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
#include "../include/light.hpp"
#include "../include/cursor.hpp"
#include "../include/Grid.hpp"


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
        Program tmp_program = loadProgram(applicationPath.dirPath() + "../assets/shaders/3D.vs.glsl",
                                        applicationPath.dirPath() + "../assets/shaders/lightShader/cubeLighted.fs.glsl");
        tmp_program.use();

    
    
    cout << "OpenGL Version : " << glGetString(GL_VERSION) << endl;
    cout << "GLEW Version : " << glewGetString(GLEW_VERSION) << endl;

    /*********************************
     * HERE SHOULD COME THE INITIALIZATION CODE
     *********************************/

    //definition locations variables uniformes
    GLint uMVPMatrix = glGetUniformLocation(tmp_program.getGLId(), "uMVPMatrix");
    GLint uMVMatrix = glGetUniformLocation(tmp_program.getGLId(), "uMVMatrix");
    GLint uNormalMatrix = glGetUniformLocation(tmp_program.getGLId(), "uNormalMatrix");
    testLight.lightInitUniVariable(tmp_program);


    //Creation Grid
    Grid worldGrid;
    
    //Creation Cursor
    Cursor worldCursor(applicationPath);
    
    // GPU checks depth
    glEnable(GL_DEPTH_TEST);

    mat4 ProjMatrix = perspective(radians(70.f),800.f/600.f,0.1f, 100.f);

    mat4 MVMatrix = camera.getViewMatrix();

    mat4 NormalMatrix = transpose(inverse(MVMatrix));

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
                }

                manageView(camera, e);
                manageCursorPos(worldCursor,e);
            }

        /*********************************
         * HERE SHOULD COME THE RENDERING CODE
         *********************************/

        //Clear the window
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        MVMatrix = camera.getViewMatrix();
        // testLight.lightApplication(camera.getViewMatrix());
        //Lié aux pb de push back
        testLight.lightApplication(camera.getViewMatrix());
        DrawAllCube(worldGrid.getVectorCube(), MVMatrix, ProjMatrix, camera.getViewMatrix());
        
        // Update the display
        windowManager.swapBuffers();
    }
    
    return EXIT_SUCCESS;
}
