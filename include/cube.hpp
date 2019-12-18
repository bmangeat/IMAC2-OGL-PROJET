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
        Cube(const Cube&);
	    Cube& operator =(const Cube&);

        Cube(std::vector<glm::vec3> tmp_vertices);
        void actualizeVertex();
        void setCubeProgram(glimac::FilePath applicationPath);
        glimac::Program getCubeProgram();
        void drawCube();
        void deleteBuffer();
        void moveLeft(float delta);
        void moveUp(float delta);
        void moveDepth(float delta);
        ~Cube();

        bool getSelect();
        void changeSelect();
};

    void firstLayer(std::vector<Cube> Layer);