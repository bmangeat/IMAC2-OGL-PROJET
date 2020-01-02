#pragma once

#include <iostream>
#include <cmath>
#include <Eigen/Dense>
#include <vector>
#include <glimac/include/glm.hpp>

class Interpolation{


public:
    //! Constructor
    /*!
      \param numberControlPoint Define the number of control points for interpolation
    */
    Interpolation(size_t numberControlPoint);


    //! Radial function : φ(d) = d
    /*!
      \param a Vector3 from glm's library corresponding to a point or cube from our world
      \param b Vector3 from glm's library corresponding to a point or cube from our world
    */
    double phiDistance(glm::vec3 a, glm::vec3 b);

    //! Radial function : Multiquadric φ(d) = sqrt ( 1 + d²)
    /*!
      \param a Vector3 from glm's library corresponding to a point or cube from our world
      \param b Vector3 from glm's library corresponding to a point or cube from our world
    */
    double phiQuad(glm::vec3 a, glm::vec3 b);

    //! Radial function decreasing : Multiquadric Inverse  φ(d) = 1 / ( 1 + d²)
    /*!
      \param a Vector3 from glm's library corresponding to a point or cube from our world
      \param b Vector3 from glm's library corresponding to a point or cube from our world
    */
    double phiInvQuad(glm::vec3 a, glm::vec3 b);

    //! Radial function decreasing : Gaussian  φ(d) = exp ( d² )
    /*!
      \param a Vector3 from glm's library corresponding to a point or cube from our world
      \param b Vector3 from glm's library corresponding to a point or cube from our world
    */
    double phiGauss(glm::vec3 a, glm::vec3 b);

    //! Calculate ω from our control points
    /*!
      \param controlPoint Vector of points created randomly
      \param weightControlPoint Vector from Eigen also created randomly and contain weight of controlPoint
    */
    Eigen::VectorXd computeWeight();


    std::vector<glm::vec3> generateControlPoint();
private:
    size_t _numberControlPoint;
    std::vector<glm::vec3> controlPoints;
    Eigen::VectorXd weightControlPoint;

    double evaluatePoint(glm::vec3 x);

    Eigen::VectorXd generateWeightControlPoint();
};