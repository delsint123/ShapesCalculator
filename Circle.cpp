/* --------------------------------------------------------
 *    File: Circle.cpp
 *   Class: COP 3003, Fall 2022
 *     Dev: Delphine Sintamour
 * Purpose: Implementation of a Circle class object
 * -------------------------------------------------------- */

#define _USE_MATH_DEFINES // for C++
#include <cmath>
#include "Circle.h"

//Constructors
//-----------------------------------------------------
Circle::Circle() {
    points = std::vector<Point>();
    shapeType = 'C';
}

Circle::Circle(std::vector<Point> points, float radius) {
    this->points = points;
    this->shapeType = 'C';
    this->radius = radius;

    //set other attributes
    setPointsForCalc();
    setCalcValues();
}

//Accessors
//-----------------------------------------------------
float Circle::getRadius() {
    return radius;
}

void Circle::setRadius(float value) {
    radius = value;
}

//Methods
//-----------------------------------------------------

/**
 * Separates the coordinates in the vector, in the class Point
 * for easier calculations.
 * Values would be retrieved repeatedly otherwise.
 * NOTE: these are never used but could be used if calculator expands
 */
void Circle::setPointsForCalc() {
    x1 = points[0].getX();
    y1 = points[0].getY();
}


/**
 * Calls all calculations in the same method.
 */
void Circle::setCalcValues() {
    calculateDiameter();
    calculateCircumference();
    calculateArea();
}


/**
 * Calculates the diameter of the circle using the
 * corresponding formula.
 */
void Circle::calculateDiameter() {
    diameter = 2.0 * radius;
}


/**
 * Calculates the circumference of the circle using the
 * corresponding formula
 */
void Circle::calculateCircumference() {
    circumference = 2.0 * M_PI * radius;
}


/**
 * Calculates the area od the circle using the corresponding
 * formula.
 */
void Circle::calculateArea() {
    area = M_PI * pow(radius, 2.0);
}


/**
 * outputs the Circle's details both calculated and inputted
 * @return a string used for output of the Circle's details
 */
std::string Circle::print() {
    std::string output = "Circle: \n";
    output += "\t Point: {" + points[0].getCoord() + "}\n";
    output += "\t Radius = " + std::to_string(radius) + "\n";
    output += "\t Diameter = " + std::to_string(diameter) + "\n";
    output += "\t Circumference = " + std::to_string(circumference) + "\n";
    output += "\t Area = " + std::to_string(area) + "\n";

    return output;
}
