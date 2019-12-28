#pragma once
#include<array>
#include<vector>
#include<map>
#include "cube.hpp"
#include "cursor.hpp"
#include "../libs/glimac/include/glm.hpp"


class Grid {
    private:
        //Determine a fixed size to the world ( Width*Depth*Height = 20*20*10)
        std::array< std::array< std::array<int,10> ,20> ,20> g_location;
        std::map<glm::vec3, Cube> stockCube;

    public:
        Grid(const Grid&) = default;
        void fillCase();
        void displayGrid();
        void drawGrid();
        
}