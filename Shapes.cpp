/* --------------------------------------------------------
 *    File: Shapes.cpp
 *   Class: COP 3003, Fall 2022
 *     Dev: Delphine Sintamour
 * Purpose: Implementation of a Shapes class object
 * -------------------------------------------------------- */

#include "Shapes.h"

//Constructors
//-----------------------------------------------------
Shape::Shape() {
    points = std::vector<Point>();
    shapeType = ' ';
}

Shape::Shape(std::vector<Point> points, char shapeType) {
    this->points = points;
    this->shapeType = shapeType;
}

//Accessors
//-----------------------------------------------------
std::vector<Point> Shape::getPoints() {
    return points;
}

void Shape::setPoints(float xValue, float yValue) {

    Point currPoint(xValue, yValue);
    points.push_back(currPoint);
}

char Shape::getShapeType() {
    return shapeType;
}

void Shape::setShapeType(char character) {
    shapeType = character;
}

//Methods
//-----------------------------------------------------

/**
 * outputs the shapes details both calculated and inputted
 * @return a string used for output of shape details
 */
std::string Shape::print() {
    std::string output = " ";
    return output;
}


