#pragma once

#include <iostream>
#include <fstream>
#include <sstream>

#include <string>
#include "cube.hpp"
#include "Grid.hpp"

class Save{
public:
    Save() = default;
    ~Save() = default;

    //! Save the queen
    /*!
      \param nameFile
      \param vectorCube Get all cubes created in our scene
      \param vectorCube Get all color's cubes created in our scene

    */
    void saveScene(std::string &nameFile, std::vector<Cube> vectorCube);

    //! Load the queen
    /*!
      \param fpath Send path of your file in your computer
    */
    void loadScene(std::string &nameFile, Grid& Grid);

};

