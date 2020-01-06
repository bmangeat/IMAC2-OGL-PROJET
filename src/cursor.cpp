#include "../include/cursor.hpp"

    Cursor::Cursor()
    {
        this->setCenter(glm::vec3(0,0,0));
        this->setVertices();
        this->setColor(glm::vec3(0.1,0.0,0.0));
        this->noSelectedColor = glm::vec3(1.0,0.0,0.0);

        //Tableau d'indices
        this->f_index = {
            0,1,    1,3,    3,2,    2,0,
            2,6,    6,4,    0,4,
            6,7,    7,5,    4,5,
            3,7,    1,5
        };

        this->initializeBuffers();
    }

    //Redefinition of motherClass --> Shift of the edges of the base cube
    void Cursor::setVertices()
    {
        float x = this->getCenter().x;
        float y = this->getCenter().y;
        float z = this->getCenter().z;

        //Shift of 0.05
        std::vector<glm::vec3> tmp_vertices = { 
        glm::vec3(x-0.55f, y+0.55f, z-0.55f),
        glm::vec3(x+0.55f, y+0.55f, z-0.55f),
        glm::vec3(x-0.55f, y+0.55f, z+0.55f),
        glm::vec3(x+0.55f, y+0.55f, z+0.55f),

        glm::vec3(x-0.55f, y-0.55f, z-0.55f),
        glm::vec3(x+0.55f, y-0.55f, z-0.55f),
        glm::vec3(x-0.55f, y-0.55f, z+0.55f),
        glm::vec3(x+0.55f, y-0.55f, z+0.55f)
        };

        for(size_t j = 0; j < 9; ++j) {
            glimac::ShapeVertex vertex;
            
            vertex.texCoords.x = 0;
            vertex.texCoords.y = 1;

            vertex.normal.x = tmp_vertices[j].x;
            vertex.normal.y = tmp_vertices[j].y;
            vertex.normal.z = tmp_vertices[j].z;
            
            vertex.position = vertex.normal;
            
            this->f_vertices.push_back(vertex);
        }
    }

    const bool &Cursor::getSelect() {
        return this->select;
    }


    void Cursor::draw( glm::mat4 MVMatrix, glm::mat4 ProjMatrix, glimac::Program curProg){
        curProg.use();
        if (this->cursorDisplay == true) {
            GLint uColor = glGetUniformLocation(curProg.getGLId(), "uColor");
            if (this->select == true)
                glUniform3fv(uColor,1, glm::value_ptr(this->getColor()));
            else glUniform3fv(uColor,1,glm::value_ptr(this->noSelectedColor));
            GLint uMVPMatrix = glGetUniformLocation(curProg.getGLId(), "uMVPMatrix");
            GLint uMVMatrix = glGetUniformLocation(curProg.getGLId(), "uMVMatrix");
            GLint uNormalMatrix = glGetUniformLocation(curProg.getGLId(), "uNormalMatrix");
            glUniformMatrix4fv(uMVMatrix, 1, GL_FALSE, glm::value_ptr(MVMatrix));
            glUniformMatrix4fv(uNormalMatrix, 1, GL_FALSE, glm::value_ptr(glm::transpose(glm::inverse(MVMatrix))));
            glUniformMatrix4fv(uMVPMatrix, 1, GL_FALSE, glm::value_ptr(ProjMatrix * MVMatrix));
            this->bindVaoIbo();
            glDrawElements(GL_LINES, 12*2, GL_UNSIGNED_INT, 0);
            glBindVertexArray(0);
        }
    }

    void Cursor::changeDisplay() {
        if (this->cursorDisplay == true)
            this->cursorDisplay = false;
        else this->cursorDisplay = true;
    }

    void Cursor::selectCase() {
        if (this->select == true) {
            this->select = false;
            std::cout << "false = " << this->select << std::endl;
        }
        else {
            this->select = true;
            std::cout << "true = " << this->select << std::endl;
        }
    }

