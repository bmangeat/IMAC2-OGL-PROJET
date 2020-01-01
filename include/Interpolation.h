#pragma once

#include <iostream>
#include <cmath>
#include <Eigen/Dense>
#include <glimac/include/glm.hpp>

class Interpolation{
public:
    double phiDistance(glm::vec3 a, glm::vec3 b);
    double phiQuad(glm::vec3 a, glm::vec3 b);
    double phiInvQuad(glm::vec3 a, glm::vec3 b);
    double phiGauss(glm::vec3 a, glm::vec3 b);

private:
};