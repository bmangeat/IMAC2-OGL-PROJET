#pragma once

#include "../libs/glimac/include/glm.hpp"
#include "../libs/glimac/include/Program.hpp"
#include "../libs/glimac/include/FilePath.hpp"
#include <iostream>
#include <GL/glew.h>
#include "../libs/glimac/include/Program.hpp"
#include "../libs/glimac/include/FilePath.hpp"

class Light {
    private:
        //concrete value to illumate the scene
        glm::vec3 l_Kd = glm::vec3(0.1,0.1,0.1);
        glm::vec3 l_Ks = glm::vec3(0.1,0.2,0.3);
        float l_Shininess = 0.1;
        glm::vec3 l_LightDir= glm::vec3(1.0,10.0,1.0);
        glm::vec3 l_LightIntensity = glm::vec3(0.50,0.50,0.50);
        int modeLight =0;
        
    public:
        //constructor 
        Light(const Light&) = default;
        Light() {};
        const int &getmodeLight();
        void changemodeLight();
        //Apply light on the elements of the scene
        void lightInitUniVariable(glimac::Program &m_Program, glm::mat4 ViewMatrix);
        ~Light() {} ;

};