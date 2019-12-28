#pragma once

#include "../libs/glimac/include/glm.hpp"
#include "../libs/glimac/include/common.hpp"
#include "../libs/glimac/include/Program.hpp"
#include <GL/glew.h>
#include <vector>
#include "./cube.hpp"

class Cursor {
    private:
        glm::vec3 c_position;
        std::vector<glimac::ShapeVertex> c_vertices;
        GLuint vao;
        GLuint vbo;
        GLuint ibo;
        bool select;

    public:
        glimac::Program CursorProgram;
        Cursor();
        void setCursorProgram();
        void DrawCursor();
        void selectCase();
        void selectCube();
        void deleteCube();
        void AddCube()
        ~Cursor();
}