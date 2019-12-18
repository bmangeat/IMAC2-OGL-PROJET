#include "../include/cube.hpp"

    Cube::Cube(const Cube&) {};

    Cube::Cube(std::vector<glm::vec3> tmp_vertices) {

        //Set vertices coordinates

        for(size_t j = 0; j < 8; ++j) {
            glimac::ShapeVertex vertex;
            
            vertex.texCoords.x = 0;
            vertex.texCoords.y = 1;

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
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, index.size() * sizeof(uint32_t), index.data(), GL_STATIC_DRAW);

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
    }

    void Cube::actualizeVertex() {
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
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, index.size() * sizeof(uint32_t), index.data(), GL_STATIC_DRAW);

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
    }

    void Cube::setCubeProgram(glimac::FilePath applicationPath) {
        this->CubeProgram = loadProgram(applicationPath.dirPath() + "../assets/shaders/3D.vs.glsl",
                                        applicationPath.dirPath() + "../assets/shaders/cubeShader/cubeTexture.fs.glsl");
        this->CubeProgram.use();
    }
       
    void Cube::drawCube() {
        //rebinder vao
        glBindVertexArray(this->vao);
        glDrawElements(GL_TRIANGLES, 12*3, GL_UNSIGNED_INT, 0);
        glBindVertexArray(0);
    }

    void Cube::deleteBuffer() {
        glDeleteBuffers(1,&this->vbo);
        glDeleteVertexArrays(1,&this->vao);
    }

    void Cube::moveUp(float delta) {
        for (int i=0 ; i < this->vertices.size() ; i++) {
            this->vertices[i].position.z += delta;
            std::cout << this->vertices[i].position.z << std::endl;
        }
    }

    void Cube::moveLeft(float delta) {
        for (int i=0; i < this->vertices.size(); i++)
            this->vertices[i].position.x += delta;
    }

    void Cube::moveDepth(float delta) {
        for (int i=0; i < this->vertices.size(); i++)
            this->vertices[i].position.y += delta;
    }

    Cube::~Cube() {
        delete this;
    }



    void firstLayer(std::vector<Cube> Layer) {
        Layer[0].actualizeVertex();
        Layer[0].drawCube();
        Layer[1].actualizeVertex();
        Layer[1].drawCube();
        Layer[2].actualizeVertex();
        Layer[2].drawCube();
    }