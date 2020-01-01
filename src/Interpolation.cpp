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


