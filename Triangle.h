/* --------------------------------------------------------
 *    File: Triangle.h
 *   Class: COP 3003, Fall 2022
 *     Dev: Delphine Sintamour
 * Purpose: Declaration of a Triangle class object
 * -------------------------------------------------------- */

#ifndef SHAPESCALCULATOR_TRIANGLE_H
#define SHAPESCALCULATOR_TRIANGLE_H

#include "Shapes.h"
#include "Line.h"

class Triangle : public Shape {
private:
    Line lineC;          //line a to b;
    Line lineA;          //line b to c;
    Line lineB;          //line c to a;
    float perimeter;
    float area;

public:
    //Constructors
    //-----------------------------------------------------
    Triangle();
    Triangle(std::vector<Point> points);

    //Accessors
    //-----------------------------------------------------

    //Methods
    //-----------------------------------------------------
    void calculateLines();
    void setCalcValues();
    void calculatePerimeter();
    void calculateArea();
    void calculateAngles();              //new angles will need to be set
    void calculateAngleBtwn2Lines(Line &currLine, float slope1, float slope2);

    std::string print();
};

#endif //SHAPESCALCULATOR_TRIANGLE_H
