#pragma once

#include <vector>
#include "./cube.hpp"
#include "../libs/glimac/include/glm.hpp"
#include "../libs/glimac/include/Program.hpp"
#include "../libs/glimac/include/FilePath.hpp"


class Grid {
    
    private:
        //Determine a fixed size to the world ( Width*Depth*Height = 20*20*10)
        int g_location[20][20][10] = {0};
        std::vector<Cube> stockCube;
        GLuint vao;
        GLuint vbo;
        GLuint ibo;
        bool gridDisplay;

    public:
        Grid(const Grid&) = default;
        Grid();
        void contenu();

        //To get the reference to the vector<Cube> attribute
        std::vector<Cube> &getVectorCube();

        void AddCube(const glm::vec3 &position);
        void deleteCube(const glm::vec3 &position);

        //Modify the bool gridDisplay
        //void displayGrid();

        //To draw the grill if the bool Griddisplay is true
        //void drawGrid();

        ~Grid();
        
};