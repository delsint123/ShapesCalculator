/* --------------------------------------------------------
 *    File: Line.h
 *   Class: COP 3003, Fall 2022
 *     Dev: Delphine Sintamour
 * Purpose: Declaration of a Line class object
 * -------------------------------------------------------- */

#ifndef SHAPESCALCULATOR_LINE_H
#define SHAPESCALCULATOR_LINE_H

#include "Shapes.h"

class Line : public Shape {
private:
    float length;
    float slope;
    float angle;
    float angle2;

    //for calculations
    float x1;
    float y1;
    float x2;
    float y2;

public:
    //Constructors
    //-----------------------------------------------------
    Line();
    Line(std::vector<Point> points);

    //Accessors
    //-----------------------------------------------------
    float getLength();

    float getAngle();
    void setAngle(float value);

    float getSlope();

    //Methods
    //-----------------------------------------------------
    void setPointsForCalc();
    void setCalcValues();
    void calculateLength();
    void calculateSlope();
    void calculateAngle();

    std::string print();

};

#endif //SHAPESCALCULATOR_LINE_H
