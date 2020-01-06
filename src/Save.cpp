#include "../include/Save.hpp"


void Save::saveScene(std::string &nameFile, std::vector<Cube> vectorCube, std::vector<glm::vec3> vectorColor) {

    std::ofstream outfile;
    outfile.open("./bin/saves/" + nameFile, std::ios::out | std::ios::binary);

    if (!outfile.is_open()) {
        std::cerr << "Can not create file named " + nameFile + "." << std::endl;
    }

    outfile << vectorColor.size() << std::endl;
    for (size_t i = 0; i < vectorCube.size(); ++i) {
        outfile << vectorCube[i].getPos().x << " ";
        outfile << vectorCube[i].getPos().y << " ";
        outfile << vectorCube[i].getPos().y << " ";
        outfile << vectorColor[i].x << " ";
        outfile << vectorColor[i].y << " ";
        outfile << vectorColor[i].z << " ";
    }

    outfile.close();


}

void Save::loadScene(std::string &nameFile) {
    std::ifstream infile;
    infile.open("./bin/saves/" + nameFile, std::ios::out | std::ios::binary);

    if (!infile.is_open()) {
        std::cerr << "Can not read file named " + nameFile + "." << std::endl;
    }

    size_t nbIter;

    std::vector<Cube> vectorCubesWillLoad;

    for (int i = 0; i < nbIter; ++i) {
        // TODO: Parcourir le fichier

        //infile >> vectorCubesWillLoad[i].getPos().x;
        
    }

    infile.close();

    // TODO: Retourner le vector créé et générer la scène

}
