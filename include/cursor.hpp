#pragma once

#include "../libs/glimac/include/glm.hpp"
#include "../libs/glimac/include/common.hpp"
#include "../libs/glimac/include/Program.hpp"
#include <../libs/glimac/include/SDLWindowManager.hpp>
#include <GL/glew.h>
#include <vector>
#include <iostream>

class Cursor {
    private:
        glm::vec3 c_position = glm::vec3(0.f,0.f,0.f);
        std::vector<glimac::ShapeVertex> c_vertices;
        GLuint vao;
        GLuint vbo;
        GLuint ibo;
        bool cursorDisplay = true;
        bool select = false ;
        GLuint uSelect;

    public:
        glimac::Program CursorProgram;
        Cursor(const Cursor&) = default; 
        Cursor(glimac::FilePath applicationPath);
        void actualizeVertex();
        void setCursorProgram(glimac::FilePath applicationPath);

        const glm::vec3 getCursorPosition();

        //To move the cursor in the space
        void moveLeft(float delta);
        void moveUp(float delta);
        void moveDepth(float delta);
        
        //To modify bool cursorDisplay
        void changeDisplay();
        
        //To display the cursor on the screen
        const void displayCursor();

        //To draw the cursor, function used in displayCursro()
        void DrawCursor();
        
        //Modify the status of the attribute "select"
        void selectCase();

        ~Cursor();
};

void manageCursorPos(Cursor cursor, SDL_Event e);