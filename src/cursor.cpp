#include "../include/cursor.hpp"

    Cursor::Cursor(glimac::FilePath applicationPath) {
        this->CursorProgram = loadProgram(applicationPath.dirPath() + "../assets/shaders/3D.vs.glsl",
                                        applicationPath.dirPath() + "../assets/shaders/cursorShader/cursorEdges.fs.glsl");

        this->uSelect = glGetUniformLocation(CursorProgram.getGLId(), "uSelect");
        glUniform1i( this->uSelect,  this->select);

        float x = this->c_position.x;
        float y = this->c_position.y;
        float z = this->c_position.z;

        //Set vertices coordinates
        std::vector<glm::vec3> tmp_vertices = { 
        glm::vec3(x-0.5f, y+0.5f, z-0.5f),
        glm::vec3(x+0.5f, y+0.5f, z-0.5f),
        glm::vec3(x-0.5f, y+0.5f, z+0.5f),
        glm::vec3(x+0.5f, y+0.5f, z+0.5f),

        glm::vec3(x-0.5f, y-0.5f, z-0.5f),
        glm::vec3(x+0.5f, y-0.5f, z-0.5f),
        glm::vec3(x-0.5f, y-0.5f, z+0.5f),
        glm::vec3(x+0.5f, y-0.5f, z+0.5f)
        };

        for(size_t j = 0; j < 8; ++j) {
            glimac::ShapeVertex vertex;
            
            vertex.texCoords.x = 0;
            vertex.texCoords.y = 1;

            vertex.normal.x = tmp_vertices[j].x;
            vertex.normal.y = tmp_vertices[j].y;
            vertex.normal.z = tmp_vertices[j].z;
            
            vertex.position = vertex.normal;
            
            this->c_vertices.push_back(vertex);
        }

        //this->vbo creation
        glGenBuffers(1, &this->vbo);

        //Binding this->vbo
        glBindBuffer(GL_ARRAY_BUFFER, this->vbo);

        glBufferData(GL_ARRAY_BUFFER, (this->c_vertices.size()+1) * sizeof(glimac::ShapeVertex), this->c_vertices.data(), GL_STATIC_DRAW);

        //débinder
        glBindBuffer(GL_ARRAY_BUFFER,0);

        //IBO Creation
        glGenBuffers(1, &this->ibo);

        //biding ibo
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->ibo);

        //Tableau d'indices
        std::vector<uint32_t> index = {
            1,2,    2,4,    4,3,    3,1,
            3,7,    7,5,    1,5,
            7,8,    8,6,    5,6,
            4,8,    2,6
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

    void Cursor::actualizeVertex() {
        //Binding this->vbo
        glBindBuffer(GL_ARRAY_BUFFER, this->vbo);

        glBufferData(GL_ARRAY_BUFFER, (this->c_vertices.size()+1) * sizeof(glimac::ShapeVertex), this->c_vertices.data(), GL_STATIC_DRAW);

        //débinder
        glBindBuffer(GL_ARRAY_BUFFER,0);

        //IBO Creation
        glGenBuffers(1, &this->ibo);

        //biding ibo
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->ibo);

        //Tableau d'indices
        std::vector<uint32_t> index = {
            1,2,    2,4,    4,3,    3,1,
            3,7,    7,5,    1,5,
            7,8,    8,6,    5,6,
            4,8,    2,6
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

    void Cursor::setCursorProgram(glimac::FilePath applicationPath) {
        this->CursorProgram = loadProgram(applicationPath.dirPath() + "../assets/shaders/3D.vs.glsl",
                                        applicationPath.dirPath() + "../assets/shaders/cursorShader/cursorEdges.fs.glsl");
        this->CursorProgram.use();
    }

    const glm::vec3 Cursor::getCursorPosition() {
        return this->c_position;
    }

    void Cursor::moveUp(float delta) {
        for (int i=0 ; i < this->c_vertices.size() ; i++) {
            this->c_vertices[i].position.z += delta;
            std::cout << this->c_vertices[i].position.z << std::endl;
        }
    }

    void Cursor::moveLeft(float delta) {
        for (int i=0; i < this->c_vertices.size(); i++)
            this->c_vertices[i].position.x += delta;
    }

    void Cursor::moveDepth(float delta) {
        for (int i=0; i < this->c_vertices.size(); i++)
            this->c_vertices[i].position.y += delta;
    }


    void Cursor::DrawCursor(){
        //rebind vao
        glBindVertexArray(this->vao);
        //biding ibo
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->ibo);
        glDrawElements(GL_LINES, 12*2, GL_UNSIGNED_INT, 0);
        glBindVertexArray(0);
    }

    void Cursor::changeDisplay() {
        if (this->cursorDisplay == true)
            this->cursorDisplay = false;
        else this->cursorDisplay = true;
    }

    //Check if the cursor had to be displayed
    const void Cursor::displayCursor() {
        if (cursorDisplay == true) {
            this->DrawCursor();
        }
    }

    void Cursor::selectCase() {
        if (this->select == true) {
            this->select = false;
            glUniform1i( this->uSelect,  this->select);
        }
        else {
            this->select = true;
            glUniform1i( this->uSelect,  this->select);
        }
    }

    Cursor::~Cursor() {};


    void manageCursorPos(Cursor cursor, SDL_Event e) {
            switch(e.type) {

                case SDL_KEYDOWN:
                    if (e.key.keysym.sym == SDLK_g) {
                        cursor.moveUp(1.f);
                    }
                    if (e.key.keysym.sym == SDLK_b) {
                        cursor.moveUp(-1.f);
                        
                    }
                    if (e.key.keysym.sym == SDLK_v) {
                        cursor.moveLeft(-1.f);
                    }
                    if (e.key.keysym.sym == SDLK_n) {
                        cursor.moveLeft(1.f);
                    }
                    if (e.key.keysym.sym == SDLK_f) {
                        cursor.moveDepth(-1.f);
                    }
                    if (e.key.keysym.sym == SDLK_h) {
                        cursor.moveDepth(1.f);
                    }
                    break;

                case SDL_KEYUP:
                    //cout << "touche levée (code = "<< e.key.keysym.sym << ")" << endl;
                    break;
            }
    }