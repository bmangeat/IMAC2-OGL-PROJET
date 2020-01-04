#include "../include/TrackballCamera.hpp"

    TrackballCamera::TrackballCamera() : 
        m_fDistance(5.f),
        m_sDistance(0.f),
        m_uDistance(0.f),
        m_fAngleX(0.f),
        m_fAngleY(0.f){};

    float TrackballCamera::get_fDistance()
    {
        return this->m_fDistance;
    }

    float TrackballCamera::get_fAgnleX()
    {
        return this->m_fAngleX;
    }

    float TrackballCamera::get_fAgnleY()
    {
        return this->m_fAngleY;
    }

    void TrackballCamera::moveFront(float delta)
    {
        this->m_fDistance += -delta;
    }

    void TrackballCamera::moveLeft(float delta)
    {
        this->m_sDistance += -delta;
    }

    void TrackballCamera::moveUp(float delta) {
        this->m_uDistance += -delta;
    }

    void TrackballCamera::rotateLeft(float degrees)
    {
        this->m_fAngleY += degrees;
    }

    void TrackballCamera::rotateUp(float degrees)
    {
        this->m_fAngleX += degrees;
    }

    glm::mat4 TrackballCamera::getViewMatrix() const
    {
        glm::mat4 ViewMatrix; // Build normally a Id Matrix...
        ViewMatrix = glm::translate(ViewMatrix, glm::vec3(-this->m_sDistance, this->m_uDistance, -this->m_fDistance));
        ViewMatrix = glm::rotate(ViewMatrix, glm::radians(this->m_fAngleX), glm::vec3(1.f, 0.f, 0.f));
        ViewMatrix = glm::rotate(ViewMatrix, glm::radians(this->m_fAngleY), glm::vec3(0.f, 1.f, 0.f));
        return ViewMatrix;
    }

    TrackballCamera::~TrackballCamera() {}