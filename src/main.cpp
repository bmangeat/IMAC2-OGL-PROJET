#include <../libs/glimac/include/SDLWindowManager.hpp>
#include <GL/glew.h>
#include <iostream>
#include <../libs/glimac/include/Program.hpp>
#include <../libs/glimac/include/FilePath.hpp>
#include "../libs/glimac/include/glm.hpp"
#include "../libs/glimac/include/common.hpp"
#include "../libs/glimac/include/Image.hpp"
#include <vector>
#include "../include/TrackballCamera.hpp"
#include "../include/Interface.hpp"

#include "../include/cube.hpp"

#include "../include/Interpolation.h"
#include <Eigen/Dense>


#include "../include/light.hpp"
#include "../include/cursor.hpp"
#include "../include/Grid.hpp"

using namespace glimac;
using namespace glm;
using namespace std;

struct SceneProgram {
    Program m_Program;

    GLint uMVPMatrix;
    GLint uMVMatrix;
    GLint uNormalMatrix;

    SceneProgram(const FilePath& applicationPath):
        m_Program(loadProgram(applicationPath.dirPath() + "../assets/shaders/3D.vs.glsl",
                              applicationPath.dirPath() + "../assets/shaders/lightShader/cubeLighted.fs.glsl")) {
        uMVPMatrix = glGetUniformLocation(m_Program.getGLId(), "uMVPMatrix");
        uMVMatrix = glGetUniformLocation(m_Program.getGLId(), "uMVMatrix");
        uNormalMatrix = glGetUniformLocation(m_Program.getGLId(), "uNormalMatrix");
    }
};

struct CursorProgram {
    Program m_Program;

    GLint uMVPMatrix;
    GLint uMVMatrix;
    GLint uNormalMatrix;

    CursorProgram(const FilePath& applicationPath):
        m_Program(loadProgram(applicationPath.dirPath() + "../assets/shaders/3D.vs.glsl",
                              applicationPath.dirPath() + "../assets/shaders/cursorShader/cursorEdges.fs.glsl")) {
        uMVPMatrix = glGetUniformLocation(m_Program.getGLId(), "uMVPMatrix");
        uMVMatrix = glGetUniformLocation(m_Program.getGLId(), "uMVMatrix");
        uNormalMatrix = glGetUniformLocation(m_Program.getGLId(), "uNormalMatrix");
    }
};

int main(int argc, char** argv) {
    // Initialize SDL and open a window
    SDLWindowManager windowManager(800, 600, "GLImac");

    // Initialize glew for OpenGL3+ support
    GLenum glewInitError = glewInit();
    if(GLEW_OK != glewInitError) {
        cerr << glewGetErrorString(glewInitError) << endl;
        return EXIT_FAILURE;
    }

    //Creation TrackballCamera
    TrackballCamera camera = TrackballCamera();


    // Declaration of ImGui Interface
    //Interface imGuiInterface(windowManager.window, &windowManager.openglContext);


    //Loading shaders
    FilePath applicationPath(argv[0]);
    SceneProgram SceneProgram(applicationPath);
    CursorProgram CursorProgram(applicationPath);

    // Test light
    vec3 Kd = vec3(linearRand (0.0,1.0),linearRand (0.0,1.0),linearRand (0.0,1.0));
    vec3 Ks = vec3(linearRand (0.0,1.0),linearRand (0.0,1.0),linearRand (0.0,1.0));
    float Shininess = linearRand (0.0,10.0);
    vec3 LightDir= vec3(1.0,1.0,1.0);
    vec3 LightIntensity = vec3(0.50,0.50,0.50);
    Light testLight(Kd, Ks, Shininess, LightDir, LightIntensity);

    cout << "OpenGL Version : " << glGetString(GL_VERSION) << endl;
    cout << "GLEW Version : " << glewGetString(GLEW_VERSION) << endl;

    /*********************************
     * HERE SHOULD COME THE INITIALIZATION CODE
     *********************************/

    //definition locations variables uniformes
    testLight.lightInitUniVariable(SceneProgram.m_Program);

    //Creation Grid
    Grid worldGrid;



    worldGrid.AddCube(vec3(0,0,0), vec3(0.1,0.2,0.4));
    worldGrid.AddCube(vec3(-2,0,0), vec3(0.8,0.4,0.7));
    worldGrid.AddCube(vec3(2,0,0),vec3(0.7,0.9,0.3));
    worldGrid.AddCube(vec3(0,2,0), vec3(0.4,0.8,0.5));

    // RBF Générator
 /*   Interpolation RBF(3);
    RBF.generateCubes(worldGrid);
*/

    //Creation Cursor
    Cursor worldCursor(applicationPath);



    
    // GPU checks depth
    glEnable(GL_DEPTH_TEST);

    mat4 ProjMatrix = perspective(radians(70.f),800.f/600.f,0.1f, 100.f);

    mat4 MVMatrix = camera.getViewMatrix();

    mat4 NormalMatrix = transpose(inverse(MVMatrix));

    mat4 ViewMatrix = camera.getViewMatrix();

    int mouseX, mouseY;
    bool mouseScrollDown;
    bool mouseLeftDown;
    glm::vec3 attribColor;

    // Application loop:
    bool done = false;
    while(!done) {
        // Event loop:
        SDL_Event e;
            while(windowManager.pollEvent(e)) {

                switch(e.type) {

                    case SDL_QUIT:
                        done = true; // Leave the loop after this iteration
                        break;
                
                    /* Clic souris */
                    case SDL_MOUSEBUTTONDOWN:
                        mouseY = e.button.y;
                        mouseX = e.button.x;
                        if (e.button.button == SDL_BUTTON_LEFT)
                            mouseLeftDown = true;
                        if ( e.button.button == SDL_BUTTON_MIDDLE)
                            mouseScrollDown = true;
                        if ( e.button.button == SDL_BUTTON_RIGHT) {
                            worldCursor.selectCase(CursorProgram.m_Program);
                        }
                        break;
                    
                    case SDL_MOUSEBUTTONUP:
                        mouseLeftDown = false;
                        mouseScrollDown = false;
                        break;
                
                    case SDL_MOUSEMOTION:
                        if (mouseLeftDown) {
                            camera.moveLeft(e.motion.xrel);
                            camera.moveUp(e.motion.yrel);
                        }                
                        if (mouseScrollDown) {
                            camera.rotateUp(e.motion.yrel);
                            camera.rotateLeft(e.motion.xrel);
                        }
                        break;

                    case SDL_MOUSEWHEEL:
                    
                        if(e.wheel.y > 0) // scroll up
                        {
                            camera.moveFront(5.f);
                        }
                        else if(e.wheel.y < 0) // scroll down
                        {
                            camera.moveFront(-5.f);
                        }
                    break;

                    case SDL_KEYDOWN:
                        //Cursor moves
                        if (e.key.keysym.sym == SDLK_a) {
                            worldCursor.moveUp(1.f);
                        }
                        if (e.key.keysym.sym == SDLK_e) {
                            worldCursor.moveUp(-1.f);
                        }
                        if (e.key.keysym.sym == SDLK_q) {
                            worldCursor.moveLeft(-1.f);
                        }
                        if (e.key.keysym.sym == SDLK_d) {
                            worldCursor.moveLeft(1.f);
                        }
                        if (e.key.keysym.sym == SDLK_s) {
                            worldCursor.moveDepth(-1.f);
                        }
                        if (e.key.keysym.sym == SDLK_z) {
                            worldCursor.moveDepth(1.f);
                        }
                        if (e.key.keysym.sym == SDLK_r) {
                            attribColor = worldGrid.getVectorColor()[0];
                        }
                        if (e.key.keysym.sym == SDLK_g) {
                            attribColor = worldGrid.getVectorColor()[1];
                        }
                        if (e.key.keysym.sym == SDLK_b) {
                            attribColor = worldGrid.getVectorColor()[2];
                        }


                        //Tool to create and delete a cube

                        //Select a case
                        // if (e.key.keysym.sym == SDLK_RCTRL) {
                        //     cout << "je suis là" << endl;
                        //     worldCursor.selectCase();
                        //     cout << "je suis là" << endl;
                        // }
                        if (e.key.keysym.sym == SDLK_SPACE) {
                            if (worldCursor.getSelect() == 1) {
                                worldGrid.AddCube(worldCursor.getCursorPosition(),attribColor);
                            }
                            cout << "je suis là" << endl;
                        }

                        

                    break;

                }
            }

        /*********************************
         * HERE SHOULD COME THE RENDERING CODE
         *********************************/

        //Clear the window
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        MVMatrix = camera.getViewMatrix();
        testLight.lightApplication(ViewMatrix);
        SceneProgram.m_Program.use();
        //worldCursor.CursorProgram.use();
        CursorProgram.m_Program.use();
        worldCursor.actualizeVertex();
        worldCursor.drawCursor( MVMatrix, ProjMatrix, CursorProgram.m_Program);

        SceneProgram.m_Program.use();
        DrawAllCube(worldGrid.getVectorCube(), MVMatrix, ProjMatrix, camera.getViewMatrix(), SceneProgram.m_Program);

        //imGuiInterface.CreateInterface(windowManager.window);
        //imGuiInterface.DrawInterface(windowManager.window, worldCursor, worldGrid, attribColor);
        //imGuiInterface.RenderInterface();
        // Update the display
        windowManager.swapBuffers();
    }
    
    return EXIT_SUCCESS;
}
