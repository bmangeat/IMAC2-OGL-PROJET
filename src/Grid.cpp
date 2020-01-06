#include "../include/Grid.hpp"

    Grid::Grid() {
    }

    std::vector<Cube> &Grid::getVectorCube() {
        return this->stockCube;
    }

    std::vector<glm::vec3> &Grid::getVectorColor() {
        return this->stockColor;
    }

    void Grid::AddCube(const glm::vec3 &position, const glm::vec3 &color) {
            this->outofWorld(position);
            int x=static_cast<int>(position.x) + 10;
            int y=static_cast<int>(position.y) + 10;
            int z=static_cast<int>(position.z) + 5;

            std::cout << "x= " << x << " y= " << y << " z= " << z << std::endl;
            if (this->g_location[x][y][z] == 0)
            {
                Cube newCube(position,color);
                this->stockCube.push_back(newCube);
                this->g_location[x][y][z] = this->stockCube.size() -1;
            }
            else this->deleteCube(position);
        }

    void Grid::deleteCube(const glm::vec3 &position) {
            int x=static_cast<int>(position.x) + 10;
            int y=static_cast<int>(position.y) + 10 ;
            int z=static_cast<int>(position.z) + 5;
            if (this->g_location[x][y][z] != 0) {
                for (int i=0; i < 20; i++) {
                    for (int j=0; j<20; j++) {
                        for (int k=0; k<10; k++) {
                            if (this->g_location[i][j][k] > this->g_location[x][y][z]) {
                                this->g_location[i][j][k] -= 1;
                            }
                        } 
                    }
                }
                this->stockCube.erase( this->stockCube.cbegin()  + this->g_location[x][y][z] -1 );
                this->g_location[x][y][z] = 0;
            }
            else std::cout<< "Il n'y a pas de cube" << std::endl;
    }

    void Grid::outofWorld(const glm::vec3 &position) {
        if (position.x < -10 || position.x>10 || position.y < -10 || position.y>10 || position.z < -5 || position.z>5) {
            std::cerr<< "The cursor is out of the world" << std::endl;
        }
    }

    Grid::~Grid() {}