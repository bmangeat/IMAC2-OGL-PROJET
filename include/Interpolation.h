#pragma once

#include <iostream>
#include <cmath>
#include <Eigen/Dense>
#include <vector>
#include <glimac/include/glm.hpp>
#include "Grid.hpp"

class Interpolation {


public:
    //! Constructor
    /*!
      \param numberControlPoint Define the number of control points for interpolation
    */
    Interpolation(size_t numberControlPoint);

    //! Calculate ω from our control points
    /*!
         Also generate control's points and co.
    */
    Eigen::VectorXd computeOmegas();

    //! Rate the cordonnate with RBF Function
    /*!
      \param vec3 X Match with cube's coordonate . This function will return the weight corresponding to the cube
    */
    double evaluatePoint(glm::vec3 x);

    void generateCubes(Grid grid);


private:

    //! Number of control's points
    /*!
      Variable can store the number of control's points desired
    */
    size_t _numberControlPoint;

    //! Vector of control's points
    /*!
      Store all control's points generated
    */
    std::vector<glm::vec3> controlPoints;

    //! Vector of (control) point's weight
    /*!
      Store all (control) point's weight generated
    */
    Eigen::VectorXd weightControlPoint;

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

    //! Generation function : Control's points
    std::vector<glm::vec3> generateControlPoint();

    //! Generation function : (Control's) Weight's points
    Eigen::VectorXd generateWeightControlPoint();

};
