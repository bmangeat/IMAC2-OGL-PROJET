#include "../include/light.hpp"

    Light::Light(
      glm::vec3 Kd,
      glm::vec3 Ks,
      float Shininess,
      glm::vec3 LightDir,
      glm::vec3 LightIntensity) :

      l_Kd(Kd),
      l_Ks(Ks),
      l_Shininess(Shininess),
      l_LightDir(LightDir),
      l_LightIntensity(LightIntensity) 

      {}

    void Light::moveUp(float delta) {
        this->l_LightDir.x += delta;
    }

    void Light::moveLeft(float delta) {
        this->l_LightDir.z += delta;
    }

    void Light::moveDepth(float delta) {
        this->l_LightDir.y += delta;
    }

    void Light::lightApplication(glimac::Program sceneProgram) {
            this->l_uKd = glGetUniformLocation(sceneProgram.getGLId(), "uKd");
            this->l_uKs = glGetUniformLocation(sceneProgram.getGLId(), "uKs");
            this->l_uShininess = glGetUniformLocation(sceneProgram.getGLId(), "uShininess");
            this->l_uLightDir_vs = glGetUniformLocation(sceneProgram.getGLId(), "uLightDir_vs");
            this->l_uLightIntensity = glGetUniformLocation(sceneProgram.getGLId(), "uLightIntensity");            
    }

    Light::~Light() {};

