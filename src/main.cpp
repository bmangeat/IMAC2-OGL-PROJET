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

#include "../include/imakerProgram.hpp"
#include "../include/forme3D.hpp"
#include "../include/cube.hpp"
#include "../include/light.hpp"
#include "../include/cursor.hpp"
#include "../include/Grid.hpp"
#include "../include/Save.hpp"


using namespace glimac;
using namespace glm;
using namespace std;


int main(int argc, char **argv) {
    // Initialize SDL and open a window
    SDLWindowManager windowManager(800, 600, "WorldIMaker");

    // Initialize glew for OpenGL3+ support
    GLenum glewInitError = glewInit();
    if (GLEW_OK != glewInitError) {
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
    DirLightProgram dirLightProgram(applicationPath);
    PointLightProgram pointLightProgram(applicationPath);


    Light Light;



    cout << "OpenGL Version : " << glGetString(GL_VERSION) << endl;
    cout << "GLEW Version : " << glewGetString(GLEW_VERSION) << endl;

    /*********************************
     * HERE SHOULD COME THE INITIALIZATION CODE
     *********************************/

    //definition locations variables uniformes
    

    //Creation Grid
    Grid worldGrid;

    Save save;

    worldGrid.AddCube(vec3(0, 0, 0), vec3(0.1, 0.2, 0.4));
    worldGrid.AddCube(vec3(-2, 0, 0), vec3(0.8, 0.4, 0.7));
    worldGrid.AddCube(vec3(2, 0, 0), vec3(0.7, 0.9, 0.3));
    worldGrid.AddCube(vec3(0, 2, 0), vec3(0.4, 0.8, 0.5));

    // RBF Générator
    Interpolation RBF(3);

    //Creation Cursor
    Cursor worldCursor;
    
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
                            worldCursor.selectCase();
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
                        if (e.key.keysym.sym == SDLK_z) {
                            worldCursor.moveUp(1.f);
                        }
                        if (e.key.keysym.sym == SDLK_s) {
                            worldCursor.moveUp(-1.f);
                        }
                        if (e.key.keysym.sym == SDLK_q) {
                            worldCursor.moveLeft(-1.f);
                        }
                        if (e.key.keysym.sym == SDLK_d) {
                            worldCursor.moveLeft(1.f);
                        }
                        if (e.key.keysym.sym == SDLK_e) {
                            worldCursor.moveDepth(-1.f);
                        }
                        if (e.key.keysym.sym == SDLK_a) {
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
                        // cout <<"position curseur " << worldCursor.getCenter() << endl;


                        //Tool to create and delete a cube
                        if (e.key.keysym.sym == SDLK_SPACE) {
                            if (worldCursor.getSelect() == true) {
                                if (worldGrid.getIndexCube(worldCursor.getCenter()) == 0)
                                    worldGrid.AddCube(worldCursor.getCenter(),attribColor);
                                else
                                {
                                    worldGrid.deleteCube(worldCursor.getCenter());
                                }
                            }
                        }

                        if (e.key.keysym.sym == SDLK_w) {
                            if (worldCursor.getSelect() == true) 
                                worldGrid.extrudCube(worldCursor.getCenter(),attribColor);
                        }
                        if (e.key.keysym.sym == SDLK_x) {
                            if (worldCursor.getSelect() == true)
                                if (worldGrid.getIndexCube(worldCursor.getCenter()) != 0)
                                    worldGrid.digCube(worldCursor.getCenter());
                        }

                        if (e.key.keysym.sym == SDLK_l) {
                            Light.changemodeLight();
                            cout << " modelight = " << Light.getmodeLight() << endl;
                        }
                    break;

                }
            }

        /*********************************
         * HERE SHOULD COME THE RENDERING CODE
         *********************************/
        //Clear the window
        //imGuiInterface.CreateInterface(windowManager.window);
        //imGuiInterface.DrawInterface(windowManager.window, worldCursor, worldGrid, attribColor, save);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glClearColor(0.2,0.2,0.2,0.5);
        //imGuiInterface.RenderInterface();


        MVMatrix = camera.getViewMatrix();


        if (Light.getmodeLight() == 0) 
        {
            DrawAllCube(worldGrid.getVectorCube(), MVMatrix, ProjMatrix, camera.getViewMatrix(), SceneProgram.m_Program);
        }
        if (Light.getmodeLight() == 1)
        {
            dirLightProgram.m_Program.use();
            Light.lightInitUniVariable(dirLightProgram.m_Program,ViewMatrix);
            DrawAllCube(worldGrid.getVectorCube(), MVMatrix, ProjMatrix, camera.getViewMatrix(), dirLightProgram.m_Program);
        }
        if (Light.getmodeLight() == 2)
        {
            pointLightProgram.m_Program.use();
            Light.lightInitUniVariable(pointLightProgram.m_Program,ViewMatrix);
            DrawAllCube(worldGrid.getVectorCube(), MVMatrix, ProjMatrix, camera.getViewMatrix(), pointLightProgram.m_Program);
        }
        //worldCursor.CursorProgram.use();
        worldCursor.actualizeVertex();
        worldCursor.draw( MVMatrix, ProjMatrix, CursorProgram.m_Program);
        
        // Update the display
        windowManager.swapBuffers();
    }
    worldCursor.deleteBuffer();

    return EXIT_SUCCESS;
}
