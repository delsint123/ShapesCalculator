/* --------------------------------------------------------
 *    File: Triangle.cpp
 *   Class: COP 3003, Fall 2022
 *     Dev: Delphine Sintamour
 * Purpose: Implementation of a Triangle class object
 * -------------------------------------------------------- */

#define _USE_MATH_DEFINES // for C++
#include <cmath>
#include "Triangle.h"
#include "Line.h"

//Constructors
//-----------------------------------------------------
Triangle::Triangle() {
    points = std::vector<Point>();
    shapeType = 'T';
}

Triangle::Triangle(std::vector<Point> points) {
    this->points = points;
    this->shapeType = 'L';

    //set other attributes
    calculateLines();
    setCalcValues();
}

//Methods
//-----------------------------------------------------

/**
 * Converts each point to 3 lines using the Class Line
 * to simplify calculations.
 */
void Triangle::calculateLines() {
    //0 = A;
    //1 = B;
    //2 = C;
    //lineC;          //line a to b;
    //lineA;          //line b to c;
    //lineB;          //line c to a;
    std::vector<Point> tempPoints;

    tempPoints.push_back(points[0]);
    tempPoints.push_back(points[1]);
    lineC = Line(tempPoints);

    tempPoints[0] = points[1];
    tempPoints[1] = points[2];
    lineA = Line(tempPoints);

    tempPoints[0] = points[2];
    tempPoints[1] = points[0];
    lineB = Line(tempPoints);
}


/**
 * Calls all calculations in the same method.
 */
void Triangle::setCalcValues() {
    calculatePerimeter();
    calculateArea();
    calculateAngles();
}


/**
 * Calculates the perimeter of the triangle using the lengths
 * that were calculated when instantiating the as Lines
 */
void Triangle::calculatePerimeter() {
    perimeter = lineC.getLength() + lineA.getLength() + lineB.getLength();
}


/**
 * Calculates the area of the triangle by utilizing the semiperimeter.
 * Semiperimeter calculated using the perimeter.
 */
void Triangle::calculateArea() {
    float s = perimeter / 2;

    float inner = s * (s - lineA.getLength()) * (s - lineB.getLength()) * (s - lineC.getLength());
    area = sqrt(inner);
}


/**
 * Calculates all angles for each side
 * Geo Refresher: angle a is "across" from side a and so on
 */
void Triangle::calculateAngles() {
    calculateAngleBtwn2Lines(lineA, lineB.getLength(), lineC.getLength());     //angle a
    calculateAngleBtwn2Lines(lineB, lineA.getLength(), lineC.getLength());     //angle b
    calculateAngleBtwn2Lines(lineC, lineA.getLength(), lineB.getLength());     //angle c
}


/**
 * Calculates the for 1 side
 * @param currLineZ: passed by reference to updated the angle of the line
 * @param lengthX: length of another side
 * @param lengthY: length of another side
 */
void Triangle::calculateAngleBtwn2Lines(Line &currLineZ, float lengthX, float lengthY) {
    float lengthZ = currLineZ.getLength();

    float sqrLengthX = pow(lengthX, 2.0);
    float sqrLengthY = pow(lengthY, 2.0);
    float sqrLengthZ = pow(lengthZ, 2.0);

    float inner = (sqrLengthX + sqrLengthY - sqrLengthZ) / (2.0 * lengthX * lengthY);
    float angle = acos(inner) * 180.0 / M_PI; //convert to degrees;

    currLineZ.setAngle(angle);
}


/**
 * outputs the Triangle's details both calculated and inputted
 * @return a string used for output of the Triangle's details
 */
std::string Triangle::print() {
    std::string output = "Triangle: \n";
    output += "\t Points: {" + points[0].getCoord() + ", " + points[1].getCoord()
            + ", " + points[2].getCoord() + "}\n";

    output += "\t A: \n";
    output += "\t\t length = " + std::to_string(lineA.getLength()) + "\n";
    output += "\t\t angle = " + std::to_string(lineA.getAngle()) + "\n";
    output += "\t B: \n";
    output += "\t\t length = " + std::to_string(lineB.getLength()) + "\n";
    output += "\t\t angle = " + std::to_string(lineB.getAngle()) + "\n";
    output += "\t C: \n";
    output += "\t\t length = " + std::to_string(lineC.getLength()) + "\n";
    output += "\t\t angle = " + std::to_string(lineC.getAngle()) + "\n";

    output += "\t Perimeter = " + std::to_string(perimeter) + "\n";
    output += "\t Area = " + std::to_string(area) + "\n";

    return output;
}



