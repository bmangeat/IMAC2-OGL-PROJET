#pragma once

#include "../libs/glimac/include/glm.hpp"
#include "../libs/glimac/include/Program.hpp"
#include "../libs/glimac/include/FilePath.hpp"
#include "../libs/glimac/include/common.hpp"
#include <iostream>
#include <vector>
#include <GL/glew.h>
#include "./forme3D.hpp"

class Cube : public forme3D
{
    private:
        //Pour la future texture si on y arrive

    public:
        //constructor 
        Cube(const Cube&) = default;

        Cube(glm::vec3 cursorPos, glm::vec3 color);
        
        //Redefinition
        void draw();
        
        //Destructor
        ~Cube() {};
};

    //Draw all existing cubes stocked in the attribute stockCube of Grid Class
    const void DrawAllCube(std::vector<Cube> &stockCube, glm::mat4 MVMatrix, glm::mat4 ProjMatrix, glm::mat4 ViewMatrix, glimac::Program &m_Program);