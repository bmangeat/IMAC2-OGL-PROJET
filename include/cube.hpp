#pragma once

#include "../libs/glimac/include/glm.hpp"
#include "../libs/glimac/include/Program.hpp"
#include "../libs/glimac/include/FilePath.hpp"
#include "../libs/glimac/include/common.hpp"
#include<vector>
#include<string>
#include<iostream>
#include <cmath>

class Cube {
    private:
        std::vector<glimac::ShapeVertex> vertices;
        GLuint vao;
        GLuint vbo;
        GLuint ibo;
        //std::string shader;

    public:
        Cube(glimac::FilePath applicationPath);
        void drawCube();
        void deleteBuffer();
        ~Cube();
};