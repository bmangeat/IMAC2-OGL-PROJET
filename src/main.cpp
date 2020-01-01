#include <glimac/include/SDLWindowManager.hpp>
#include <GL/glew.h>
#include <iostream>
#include <glimac/include/Program.hpp>
#include <glimac/include/FilePath.hpp>
#include <glimac/include/glm.hpp>
#include <glimac/include/common.hpp>
#include <glimac/include/Image.hpp>
#include <vector>
#include "../include/TrackballCamera.hpp"

#include <imgui/include/imgui.h>
#include <imgui/include/imgui_impl_opengl3.h>
#include <imgui/include/imgui_impl_sdl.h>



#include "../include/cube.hpp"
#include "../include/Interface.h"
#include "../include/light.hpp"


using namespace glimac;
using namespace glm;
using namespace std;

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
    
    // Test light
    vec3 Kd = vec3(linearRand (0.0,1.0),linearRand (0.0,1.0),linearRand (0.0,1.0));
    vec3 Ks = vec3(linearRand (0.0,1.0),linearRand (0.0,1.0),linearRand (0.0,1.0));
    float Shininess = linearRand (0.0,1.0);
    vec3 LightDir= vec3(5.0,10.0,-5.0);
    vec3 LightIntensity = vec3(1.0,1.0,1.0);
    Light testLight(Kd, Ks, Shininess, LightDir, LightIntensity);

    //Loading shaders
    FilePath applicationPath(argv[0]);

    //Declaration d'un vecteur de cube
    vector<Cube> Layer;

    //déclaration de 2 cubes

    //Pb du push back
    CubeLayer(Layer,applicationPath);

    //init program
    //Layer[0].setCubeProgram(applicationPath);
    
    
    cout << "OpenGL Version : " << glGetString(GL_VERSION) << endl;
    cout << "GLEW Version : " << glewGetString(GLEW_VERSION) << endl;

    /*********************************
     * HERE SHOULD COME THE INITIALIZATION CODE
     *********************************/


    // Interface Imgui implemented
    Interface imGuiInterface(windowManager.window, &windowManager.openglContext);

    //definition locations variables uniformes
    GLint uMVPMatrix = glGetUniformLocation(Layer[0].CubeProgram.getGLId(), "uMVPMatrix");
    GLint uMVMatrix = glGetUniformLocation(Layer[0].CubeProgram.getGLId(), "uMVMatrix");
    GLint uNormalMatrix = glGetUniformLocation(Layer[0].CubeProgram.getGLId(), "uNormalMatrix");
    testLight.lightInitUniVariable(Layer[0].CubeProgram);

    
    // GPU checks depth
    glEnable(GL_DEPTH_TEST);

    mat4 ProjMatrix = perspective(radians(70.f),800.f/600.f,0.1f, 100.f);

    mat4 MVMatrix = camera.getViewMatrix();

    mat4 NormalMatrix = transpose(inverse(MVMatrix));

    int mouseX, mouseY;
    bool mouseDown;

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
                    mouseDown = true;
                    break;
                
                case SDL_MOUSEBUTTONUP:
                    mouseDown = false;
                    break;
            
                case SDL_MOUSEMOTION:                
                    if (mouseDown) {
                        camera.rotateUp(e.motion.yrel);
                        camera.rotateLeft(e.motion.xrel);
                    }
                    break;

                case SDL_KEYDOWN:
                    if (e.key.keysym.sym == SDLK_z) {
                        camera.moveFront(5.f);
                    }
                    if (e.key.keysym.sym == SDLK_s) {
                        camera.moveFront(-5.f);
                    }
                    if (e.key.keysym.sym == SDLK_q) {
                        camera.moveLeft(-1.f);
                    }
                    if (e.key.keysym.sym == SDLK_d) {
                        camera.moveLeft(1.f);
                    }

                    // To deplace
                    if (e.key.keysym.sym == SDLK_g) {
                        Layer[0].moveUp(1.f);
                    }
                    if (e.key.keysym.sym == SDLK_b) {
                        Layer[0].moveUp(-1.f);
                        
                    }
                    if (e.key.keysym.sym == SDLK_v) {
                        Layer[0].moveLeft(-1.f);
                    }
                    if (e.key.keysym.sym == SDLK_n) {
                        Layer[0].moveLeft(1.f);
                    }
                    if (e.key.keysym.sym == SDLK_f) {
                        Layer[0].moveDepth(-1.f);
                    }
                    if (e.key.keysym.sym == SDLK_h) {
                        Layer[0].moveDepth(1.f);
                    }
                    break;

                case SDL_KEYUP:
                    //cout << "touche levée (code = "<< e.key.keysym.sym << ")" << endl;
                    break;
            }
        }

        /*********************************
         * HERE SHOULD COME THE RENDERING CODE
         *********************************/

        //Clear the window
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        MVMatrix = camera.getViewMatrix();
        // testLight.lightApplication(camera.getViewMatrix());
        //Lié aux pb de push back
        firstLayerDraw(Layer, MVMatrix, ProjMatrix, testLight, camera.getViewMatrix());

        imGuiInterface.CreateInterface(windowManager.window);
        imGuiInterface.DrawInterface();
        imGuiInterface.RenderInterface();


        // Update the display
        windowManager.swapBuffers();



    }

    return EXIT_SUCCESS;
}
