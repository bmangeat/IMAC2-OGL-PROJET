#include "../include/light.hpp"

    Light::Light(
      glm::vec3 Kd,
      glm::vec3 Ks,
      float Shininess,
      glm::vec3 LightDir,
      glm::vec3 LightIntensity) :
    //set up the initial parameter of the light
      l_Kd(Kd),
      l_Ks(Ks),
      l_Shininess(Shininess),
      l_LightDir(LightDir),
      l_LightIntensity(LightIntensity) 

      {
      }

    void Light::moveUp(float delta) {
        this->l_LightDir.x += delta;
    }

    void Light::moveLeft(float delta) {
        this->l_LightDir.z += delta;
    }

    void Light::moveDepth(float delta) {
        this->l_LightDir.y += delta;
    }

    void Light::lightInitUniVariable(glimac::Program m_Program) {
        m_Program.use();
        this->l_uKd = glGetUniformLocation(m_Program.getGLId(), "uKd");
        this->l_uKs = glGetUniformLocation(m_Program.getGLId(), "uKs");
        this->l_uShininess = glGetUniformLocation(m_Program.getGLId(), "uShininess");
        this->l_uLightDir_vs = glGetUniformLocation(m_Program.getGLId(), "uLightDir_vs");
        this->l_uLightIntensity = glGetUniformLocation(m_Program.getGLId(), "uLightIntensity");
    }
    
    void Light::lightApplication(glm::mat4 ViewMatrix) {
            glUniform3fv(this->l_uKd, 1, glm::value_ptr(this->l_Kd));
            glUniform3fv(this->l_uKs, 1, glm::value_ptr(this->l_Ks));
            glUniform1f(this->l_uShininess, this->l_Shininess);
            glUniform3fv(this->l_uLightDir_vs, 1, glm::value_ptr(glm::mat3(ViewMatrix)*this->l_LightDir));
            glUniform3fv(this->l_uLightIntensity, 1, glm::value_ptr(this->l_LightIntensity));         
    }

    Light::~Light() {};

