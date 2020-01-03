#include <GL/glew.h>
#include "../libs/glimac/include/glm.hpp"
#include "../libs/glimac/include/Program.hpp"
#include "../libs/glimac/include/FilePath.hpp"
#include <../libs/glimac/include/SDLWindowManager.hpp>

class TrackballCamera 
{
    private:
        float m_fDistance; //distance from the center of the scene
        float m_sDistance; //To move on the honrizontal axis
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

        TrackballCamera();

        float get_fDistance();
        
        float get_fAgnleX();

        float get_fAgnleY();

        void moveFront(float delta);

        void moveLeft(float delta);

        void rotateLeft(float degrees);
        
        void rotateUp(float degrees);

        glm::mat4 getViewMatrix() const;

        ~TrackballCamera();

};

void manageView(TrackballCamera camera, SDL_Event e);