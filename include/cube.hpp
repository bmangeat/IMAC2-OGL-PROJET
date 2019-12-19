#pragma once

#include "../libs/glimac/include/glm.hpp"
#include "../libs/glimac/include/Program.hpp"
#include "../libs/glimac/include/FilePath.hpp"
#include "../libs/glimac/include/common.hpp"
#include <vector>
#include <string>
#include <iostream>
#include <cmath>

class Cube {
    private:
        std::vector<glimac::ShapeVertex> vertices;
        GLuint vao;
        GLuint vbo;
        GLuint ibo;
        bool select = false;

    public:
        glimac::Program CubeProgram;

        //constructor 
         Cube(const Cube&) = default;
	    // Cube& operator =(const Cube&);

        Cube();

        //Bind Vao, Vbo & IBO Again when the vertices change
        void actualizeVertex();

        //Creation Program use to link main.cpp to the shaders
        void setCubeProgram(glimac::FilePath applicationPath);

        //public attribute --> Impossible to pass in private because of it's definition in glimac
        glimac::Program getCubeProgram();

        //Bind Vao Vbo and draw the cube
        void drawCube();

        void deleteBuffer();

        //To move the cube in the space
        void moveLeft(float delta);
        void moveUp(float delta);
        void moveDepth(float delta);
        
        //Destructor
        ~Cube();

        //Check and change the status of the selection in order to use the cursor
        bool getSelect();
        void changeSelect();
};

    void CubeLayer(std::vector<Cube> &Layer, glimac::FilePath applicationPath);
    void firstLayerDraw(std::vector<Cube> &Layer, glm::mat4 MVMatrix, glm::mat4 ProjMatrix);