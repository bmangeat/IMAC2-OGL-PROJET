#include "../include/cube.hpp"

    Cube::Cube(glimac::FilePath applicationPath) {

        //Set vertices coordinates
        std::vector<glm::vec3> tmp_vertices = { 
            glm::vec3(-0.5f,0.5f,-0.5f),
            glm::vec3(0.5f,0.5f,-0.5f),
            glm::vec3(-0.5f,0.5f,0.5f),
            glm::vec3(0.5f,0.5f,0.5f),

            glm::vec3(-0.5f,-0.5f,-0.5f),
            glm::vec3(0.5f,-0.5f,-0.5f),
            glm::vec3(-0.5f,-0.5f,0.5f),
            glm::vec3(0.5f,-0.5f,0.5f)
        };

        for(size_t j = 0; j < 8; ++j) {
            glimac::ShapeVertex vertex;
            
            if (j==0) {
                vertex.texCoords.x = 0;
                vertex.texCoords.y = 1;
            }
            else {
                vertex.texCoords.x += 1/8;
                vertex.texCoords.y -= 1/8;
                std::cout << "coucou" << std::endl;
            }

            vertex.normal.x = tmp_vertices[j].x;
            vertex.normal.y = tmp_vertices[j].y;
            vertex.normal.z = tmp_vertices[j].z;
            
            vertex.position = vertex.normal;
            
            this->vertices.push_back(vertex);
        }

        //this->vbo creation
        glGenBuffers(1, &this->vbo);

        //Binding this->vbo
        glBindBuffer(GL_ARRAY_BUFFER, this->vbo);

        glBufferData(GL_ARRAY_BUFFER, (this->vertices.size()+1) * sizeof(glimac::ShapeVertex), this->vertices.data(), GL_STATIC_DRAW);

        //débinder
        glBindBuffer(GL_ARRAY_BUFFER,0);

        //IBO Creation
        glGenBuffers(1, &this->ibo);

        //biding ibo
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->ibo);

        //Tableau d'indices
        std::vector<uint32_t> index = {
            0,1,2,
            1,2,3,
            0,2,6,
            4,0,6,
            0,4,5,
            1,0,5,
            1,3,5,
            3,5,7,
            2,3,6,
            3,6,7,
            4,5,6,
            5,6,7
        };


        //put index in IBO
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, (index.size()+1) * sizeof(uint32_t), index.data(), GL_STATIC_DRAW);

        //Debinding ibo
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,0);

        //this->vao creation
        glGenVertexArrays(1,&this->vao);

        //Binding this->vao
        glBindVertexArray(this->vao);

        //Save IBO in vao
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,ibo);

        //attributs activation
        const GLuint VERTEX_ATTR_POSITION = 0;
        glEnableVertexAttribArray(VERTEX_ATTR_POSITION);

        const GLuint VERTEX_ATTR_NORMAL = 1;
        glEnableVertexAttribArray(VERTEX_ATTR_NORMAL);

        const GLuint VERTEX_ATTR_TEXTURE = 2;
        glEnableVertexAttribArray(VERTEX_ATTR_TEXTURE);

        //rebinder le this->vbo
        glBindBuffer(GL_ARRAY_BUFFER,this->vbo);

        glVertexAttribPointer(VERTEX_ATTR_POSITION, 3, GL_FLOAT, GL_FALSE, sizeof(glimac::ShapeVertex), (const GLvoid*) offsetof(glimac::ShapeVertex, position));
        glVertexAttribPointer(VERTEX_ATTR_NORMAL, 3, GL_FLOAT, GL_FALSE, sizeof(glimac::ShapeVertex), (const GLvoid*) offsetof(glimac::ShapeVertex, normal));
        glVertexAttribPointer(VERTEX_ATTR_TEXTURE, 2, GL_FLOAT, GL_FALSE, sizeof(glimac::ShapeVertex), (const GLvoid*) offsetof(glimac::ShapeVertex, texCoords));

        //debind vbo
        glBindBuffer(GL_ARRAY_BUFFER,0);

        //debinder this->vao
        glBindVertexArray(0);

    };


       
    void Cube::drawCube() {
        //rebinder vao
        glBindVertexArray(vao);
        glDrawElements(GL_TRIANGLES, 12*3, GL_UNSIGNED_INT, 0);
        glBindVertexArray(0);
    };

    void Cube::deleteBuffer() {
        glDeleteBuffers(1,&this->vbo);
        glDeleteVertexArrays(1,&this->vao);
    }

    Cube::~Cube() {
        delete this;
    };