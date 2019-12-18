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

#include "../include/cube.hpp"


using namespace glimac;
using namespace glm;
using namespace std;

int main(int argc, char** argv) {
    // Initialize SDL and open a window
    SDLWindowManager windowManager(800, 600, "GLImac");

    // Initialize glew for OpenGL3+ support
    GLenum glewInitError = glewInit();
    if(GLEW_OK != glewInitError) {
        std::cerr << glewGetErrorString(glewInitError) << std::endl;
        return EXIT_FAILURE;
    }

    //Creation TrackballCamera
    TrackballCamera camera = TrackballCamera();
    

    //Loading shaders
    FilePath applicationPath(argv[0]);

    //first position
        std::vector<glm::vec3> tmp_vertices = { 
            glm::vec3(-0.5f,0.5f,-0.5f),
            glm::vec3(0.5f,0.5f,-0.5f),
            glm::vec3(-0.5f,0.5f,0.5f),
            glm::vec3(0.5f,0.5f,0.5f),

            glm::vec3(-0.5f,-0.5f,-0.5f),
            glm::vec3(0.5f,-0.5f,-0.5f),
            glm::vec3(-0.5f,-0.5f,0.5f),
            glm::vec3(0.5f,-0.5f,0.5f)
        };

    //init Cube
    Cube firstCube(tmp_vertices);

    Cube secondCube(tmp_vertices);


    //init program
    firstCube.setCubeProgram(applicationPath);

    secondCube.setCubeProgram(applicationPath);
    
    
    std::cout << "OpenGL Version : " << glGetString(GL_VERSION) << std::endl;
    std::cout << "GLEW Version : " << glewGetString(GLEW_VERSION) << std::endl;

    /*********************************
     * HERE SHOULD COME THE INITIALIZATION CODE
     *********************************/

    //definition locations variables uniformes
    GLint uMVPMatrix = glGetUniformLocation(firstCube.CubeProgram.getGLId(), "uMVPMatrix");
    GLint uMVMatrix = glGetUniformLocation(firstCube.CubeProgram.getGLId(), "uMVMatrix");
    GLint uNormalMatrix = glGetUniformLocation(firstCube.CubeProgram.getGLId(), "uNormalMatrix");

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
                        firstCube.moveUp(1.f);
                    }
                    if (e.key.keysym.sym == SDLK_b) {
                        firstCube.moveUp(-1.f);
                    }
                    if (e.key.keysym.sym == SDLK_v) {
                        firstCube.moveLeft(-1.f);
                    }
                    if (e.key.keysym.sym == SDLK_n) {
                        firstCube.moveLeft(1.f);
                    }
                    if (e.key.keysym.sym == SDLK_f) {
                        firstCube.moveDepth(-1.f);
                    }
                    if (e.key.keysym.sym == SDLK_h) {
                        firstCube.moveDepth(1.f);
                    }
                    break;

                case SDL_KEYUP:
                    //std::cout << "touche levée (code = "<< e.key.keysym.sym << ")" << std::endl;
                    break;
            }
        }

        /*********************************
         * HERE SHOULD COME THE RENDERING CODE
         *********************************/

        //Clear the window
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        MVMatrix = camera.getViewMatrix();

        //MVMatrix = rotate(MVMatrix, windowManager.getTime(), vec3(0, 1, 0));
        glUniformMatrix4fv(uMVMatrix, 1, GL_FALSE, value_ptr(MVMatrix));
        glUniformMatrix4fv(uNormalMatrix, 1, GL_FALSE, value_ptr(transpose(inverse(MVMatrix))));
        glUniformMatrix4fv(uMVPMatrix, 1, GL_FALSE, value_ptr(ProjMatrix * MVMatrix));

        firstCube.actualizeVertex();
        firstCube.drawCube();
        secondCube.drawCube();
        

        // Update the display
        windowManager.swapBuffers();
    }
    
    firstCube.deleteBuffer();
    
    return EXIT_SUCCESS;
}
