/* --------------------------------------------------------
 *    File: Rectangle.cpp
 *   Class: COP 3003, Fall 2022
 *     Dev: Delphine Sintamour
 * Purpose: Implementation of a Rectangle class object
 * -------------------------------------------------------- */

#include "Rectangle.h"

//Constructors
//-----------------------------------------------------
Rectangle::Rectangle() {
    points = std::vector<Point>();
    shapeType = 'R';
}

Rectangle::Rectangle(std::vector<Point> points, float width, float height) {
    this->points = points;
    this->shapeType = 'R';
    this->width = width;
    this->height = height;

    //set other attributes
    setPointsForCalc();
    setCalcValues();
    calculateOtherPoints();
}

//Accessors
//-----------------------------------------------------
float Rectangle::getWidth() {
    return width;
}

void Rectangle::setWidth(float value) {
    width = value;
}

float Rectangle::getHeight() {
    return height;
}

void Rectangle::setHeight(float value) {
    height = value;
}

//Methods
//-----------------------------------------------------

/**
 * Separates the coordinates in the vector, in the class Point
 * for easier calculations.
 * Values would be retrieved repeatedly otherwise.
 */
void Rectangle::setPointsForCalc() {
    x1 = points[0].getX();
    y1 = points[0].getY();
}


/**
 * Calculates the other 3 points of the rectangle give the initial point
 */
void Rectangle::calculateOtherPoints() {
    float tempX = x1;
    float tempY = y1;
    Point currPoint(tempX, tempY);

    //to the right of given point
    tempX += width;
    currPoint.setX(tempX);
    points.push_back(currPoint);

    //diagonally from the given point
    tempY += height;
    currPoint.setY(tempY);
    points.push_back(currPoint);

    //above the given point
    tempX -= width;
    currPoint.setX(tempX);
    points.push_back(currPoint);
}


/**
 * Calls all calculations in the same method.
 */
void Rectangle::setCalcValues() {
    calculatePerimeter();
    calculateArea();
}


/**
 * Calculates the perimeter of the rectangle using the
 * corresponding formula.
 */
void Rectangle::calculatePerimeter() {
    perimeter = (2 * width) + (2 * height);
}


/**
 * Calculates the area of the rectangle using the corresponding
 * formula.
 */
void Rectangle::calculateArea() {
    area = height * width;
}


/**
 * outputs the Rectangle's details both calculated and inputted
 * @return a string used for output of the Rectangle's details
 */
std::string Rectangle::print() {
    std::string output = "Rectangle: \n";
    output += "\t Width = " + std::to_string(width) + "\n";
    output += "\t Height = " + std::to_string(height) + "\n";
    output += "\t Points: {" + points[0].getCoord() + ", " + points[1].getCoord()
            + ", " + points[2].getCoord() + ", " + points[3].getCoord() + "}\n";
    output += "\t Perimeter = " + std::to_string(perimeter) + "\n";
    output += "\t Area = " + std::to_string(area) + "\n";

    return output;
}


