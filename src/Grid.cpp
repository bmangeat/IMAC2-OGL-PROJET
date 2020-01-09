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
    int x = static_cast<int>(position.x) + 10;
    int y = static_cast<int>(position.y) + 10;
    int z = static_cast<int>(position.z) + 5;
    std::cout << " x, y z = " << x << " " << y << " " << z << std::endl;
    if (this->g_location[x][y][z] == 0) {
        Cube newCube(position, color);
        this->stockCube.push_back(newCube);
        this->g_location[x][y][z] = this->stockCube.size();
        std::cout << "CENTER x,y,z = " << this->stockCube[this->stockCube.size() - 1].getCenter() << std::endl;
        std::cout << "number  of cube at x,y,z = " << this->g_location[x][y][z] << std::endl << std::endl;
    } else this->deleteCube(position);
}

void Grid::deleteCube(const glm::vec3 &position) {
    int x = static_cast<int>(position.x) + 10;
    int y = static_cast<int>(position.y) + 10;
    int z = static_cast<int>(position.z) + 5;
    std::cout << " x, y z = " << x << " " << y << " " << z << std::endl;
    if (this->g_location[x][y][z] != 0) {
        for (int i = 0; i < 20; ++i) {
            for (int j = 0; j < 20; ++j) {
                for (int k = 0; k < 10; ++k) {
                    if (this->g_location[i][j][k] > this->g_location[x][y][z]) {
                        this->g_location[i][j][k] -= 1;
                        std::cout << " ijk " << this->g_location[i][j][k] << std::endl;
                    }
                }
            }
        }
        std::cout << "n = " << this->g_location[x][y][z] << std::endl;
        this->stockCube.erase(this->stockCube.cbegin() + (this->g_location[x][y][z] - 1));
        this->g_location[x][y][z] = 0;
        std::cout << "n aft = " << this->g_location[x][y][z] << std::endl;
    } else std::cout << "Il n'y a pas de cube" << std::endl;
}

void Grid::refreshGrid() {
    for (int i = -9; i < 10; ++i) {
        for (int j = -9; j < 10; ++j) {
            for (int k = -4; k < 5; ++k) {
                deleteCube(glm::vec3(i, j, k));
            }
        }

    }
}

Grid::~Grid() {}