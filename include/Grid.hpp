#pragma once

#include <vector>
#include "./forme3D.hpp"
#include "./cube.hpp"
#include "../libs/glimac/include/glm.hpp"
#include "../libs/glimac/include/Program.hpp"
#include "../libs/glimac/include/FilePath.hpp"


class Grid {
    
    private:
        //Determine a fixed size to the world ( Width*Depth*Height = 20*20*10)
        int width = 20;
        int height = 20;
        int depth = 10;
        int g_location[20][20][20] = {0};
        std::vector<Cube> stockCube;
        std::vector<glm::vec3> stockColor = {glm::vec3(1.0,0.2,0.3), glm::vec3(0.2,1.0,0.4), glm::vec3(0.3,0.1,1.0)};

        bool gridDisplay;

    public:
        Grid(const Grid&) = default;
        Grid();

        //To get the reference to the vector<Cube> attribute
        std::vector<Cube> &getVectorCube();
        std::vector<glm::vec3> &getVectorColor();

        int &getIndexCube(const glm::vec3 &position);

        void AddCube(const glm::vec3 &position, const glm::vec3 &color);
        void deleteCube(const glm::vec3 &position);

        void extrudCube(const glm::vec3 &position,const glm::vec3 &color);
        void digCube(const glm::vec3 &position);

        void outofWorld(const glm::vec3 &position);

        //void displayGrid();
        void refreshGrid();
        

        ~Grid();
        
};