#include "../include/light.hpp"

void Light::lightInitUniVariable(glimac::Program &m_Program, glm::mat4 ViewMatrix)
{
    m_Program.use();
    GLint uKd = glGetUniformLocation(m_Program.getGLId(), "uKd");
    GLint uKs = glGetUniformLocation(m_Program.getGLId(), "uKs");
    GLint uShininess = glGetUniformLocation(m_Program.getGLId(), "uShininess");
    GLint uLightDir_vs = glGetUniformLocation(m_Program.getGLId(), "uLightDir_vs");
    GLint uLightIntensity = glGetUniformLocation(m_Program.getGLId(), "uLightIntensity");
    glUniform3fv(uKd, 1, glm::value_ptr(this->l_Kd));
    glUniform3fv(uKs, 1, glm::value_ptr(this->l_Ks));
    glUniform1f(uShininess, this->l_Shininess);
    glUniform3fv(uLightDir_vs, 1, glm::value_ptr(glm::mat3(ViewMatrix) * this->l_LightDir));
    glUniform3fv(uLightIntensity, 1, glm::value_ptr(this->l_LightIntensity));
}

const int &Light::getmodeLight()
{
    return modeLight;
}

void Light::changemodeLight()
{
    if (modeLight == 0)
        this->modeLight = 1;
    else if (modeLight == 1)
        this->modeLight = 2;
    else if (modeLight == 2)
        this->modeLight = 0;
}


