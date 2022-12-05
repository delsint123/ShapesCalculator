/* --------------------------------------------------------
 *    File: Rectangle.h
 *   Class: COP 3003, Fall 2022
 *     Dev: Delphine Sintamour
 * Purpose: Declaration of a Rectangle class object
 * -------------------------------------------------------- */

#ifndef SHAPESCALCULATOR_RECTANGLE_H
#define SHAPESCALCULATOR_RECTANGLE_H

#include "Shapes.h"

class Rectangle : public Shape {
private:
    float width;
    float height;
    float perimeter;
    float area;

    //for calculations
    float x1;
    float y1;

public:
    //Constructors
    //-----------------------------------------------------
    Rectangle();
    Rectangle(std::vector<Point> points, float width, float height);

    //Accessors
    //-----------------------------------------------------
    float getWidth();
    void setWidth(float value);

    float getHeight();
    void setHeight(float value);

    //Methods
    //-----------------------------------------------------
    void setPointsForCalc();
    void calculateOtherPoints();              //these must be calculated and added to points vector
    void setCalcValues();
    void calculatePerimeter();
    void calculateArea();

    std::string print();
};

#endif //SHAPESCALCULATOR_RECTANGLE_H
