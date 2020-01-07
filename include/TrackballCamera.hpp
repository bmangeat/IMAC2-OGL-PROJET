#include <GL/glew.h>
#include "../libs/glimac/include/glm.hpp"
#include "../libs/glimac/include/Program.hpp"
#include "../libs/glimac/include/FilePath.hpp"
#include <../libs/glimac/include/SDLWindowManager.hpp>

class TrackballCamera {
private:
    float m_fDistance; //distance from the center of the scene
    float m_sDistance; //To move on the honrizontal axis
    float m_uDistance; //To move on the vertical axis
    float m_fAngleX; // Angle around the xAxis (rotation up/down)
    float m_fAngleY; // Angle around the yAxis (rotation right/left)
    GLint uMVPMatrix;
    GLint uMVMatrix;
    GLint uNormalMatrix;

public:
    // TrackballCamera(float fDistance, float fAgnleX, float fAngleY) :
    //     m_fDistance(fDistance),
    //     m_fAngleX(fAgnleX),
    //     m_fAngleY(fAngleY)
    //     {};

    //! Constructor
    /*!
      \brief Initialize Camera
    */
    TrackballCamera();

    //! Getter : distance
    /*!
      \brief Get distance from the center of the scene
    */
    float get_fDistance();

    //! Getter : AngleX
    /*!
      \brief Angle around the xAxis (rotation up/down)
    */
    float get_fAgnleX();

    //! Getter : AngleY
    /*!
      \brief Angle around the yAxis (rotation right/left)
    */
    float get_fAgnleY();

    //! Get matrix for camera
    /*!
      \brief Create matrix translate/rotation which will be applied to camera
    */
    glm::mat4 getViewMatrix() const;

    //! Move Camera : z-axis
    /*!
      \brief Allow movement of the camera on z-axis - zoom in and zoom out
      \param delta Param enter thanks to keyboard or mouse's event from main
    */
    void moveFront(float delta);

    //! Move Camera : x-axis
    /*!
      \brief Allow movement of the camera on x-axis - left and right
      \param delta Param enter thanks to keyboard or mouse's event from main
    */
    void moveLeft(float delta);

    //! Move Camera : y-axis
    /*!
      \brief Allow movement of the camera on y-axis - top and bottom
      \param delta Param enter thanks to keyboard or mouse's event from main
    */
    void moveUp(float delta);

    //! Rotate Camera : x-axis
    /*!
      \brief Allow rotation of the camera on x-axis - left and right
      \param degrees Param enter thanks to keyboard or mouse's event from main
    */
    void rotateLeft(float degrees);

    //! Rotate Camera : y-axis
    /*!
      \brief Allow rotation of the camera on y-axis - top and bottom
      \param degrees Param enter thanks to keyboard or mouse's event from main
    */
    void rotateUp(float degrees);

    //! Destructor
    /*!
      \brief No more camera after this
    */
    ~TrackballCamera();

};