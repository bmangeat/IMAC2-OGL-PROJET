#include "../include/forme3D.hpp"

forme3D::forme3D() {};

void forme3D::initializeBuffers()
{
    //this->f_vbo creation
    glGenBuffers(1, &this->f_vbo);

    //Binding this->f_vbo
    glBindBuffer(GL_ARRAY_BUFFER, this->f_vbo);

    glBufferData(GL_ARRAY_BUFFER, this->f_vertices.size() * sizeof(glimac::ShapeVertex), this->f_vertices.data(), GL_STATIC_DRAW);

    //débinder
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    //IBO Creation
    glGenBuffers(1, &this->f_ibo);

    //biding ibo
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->f_ibo);

    //put index in IBO
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, this->f_index.size() * sizeof(uint32_t), this->f_index.data(), GL_STATIC_DRAW);

    //Debinding ibo
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

    //this->f_vao creation
    glGenVertexArrays(1, &this->f_vao);

    //Binding this->f_vao
    glBindVertexArray(this->f_vao);

    //Save IBO in vao
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->f_ibo);

    //attributs activation
    const GLuint VERTEX_ATTR_POSITION = 0;
    glEnableVertexAttribArray(VERTEX_ATTR_POSITION);

    const GLuint VERTEX_ATTR_NORMAL = 1;
    glEnableVertexAttribArray(VERTEX_ATTR_NORMAL);

    const GLuint VERTEX_ATTR_TEXTURE = 2;
    glEnableVertexAttribArray(VERTEX_ATTR_TEXTURE);

    //rebinder le this->f_vbo
    glBindBuffer(GL_ARRAY_BUFFER, this->f_vbo);

    glVertexAttribPointer(VERTEX_ATTR_POSITION, 3, GL_FLOAT, GL_FALSE, sizeof(glimac::ShapeVertex), (const GLvoid *)offsetof(glimac::ShapeVertex, position));
    glVertexAttribPointer(VERTEX_ATTR_NORMAL, 3, GL_FLOAT, GL_FALSE, sizeof(glimac::ShapeVertex), (const GLvoid *)offsetof(glimac::ShapeVertex, normal));
    glVertexAttribPointer(VERTEX_ATTR_TEXTURE, 2, GL_FLOAT, GL_FALSE, sizeof(glimac::ShapeVertex), (const GLvoid *)offsetof(glimac::ShapeVertex, texCoords));

    //debind vbo
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    //debinder this->f_vao
    glBindVertexArray(0);
}

void forme3D::actualizeVertex()
{
    //Binding this->f_vbo
    glBindBuffer(GL_ARRAY_BUFFER, this->f_vbo);

    glBufferData(GL_ARRAY_BUFFER, this->f_vertices.size() * sizeof(glimac::ShapeVertex), this->f_vertices.data(), GL_STATIC_DRAW);

    //débinder
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    //this->f_vao creation
    glGenVertexArrays(1, &this->f_vao);

    //Binding this->f_vao
    glBindVertexArray(this->f_vao);

    //Save IBO in vao
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->f_ibo);

    //attributs activation
    const GLuint VERTEX_ATTR_POSITION = 0;
    glEnableVertexAttribArray(VERTEX_ATTR_POSITION);

    const GLuint VERTEX_ATTR_NORMAL = 1;
    glEnableVertexAttribArray(VERTEX_ATTR_NORMAL);

    const GLuint VERTEX_ATTR_TEXTURE = 2;
    glEnableVertexAttribArray(VERTEX_ATTR_TEXTURE);

    //rebinder le this->f_vbo
    glBindBuffer(GL_ARRAY_BUFFER, this->f_vbo);

    glVertexAttribPointer(VERTEX_ATTR_POSITION, 3, GL_FLOAT, GL_FALSE, sizeof(glimac::ShapeVertex), (const GLvoid *)offsetof(glimac::ShapeVertex, position));
    glVertexAttribPointer(VERTEX_ATTR_NORMAL, 3, GL_FLOAT, GL_FALSE, sizeof(glimac::ShapeVertex), (const GLvoid *)offsetof(glimac::ShapeVertex, normal));
    glVertexAttribPointer(VERTEX_ATTR_TEXTURE, 2, GL_FLOAT, GL_FALSE, sizeof(glimac::ShapeVertex), (const GLvoid *)offsetof(glimac::ShapeVertex, texCoords));

    //debind vbo
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    //debinder this->f_vao
    glBindVertexArray(0);
}

const glm::vec3 &forme3D::getCenter()
{
    return this->f_center;
}

const glm::vec3 &forme3D::getColor()
{
    return this->f_color;
}

void forme3D::setCenter(glm::vec3 position)
{
    this->f_center = position;
}

void forme3D::setVertices()
{
    //Set vertices coordinates with the position of the curosr
    float x = this->f_center.x;
    float y = this->f_center.y;
    float z = this->f_center.z;

    std::vector<glm::vec3> tmp_vertices = {
        glm::vec3(x - 0.5f, y + 0.5f, z - 0.5f),
        glm::vec3(x + 0.5f, y + 0.5f, z - 0.5f),
        glm::vec3(x - 0.5f, y + 0.5f, z + 0.5f),
        glm::vec3(x + 0.5f, y + 0.5f, z + 0.5f),

        glm::vec3(x - 0.5f, y - 0.5f, z - 0.5f),
        glm::vec3(x + 0.5f, y - 0.5f, z - 0.5f),
        glm::vec3(x - 0.5f, y - 0.5f, z + 0.5f),
        glm::vec3(x + 0.5f, y - 0.5f, z + 0.5f)};

    for (size_t j = 0; j < 8; ++j)
    {
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

void forme3D::setColor(glm::vec3 color)
{
    this->f_color = color;
}

void forme3D::bindVaoIbo()
{
    //rebind vao
    glBindVertexArray(this->f_vao);
    //biding ibo
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->f_ibo);
};

void forme3D::moveUp(float delta)
{
    for (int i = 0; i < this->f_vertices.size(); i++)
    {
        this->f_vertices[i].position.z += delta;
    }
    this->f_center.z += delta;
}

void forme3D::moveLeft(float delta)
{
    for (int i = 0; i < this->f_vertices.size(); i++)
        this->f_vertices[i].position.x += delta;
    this->f_center.x += delta;
}

void forme3D::moveDepth(float delta)
{
    for (int i = 0; i < this->f_vertices.size(); i++)
        this->f_vertices[i].position.y += delta;
    this->f_center.y += delta;
}

void forme3D::deleteBuffer()
{
    glDeleteBuffers(1, &this->f_vbo);
    glDeleteVertexArrays(1, &this->f_vao);
}
