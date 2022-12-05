/* --------------------------------------------------------
 *    File: Point.cpp
 *   Class: COP 3003, Fall 2022
 *     Dev: Delphine Sintamour
 * Purpose: Implementation of a Point class object
 * -------------------------------------------------------- */

#include "Point.h"

//Constructors
//-----------------------------------------------------
Point::Point() {
    x = 0;
    y = 0;
}

Point::Point(float xValue, float yValue) {
    x = xValue;
    y = yValue;
}

//Accessors
//-----------------------------------------------------
float Point::getX() {
    return x;
}

void Point::setX(float value) {
    x = value;
}

float Point::getY() {
    return y;
}

void Point::setY(float value) {
    y = value;
}

//Methods
//-----------------------------------------------------

/**
 * Stores the x and y values in coord string (x, y) form
 * @return coordinate used for output in main program
 */
std::string Point::getCoord() {
    std::string coord = "(";
    coord += std::to_string(x) + ", ";
    coord += std::to_string(y) + ")";

    return coord;
}
