#include "../include/Grid.hpp"

Grid::Grid()
{
}

std::vector<Cube> &Grid::getVectorCube()
{
    return this->stockCube;
}

std::vector<glm::vec3> &Grid::getVectorColor()
{
    return this->stockColor;
}

void Grid::extrudCube(const glm::vec3 &position, const glm::vec3 &color)
{
    int x = static_cast<int>(position.x) + 10;
    int y = static_cast<int>(position.y) + 10;
    int z = static_cast<int>(position.z) + 5;
    while (this->g_location[x][y][z]!= 0 && y<height)
    {
            ++y;
    }
    glm::vec3 dig = glm::vec3(position.x, y-10, position.z);
    this->AddCube(dig, color);
}

void Grid::digCube(const glm::vec3 &position)
{
    int x = static_cast<int>(position.x) + 10;
    int y = static_cast<int>(position.y) + 10;
    int z = static_cast<int>(position.z) + 5;
    while (this->g_location[x][y][z]!= 0 && y<height)
    {
            y++;
    }
    y--;
    glm::vec3 dig = glm::vec3(position.x, y-10, position.z);
    if (y>=position.y)
        this->deleteCube(dig);
}

int &Grid::getIndexCube(const glm::vec3 &position)
{
    int x = static_cast<int>(position.x) + 10;
    int y = static_cast<int>(position.y) + 10;
    int z = static_cast<int>(position.z) + 5;
    return this->g_location[x][y][z];
}

//To had the first third layer of cube
void Grid::firstFloor() {
    for (int i=0; i<20; i++) {
        for(int j=0; j<20; j++) {
            for (int k=-3; k<0; k++) {
                AddCube(glm::vec3(i-10,k,j-10), glm::vec3(0.4,0.8,0.45));
            }
        }
    }
}

void Grid::AddCube(const glm::vec3 &position, const glm::vec3 &color)
{
    int x = static_cast<int>(position.x) + 10;
    int y = static_cast<int>(position.y) + 10;
    int z = static_cast<int>(position.z) + 5;
    if (this->g_location[x][y][z] == 0)
    {
        Cube newCube(position, color);
        this->stockCube.push_back(newCube);
        this->g_location[x][y][z] = this->stockCube.size();
    }
}

void Grid::deleteCube(const glm::vec3 &position)
{
    int x = static_cast<int>(position.x) + 10;
    int y = static_cast<int>(position.y) + 10;
    int z = static_cast<int>(position.z) + 5;
    for (int i = 0; i < 20; ++i)
    {
        for (int j = 0; j < 20; ++j)
        {
            for (int k = 0; k < 10; ++k)
            {
                if (this->g_location[i][j][k] > this->g_location[x][y][z])
                {
                    this->g_location[i][j][k] -= 1;
                }
            }
        }
    }
    this->stockCube.erase(this->stockCube.cbegin() + (this->g_location[x][y][z] - 1));
    this->g_location[x][y][z] = 0;
}

void Grid::refreshGrid()
{
    for (int i = 0; i < 20; ++i)
    {
        for (int j = 0; j < 20; ++j)
        {
            for (int k = 0; k < 10; ++k)
            {
                 this->g_location[i][j][k] =0;
            }
        }
    }
    stockCube.clear();
}

Grid::~Grid() {}

