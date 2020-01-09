#pragma once

#include <GL/glew.h>
#include "../libs/glimac/include/glm.hpp"
#include "../libs/glimac/include/common.hpp"
#include <vector>
#include <iostream>



class forme3D {
    private :
        glm::vec3 f_center;
        GLuint f_vao;
        GLuint f_vbo;
        GLuint f_ibo;
        glm::vec3 f_color;
        
    protected :
        std::vector<uint32_t> f_index;
        std::vector<glimac::ShapeVertex> f_vertices;

    public :
        //constructor
        forme3D(const forme3D&) = default;

        forme3D() {};
        const glm::vec3 &getCenter();
        const glm::vec3 &getColor();
        void initializeBuffers();
        void actualizeVertex();
        void setCenter(glm::vec3 position);
        void setVertices();
        void setColor(glm::vec3 color);

        void bindVaoIbo();

        //To move all point in the 3Dspace
        void moveLeft(float delta);
        void moveUp(float delta);
        void moveDepth(float delta);

        //Abstract function to draw the 3D forme
        virtual void draw() {};

        //DeleteBuffer
        void deleteBuffer();

        //Destructor
        virtual ~forme3D() {};

};