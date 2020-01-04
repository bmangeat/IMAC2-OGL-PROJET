#pragma once

#include "../libs/glimac/include/glm.hpp"
#include "../libs/glimac/include/Program.hpp"
#include "../libs/glimac/include/FilePath.hpp"
#include "../libs/glimac/include/common.hpp"
#include <vector>
#include <string>
#include <iostream>
#include <cmath>
#include <GL/glew.h>

class Cube {

    private:
        std::vector<glimac::ShapeVertex> vertices;
        //To stock the position given by the cursor when we create the cube
        glm::vec3 center;

        //To draw the Cube
        GLuint vao;
        GLuint vbo;
        GLuint ibo;

    public:
        //constructor 
        Cube(const Cube&) = default;
	    // Cube& operator =(const Cube&);

        Cube(glm::vec3 cursorPos);


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

    // void CubeLayer(std::vector<Cube> &Layer, glimac::FilePath applicationPath);
    // void firstLayerDraw(std::vector<Cube> &Layer, glm::mat4 MVMatrix, glm::mat4 ProjMatrix, Light Sun, glm::mat4 ViewMatrix);

    //Draw all existing cubes stocked in the attribute stockCube of Grid Class
    const void DrawAllCube(std::vector<Cube> &stockCube, glm::mat4 MVMatrix, glm::mat4 ProjMatrix, glm::mat4 ViewMatrix, glimac::Program m_Program);