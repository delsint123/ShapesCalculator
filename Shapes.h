/* --------------------------------------------------------
 *    File: Shapes.h
 *   Class: COP 3003, Fall 2022
 *     Dev: Delphine Sintamour
 * Purpose: Declaration of a Shape class object
 * -------------------------------------------------------- */

#ifndef SHAPESCALCULATOR_SHAPES_H
#define SHAPESCALCULATOR_SHAPES_H

#include <string>
#include <vector>
#include "Point.h"

class Shape {

protected:
    std::vector<Point> points;
    char shapeType;

private:

public:
    //Constructors
    //-----------------------------------------------------
    Shape();
    Shape(std::vector<Point> points, char shapeType);

    //Accessors
    //-----------------------------------------------------
    std::vector<Point> getPoints();
    void setPoints(float xValue, float yValue);

    char getShapeType();
    void setShapeType(char character);

    //Methods
    //-----------------------------------------------------
    virtual std::string print();

};


#endif //SHAPESCALCULATOR_SHAPES_H
