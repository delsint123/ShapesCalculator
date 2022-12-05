/* --------------------------------------------------------
 *    File: Point.h
 *   Class: COP 3003, Fall 2022
 *     Dev: Delphine Sintamour
 * Purpose: Declaration of a Point class object
 * -------------------------------------------------------- */

//HEADER GUARD
#ifndef SHAPESCALCULATOR_POINT_H
#define SHAPESCALCULATOR_POINT_H

#include <string>

class Point {
private:
    float x;
    float y;

public:
    //Constructors
    //-----------------------------------------------------
    Point();
    Point(float Xvalue, float Yvalue);

    //Accessors
    //-----------------------------------------------------
    float getX();
    void setX(float value);

    float getY();
    void setY(float value);

    //Methods
    //-----------------------------------------------------
    std::string getCoord();
};

#endif //SHAPESCALCULATOR_POINT_H
