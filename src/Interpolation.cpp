#include <iostream>
#include <cmath>
#include <Eigen/Dense>
#include <glimac/include/glm.hpp>
#include "../include/Interpolation.h"

#include <random>
#include <chrono>


Interpolation::Interpolation(size_t numberControlPoint)
        : _numberControlPoint(numberControlPoint) {
}

double Interpolation::phiDistance(glm::vec3 a, glm::vec3 b) {
    return abs(glm::distance(a, b));
}

double Interpolation::phiQuad(glm::vec3 a, glm::vec3 b) {
    return abs(sqrt(1 + pow(glm::distance(a, b), 2)));
}

double Interpolation::phiInvQuad(glm::vec3 a, glm::vec3 b) {
    return abs(1 / (1 + pow(glm::distance(a, b), 2)));
}

double Interpolation::phiGauss(glm::vec3 a, glm::vec3 b) {
    return abs(exp(-pow(glm::distance(a, b), 2)));
}

Eigen::VectorXd Interpolation::computeOmegas() {
    controlPoints = generateControlPoint();
    weightControlPoint = generateWeightControlPoint();


    Eigen::MatrixXd phiMatrix = Eigen::MatrixXd::Zero(controlPoints.size(), controlPoints.size());

    // Parse our matrix in order to fill with distance between two control points
    for (size_t i = 0; i < controlPoints.size(); ++i) {
        for (size_t j = 0; j < controlPoints.size(); ++j) {
            phiMatrix(i, j) = phiDistance(controlPoints[i], controlPoints[j]);
        }
    }


    return phiMatrix.inverse() * weightControlPoint;
}

double Interpolation::evaluatePoint(glm::vec3 x) {

    // ux is the weight on the point X
    double ux = 0.f;
    for (int i = 0; i < controlPoints.size(); ++i) {
        ux += omegas(i) * phiDistance(x, controlPoints[i]);
    }

    return ux;
}

std::vector<glm::vec3> Interpolation::generateControlPoint() {

    std::vector<glm::vec3> controlPointVec;
    // select seed from time
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();

    std::ranlux24_base ranlux24Generator(seed);

    std::uniform_int_distribution<int> uniformIntDistribution(1, 10);
    for (size_t i = 0; i < _numberControlPoint; ++i) {

        glm::vec3 controlPoint(uniformIntDistribution(ranlux24Generator),
                               uniformIntDistribution(ranlux24Generator),
                               uniformIntDistribution(ranlux24Generator));
        controlPointVec.push_back(controlPoint);

    }

    return controlPointVec;
}

Eigen::VectorXd Interpolation::generateWeightControlPoint() {

    Eigen::VectorXd weightControlPointVec(_numberControlPoint);
    // select seed from time
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();

    std::ranlux24_base ranlux24Generator(seed);


    std::uniform_int_distribution<int> uniformIntDistribution(-10, 10);
    for (size_t i = 0; i < _numberControlPoint; ++i) {
        weightControlPointVec(i) = double(uniformIntDistribution(ranlux24Generator));
    }


    return weightControlPointVec;
}

glm::vec3 Interpolation::generateColor() {

    // select seed from time
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();

    std::ranlux24_base ranlux24Generator(seed);

    std::uniform_real_distribution<double> uniformDoubleDistribution(0, 1);

    glm::vec3 color(uniformDoubleDistribution(ranlux24Generator),
                    uniformDoubleDistribution(ranlux24Generator),
                    uniformDoubleDistribution(ranlux24Generator));


    return color;
}

void Interpolation::generateCubes(Grid &grid) {
    omegas = computeOmegas();
    grid.refreshGrid();

    for (int i = -9; i < 10; ++i) {
        for (int j = -9; j < 10; ++j) {
            for (int k = -9; k < 10; ++k) {
                glm::vec3 currentPoint(i, j, k);
                double weightPoint = evaluatePoint(currentPoint);

                if (weightPoint >= 0) {
                    grid.AddCube(currentPoint, generateColor());
                }
            }
        }

    }

}






