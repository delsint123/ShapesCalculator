/* --------------------------------------------------------
 *    File: Line.cpp
 *   Class: COP 3003, Fall 2022
 *     Dev: Delphine Sintamour
 * Purpose: Implementation of a Line class object
 * -------------------------------------------------------- */

#define _USE_MATH_DEFINES // for C++
#include <cmath>
#include "Line.h"

//Constructors
//-----------------------------------------------------
Line::Line() {
    points = std::vector<Point>();
    shapeType = 'L';
}

Line::Line(std::vector<Point> points) : Shape(points, shapeType) {
    this->points = points;
    this->shapeType = 'L';

    //set other attributes
    setPointsForCalc();
    setCalcValues();
}

//Accessors
//-----------------------------------------------------
float Line::getLength() {
    return length;
}

float Line::getAngle() {
    return angle;
}

void Line::setAngle(float value) {
    angle = value;
}

float Line::getSlope() {
    return slope;
}

//Methods
//-----------------------------------------------------

/**
 * Separates the coordinates in the vector, in the class Point
 * for easier calculations.
 * Values would be retrieved repeatedly otherwise.
 */
void Line::setPointsForCalc() {
    x1 = points[0].getX();
    y1 = points[0].getY();
    x2 = points[1].getX();
    y2 = points[1].getY();
}


/**
 * Calls all calculations in the same method.
 */
void Line::setCalcValues() {
    calculateLength();
    calculateSlope();
    calculateAngle();
}


/**
 * Calculates the length of the line using the distance formula
 */
void Line::calculateLength() {
    float inner = pow((x2 - x1), 2.0) + pow((y2 - y1), 2.0);

    length = sqrt(inner);
}


/**
 * Calculates the slope of the line using the slope formula
 */
void Line::calculateSlope() {
    slope = (y2 - y1) / (x2 - x1);
}


/**
 * Calculates the slope of the line using tangent
 */
void Line::calculateAngle() {
    angle = atan2((y2 - y1), (x2 - x1)) * 180 / M_PI;   //convert to degrees
}


/**
 * outputs the Line's details both calculated and inputted
 * @return a string used for output of the Line's details
 */
std::string Line::print() {
    std::string output = "Line: \n";
    output += "\t Points: {" + points[0].getCoord() + ", " + points[1].getCoord() + "}\n";
    output += "\t Length = " + std::to_string(length) + "\n";
    output += "\t Slope = " + std::to_string(slope) + "\n";
    output += "\t Angle = " + std::to_string(angle) + "\n";

    return output;
}













