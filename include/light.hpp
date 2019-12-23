#pragma once

#include "../libs/glimac/include/glm.hpp"
#include "../libs/glimac/include/Program.hpp"
#include "../libs/glimac/include/FilePath.hpp"
#include "../libs/glimac/include/SDLWindowManager.hpp"
#include "../libs/glimac/include/FilePath.hpp"
#include "../libs/glimac/include/common.hpp"
#include <vector>
#include <string>
#include <iostream>
#include <cmath>
#include <GL/glew.h>

class Light {
    private:
        //concrete value to illumate the scene
        glm::vec3 l_Kd;
        glm::vec3 l_Ks;
        float l_Shininess;
        glm::vec3 l_LightDir;
        glm::vec3 l_LightIntensity;

        //Link to shader
        GLuint l_uKd;
        GLuint l_uKs;
        GLuint l_uShininess;
        GLuint l_uLightDir_vs;
        GLuint l_uLightIntensity;

    public:
        //constructor 
        Light(const Light&) = default;
        Light(glm::vec3 Kd, glm::vec3 Ks, float Shininess, glm::vec3 LightDir, glm::vec3 LightIntensity);
        //To move the cube in the space
        void moveLeft(float delta);
        void moveUp(float delta);
        void moveDepth(float delta);
        //Apply light on the elements of the scene
        void lightInitUniVariable(glimac::Program sceneProgram);
        void lightApplication(glm::mat4 ViewMatrix);
        ~Light();

};