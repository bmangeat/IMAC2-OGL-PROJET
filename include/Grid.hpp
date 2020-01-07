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
    std::vector<glm::vec3> stockColor = {glm::vec3(1.0, 0.2, 0.3), glm::vec3(0.2, 1.0, 0.4), glm::vec3(0.3, 0.1, 1.0)};
    GLuint vao;
    GLuint vbo;
    GLuint ibo;
    bool gridDisplay;

public:
    Grid(const Grid &) = default;

    Grid();

    void contenu();

    //To get the reference to the vector<Cube> attribute
    std::vector<Cube> &getVectorCube();

    std::vector<glm::vec3> &getVectorColor();

    void AddCube(const glm::vec3 &position, const glm::vec3 &color);

    void deleteCube(const glm::vec3 &position);

    void refreshGrid();


    //Modify the bool gridDisplay
    //void displayGrid();

    //To draw the grill if the bool Griddisplay is true
    //void drawGrid();

    ~Grid();

};