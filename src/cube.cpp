#include "../include/cube.hpp"


    Cube::Cube(glm::vec3 cursorPos, glm::vec3 color)
    {
        this->setCenter(cursorPos);
        this->setColor(color);
        this->setVertices();

        //Tableau d'indices
        this->f_index = {
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

        this->initializeBuffers();
    }

       
    void Cube::draw() {
        this->bindVaoIbo();
        glDrawElements(GL_TRIANGLES, 12*3, GL_UNSIGNED_INT, 0);
        glBindVertexArray(0);
    }

    const void DrawAllCube(std::vector<Cube> &stockCube, glm::mat4 MVMatrix, glm::mat4 ProjMatrix, glm::mat4 ViewMatrix, glimac::Program &m_Program) {
        m_Program.use();
        for (int i=0; i < stockCube.size(); i++) {
            GLint uColor = glGetUniformLocation(m_Program.getGLId(), "uColor");
            GLint uMVPMatrix = glGetUniformLocation(m_Program.getGLId(), "uMVPMatrix");
            GLint uMVMatrix = glGetUniformLocation(m_Program.getGLId(), "uMVMatrix");
            GLint uNormalMatrix = glGetUniformLocation(m_Program.getGLId(), "uNormalMatrix");
            glUniform3fv(uColor, 1, glm::value_ptr(stockCube[i].getColor()));
            glUniformMatrix4fv(uMVMatrix, 1, GL_FALSE, glm::value_ptr(MVMatrix));
            glUniformMatrix4fv(uNormalMatrix, 1, GL_FALSE, glm::value_ptr(glm::transpose(glm::inverse(MVMatrix))));
            glUniformMatrix4fv(uMVPMatrix, 1, GL_FALSE, glm::value_ptr(ProjMatrix * MVMatrix));

            stockCube[i].draw();
        }
    }   