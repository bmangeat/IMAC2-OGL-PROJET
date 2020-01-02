#include <iostream>
#include <cmath>
#include <Eigen/Dense>
#include <glimac/include/glm.hpp>
#include "../include/Interpolation.h"


double Interpolation::phiDistance(glm::vec3 a, glm::vec3 b) {
    return glm::distance(a, b);
}

double Interpolation::phiQuad(glm::vec3 a, glm::vec3 b) {
    return sqrt(1+pow(glm::distance(a,b),2));
}

double Interpolation::phiInvQuad(glm::vec3 a, glm::vec3 b) {
    return 1/(1+pow(glm::distance(a,b),2));
}

double Interpolation::phiGauss(glm::vec3 a, glm::vec3 b) {
    return exp(-pow(glm::distance(a,b),2));
}

Eigen::VectorXd Interpolation::computeWeight(const std::vector<glm::vec3> controlPoint, const Eigen::VectorXd weightControlPoint) {
    Eigen::MatrixXd phiDistance = Eigen::MatrixXd::Zero(controlPoint.size(), controlPoint.size() );

    for (size_t i = 0; i < controlPoint.size() ; ++i) {
        for (size_t j = 0; j < controlPoint.size() ; ++j) {
            phiDistance(i,j) = phiGauss(controlPoint[i], controlPoint[j]);
        }
    }



    return phiDistance.inverse()*weightControlPoint;
}


