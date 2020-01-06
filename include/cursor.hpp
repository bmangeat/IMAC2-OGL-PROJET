#pragma once

#include "../libs/glimac/include/glm.hpp"
#include "../libs/glimac/include/common.hpp"
#include "../libs/glimac/include/Program.hpp"
#include <../libs/glimac/include/SDLWindowManager.hpp>
#include "./forme3D.hpp"
#include <GL/glew.h>
#include <vector>
#include <iostream>


class Cursor : public forme3D
{
    private:
        bool cursorDisplay = true;
        bool select =  false;
        glm::vec3 noSelectedColor;
        GLuint uSelect;

    public:
        Cursor(const Cursor&) = default; 
        Cursor();

        //Redefinition of motherClass
        void setVertices();

        const glm::vec3 &getCursorPosition();

        //To check the state of bool select
        const int &getSelect();
        
        //To modify bool cursorDisplay
        void changeDisplay();
        
        //To display the cursor on the screen
        //const void displayCursor();

        //To draw the cursor, function used in displayCursro()
        void draw(glm::mat4 MVMatrix, glm::mat4 ProjMatrix, glimac::Program curProg) ;
        
        //Modify the status of the attribute "select"
        void selectCase(glimac::Program m_Program);

        ~Cursor() {} ;
};
