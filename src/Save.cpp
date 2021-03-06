#include "../include/Save.hpp"


void Save::saveScene(std::vector<Cube> vectorCube) {

    std::string nameFile;
    std::cout << "Veuillez entrer le nom du fichier à enregistrer ?";
    std::cin >> nameFile;

    std::ofstream outfile;
    outfile.open("./bin/" + nameFile, std::ios::out | std::ios::binary);

    if (!outfile.is_open()) {
        std::cerr << "Can not create file named " + nameFile + "." << std::endl;
    }

    outfile << vectorCube.size() << std::endl;
    for (size_t i = 0; i < vectorCube.size(); ++i) {
        outfile << vectorCube[i].getCenter().x << " ";
        outfile << vectorCube[i].getCenter().y << " ";
        outfile << vectorCube[i].getCenter().z << " ";
        outfile << vectorCube[i].getColor().r << " ";
        outfile << vectorCube[i].getColor().g << " ";
        outfile << vectorCube[i].getColor().b << " ";
    }

    outfile.close();


}

void Save::loadScene(Grid &grid) {

    std::string nameFile;
    std::cout << "Quelle scène voulez-vous enregistrer ?";
    std::cin >> nameFile;

    std::ifstream infile;
    infile.open("./bin/" + nameFile, std::ios::out | std::ios::binary);

    if (!infile.is_open()) {
        std::cerr << "Can not read file named " + nameFile + "." << std::endl;
    }

    size_t nbIter;
    infile >> nbIter;
    std::vector<glm::vec3> vectorPosCubesWillLoad(nbIter);
    std::vector<glm::vec3> vectorColorCubesWillLoad(nbIter);

    std::cout << nbIter << std::endl;


    for (size_t i = 0; i < nbIter; ++i) {

        infile >> vectorPosCubesWillLoad[i].x;
        infile >> vectorPosCubesWillLoad[i].y;
        infile >> vectorPosCubesWillLoad[i].z;
        infile >> vectorColorCubesWillLoad[i].r;
        infile >> vectorColorCubesWillLoad[i].g;
        infile >> vectorColorCubesWillLoad[i].b;

    }

    grid.refreshGrid();

    for (int j = 0; j < nbIter; ++j) {
        grid.AddCube(vectorPosCubesWillLoad[j],vectorColorCubesWillLoad[j]);
    }

    infile.close();
}
