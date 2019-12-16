#pragma once

#include<../libs/glimac/include/glm.hpp>
#include<../libs/glimac/include/Shader.hpp>
#include<vector>


class Cube {
    private:
        glm::vec3 vertices;
        GLuint vao;
        GLuint ibo;
        glimac::Shader shader;

    public:
        Cube();
        void drawCube();
        ~Cube();

}