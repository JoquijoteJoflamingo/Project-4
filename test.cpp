/**
 * test.cpp
 * Project UID 2e6ea4e086ea6a06753e819c30923369
 *
 * EECS 183
 * Project 4: CoolPics
 *
 * <#Name(s)#>
 * <#uniqname(s)#>
 *
 * Contains functions for testing classes in the project. 
 */

#include "Graphics.h"
#include "Circle.h"
#include "Color.h"
#include "Line.h"
#include "Point.h"
#include "Rectangle.h"
#include "Shape.h"
#include "Triangle.h"

#include <iostream>
#include <fstream>

using namespace std;


void test_Circle();
void test_Color();
void test_Line();
void test_Point();
void test_Rectangle();
void test_Triangle();
void test_Graphics();

void startTests() {
    test_Circle();
    test_Color();
    test_Line();
    test_Point();
    test_Triangle();
    test_Graphics();
    test_Rectangle();
    return;
}

void test_Point() {
    // test of default constructor
    Point p1;
    cout << "Expected: (0,0), actual: " << p1 << endl;
    
    // test of the non-default constructor
    Point p2(3, 9);
    cout << "Expected: (3,9), actual: " << p2 << endl;

    // test of member function: setX()
    p1.setX(5);
    // test of member function: setY()
    p1.setY(3);

    // test of member functions getX() and getY()
    cout << "Expected: (5,3), actual: ";
    cout << "( " << p1.getX()
         << ", " << p1.getY()
         << " )" << endl;
    
    return;
}

void test_Color() {
    Color color1;
    
    ifstream input_file;
    input_file.open("data2.txt");
    color1.read(input_file);
    cout << "Expected: (9,9,9), Actual: " << color1 << endl;
    
    
    // TO DO: test cases getRed etc.
    return;
}

void test_Graphics() {
    Graphics graphics1;
    Color color1(255, 0, 0);
    graphics1.setPixel(45, 2, color1);
    graphics1.writeFile("testGraphics.bmp");
}

void test_Line() {
    Line line1;
    char fill;
    string trash;
    
    
    ifstream input_file;
    input_file.open("data1.txt");
    
    input_file >> fill;
    while(!input_file.fail()) {
        if (fill == 'L') {
            line1.read(input_file);
            cout << fill << line1 << endl;
        }
        else {
            getline(input_file, trash);
        }
        input_file >> fill;
    }
}

void test_Triangle() {
    Triangle triangle1;
    char fill;
    string trash;
    
    
    ifstream input_file;
    input_file.open("data1.txt");
    
    input_file >> fill;
    while(!input_file.fail()) {
        if (fill == 'T') {
            triangle1.read(input_file);
            cout << fill << triangle1 << endl;
        }
        else {
            getline(input_file, trash);
        }
        input_file >> fill;
    }
}

void test_Circle() {
    Circle circle1;
    char fill;
    string trash;
    
    
    ifstream input_file;
    input_file.open("data1.txt");
    
    input_file >> fill;
    while(!input_file.fail()) {
        if (fill == 'C') {
            circle1.read(input_file);
            cout << fill << circle1 << endl;
        }
        else {
            getline(input_file, trash);
        }
        input_file >> fill;
    }
}

void test_Rectangle() {
    Rectangle rectangle1;
    char fill;
    string trash;
    
    
    ifstream input_file;
    input_file.open("data1.txt");
    
    input_file >> fill;
    while(!input_file.fail()) {
        if (fill == 'R') {
            rectangle1.read(input_file);
            cout << fill << rectangle1 << endl;
        }
        else {
            getline(input_file, trash);
        }
        input_file >> fill;
    }
}
