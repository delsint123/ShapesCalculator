/* --------------------------------------------------------
 *    File: shapeCalculator.cpp
 *   Class: COP 3003, Fall 2022
 *     Dev: Delphine Sintamour
 * Purpose: Calculator that returns dimensions of user generated
 *          shapes
 * -------------------------------------------------------- */

#include <iostream>
#include <vector>
#include "Point.h"
#include "Shapes.h"
#include "Line.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Triangle.h"

//function declarations
//---------------------------------------------------------
char chooseShape();
Point setPoint();
Line* createLine();
Rectangle* createRectangle();
Circle* createCircle();
Triangle* createTriangle();
void print(std::vector<Shape*> shapes);


int main() {
    std::vector<Shape*> shapes;     //holds the addresses of shapes to be generated
    bool run = true;

    do {
        char shapeType = chooseShape();

        switch (shapeType) {
            case 'L':
                shapes.push_back(createLine());
                break;
            case 'R':
                shapes.push_back(createRectangle());
                break;
            case 'C':
                shapes.push_back(createCircle());
                break;
            case 'T':
                shapes.push_back(createTriangle());
                break;
            case 'P':
                print(shapes);
                break;
            case 'E':
                run = false;
                break;
            default:
                std::cout << "Not a valid character! \n Try Again. \n";
        }
    }while(run);

    return 0;
}


//function definitions
//---------------------------------------------------------

/**
 * Asks user fpr type of shape to be generated
 * @return type of shape
 */
char chooseShape() {
    std::cout << "Enter 1st Character: \n";
    std::cout << "\t Line \n";
    std::cout << "\t Rectangle \n";
    std::cout << "\t Circle \n";
    std::cout << "\t Triangle \n";
    std::cout << "\t Print \n";
    std::cout << "\t Exit \n";

    char type;
    std::cin >> type;
    type = toupper(type);      //ensure the same case

    return type;
};


/**
 * Asks user for a point to create shape chosen
 * @return a new Point(user-defined class)
 */
Point setPoint() {
    float tempX;
    float tempY;

    std::cout << "Enter a point (x space y enter): ";
    std::cin >> tempX >> tempY;

    Point currPoint(tempX, tempY);
    return currPoint;
};


/**
 * Creates Line and generates values for a line
 * @return a ptr to the newly generated line which is stored in a vector
 */
Line* createLine() {
    std::vector<Point> points;

    std::cout << "-----------------------------------------------------------\n";
    std::cout << "Enter two points for a line... \n";

    points.push_back(setPoint());
    points.push_back(setPoint());
    std::cout << "\n-----------------------------------------------------------\n";

    Line *ptrLine = new Line(points);

    return ptrLine;
};


/**
 * Creates Rectangle and generates values for a Rectangle
 * @return a ptr to the newly generated Rectangle which is stored in a vector
 */
Rectangle* createRectangle() {
    std::vector<Point> points;

    std::cout << "-----------------------------------------------------------\n";
    std::cout << "Enter one point for a rectangle... \n";
    points.push_back(setPoint());

    float width;
    float height;
    std::cout << "Enter a width: ";
    std::cin >> width;
    std::cout << "Enter a height: ";
    std::cin >> height;
    std::cout << "\n-----------------------------------------------------------\n";

    Rectangle *ptrRect = new Rectangle(points, width, height);

    return ptrRect;
};


/**
 * Creates Circle and generates values for a Circle
 * @return a ptr to the newly generated Circle which is stored in a vector
 */
Circle* createCircle() {
    std::vector<Point> points;

    std::cout << "-----------------------------------------------------------\n";
    std::cout << "Enter a points for center of a circle... \n";
    points.push_back(setPoint());

    float radius;
    std::cout << "Enter a radius: ";
    std::cin >> radius;
    std::cout << "\n-----------------------------------------------------------\n";

    Circle *ptrCirc = new Circle(points, radius);

    return ptrCirc;
};


/**
 * Creates Triangle and generates values for a Triangle
 * @return a ptr to the newly generated Triangle which is stored in a vector
 */
Triangle *createTriangle() {

    std::vector<Point> points;

    std::cout << "-----------------------------------------------------------\n";
    std::cout << "Enter a 3 points for a triangle... \n";
    points.push_back(setPoint());
    points.push_back(setPoint());
    points.push_back(setPoint());
    std::cout << "\n-----------------------------------------------------------\n";

    Triangle *ptrTri = new Triangle(points);

    return ptrTri;
}


/**
 * Outputs all shapes that have been generated
 * @param shapes: a vector of pointers to generated shapes
 */
void print(std::vector<Shape*> shapes) {

    std::cout << "-----------------------------------------------------------\n";
    std::cout << "-------------------- Start Shapes List --------------------\n";

    //loop through the vector of pointers
    for(auto & shape : shapes) {
        std::cout << shape->print() << std::endl;
        std::cout << "-  -  -  -  -  -  -  -  -  -  -  -  -  -  -\n";
    }

    std::cout << "--------------------- End Shapes List ---------------------\n";
    std::cout << "-----------------------------------------------------------\n";
}



