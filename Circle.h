/* --------------------------------------------------------
 *    File: Circle.h
 *   Class: COP 3003, Fall 2022
 *     Dev: Delphine Sintamour
 * Purpose: Declaration of a Circle class object
 * -------------------------------------------------------- */

#ifndef SHAPESCALCULATOR_CIRCLE_H
#define SHAPESCALCULATOR_CIRCLE_H

#include "Shapes.h"

class Circle : public Shape {
private:
    float radius;
    float diameter;
    float circumference;
    float area;

    //for calculations
    float x1;
    float y1;

public:
    //Constructors
    //-----------------------------------------------------
    Circle();
    Circle(std::vector<Point> points, float radius);

    //Accessors
    //-----------------------------------------------------
    float getRadius();
    void setRadius(float value);

    //Methods
    //-----------------------------------------------------
    void setPointsForCalc();
    void setCalcValues();
    void calculateDiameter();
    void calculateCircumference();
    void calculateArea();

    std::string print();
};

#endif //SHAPESCALCULATOR_CIRCLE_H
