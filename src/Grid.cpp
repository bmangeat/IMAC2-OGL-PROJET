#include "../include/Grid.hpp"


    Grid::Grid() {};

    std::vector<Cube> &Grid::getVectorCube() {
        return this->stockCube;
    }

    void Grid::AddCube(const glm::vec3 &position) {
            int x=static_cast<int>(position.x);
            int y=static_cast<int>(position.y);
            int z=static_cast<int>(position.z);
            if (this->g_location[x][y][z] == -1)
            {
                Cube newCube(position);
                this->stockCube.push_back(newCube);
                this->g_location[x][y][z] = this->stockCube.size();
            }
            else std::cout<< "Il y a déjà un cube" << std::endl;
        }

    void Grid::deleteCube(const glm::vec3 &position) {
            int x=static_cast<int>(position.x);
            int y=static_cast<int>(position.y);
            int z=static_cast<int>(position.z);
            if (this->g_location[x][y][z] != -1) {
                for (int i=0; i < 20; i++) {
                    for (int j=0; j<20; j++) {
                        for (int k=0; k<10; k++) {
                            if (this->g_location[i][j][k] > this->g_location[x][y][z]) {
                                this->g_location[i][j][k] -= 1;
                            }
                        } 
                    }
                }
                this->stockCube.erase( this->stockCube.begin() + (this->g_location[x][y][z] - 1) );
                this->g_location[x][y][z] = -1;
            }
            else std::cout<< "Il n'y a pas de cube" << std::endl;
    }

    Grid::~Grid() {}