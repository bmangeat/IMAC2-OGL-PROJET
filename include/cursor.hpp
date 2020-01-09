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
        glm::vec3 c_position;
        bool cursorDisplay = true;
        bool select =  false;
        glm::vec3 noSelectedColor;

    public:
        Cursor(const Cursor&) = default; 
        Cursor();

        //Redefinition of motherClass
        void setVertices();

        //To check the state of bool select
        const bool &getSelect();
        
        //To modify bool cursorDisplay
        void changeDisplay();
        
        //To draw the cursor, function used in displayCursro()
        void draw(glm::mat4 MVMatrix, glm::mat4 ProjMatrix, glimac::Program &curProg) ;
        
        //Modify the status of the attribute "select"
        void selectCase();

        ~Cursor() {} ;
};
