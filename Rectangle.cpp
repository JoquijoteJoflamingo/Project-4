/**
 * Rectangle.cpp
 * Project UID 2e6ea4e086ea6a06753e819c30923369
 *
 * EECS 183
 * Project 4: CoolPics
 *
 * <#Name(s)#>
 * <#uniqname(s)#>
 *
 * <#Description#>
 */

#include "Rectangle.h"
#include "Line.h"
#include "Triangle.h"
#include "Graphics.h"
#include <algorithm>
using namespace std;

// TODO: implement three constructors, setStart, getStart, setEnd, getEnd,
//       setColor, setColorTopLeft, getColorTopLeft, setColorTopRight,
//       getColorTopRight, setColorBottomRight, getColorBottomRight,
//       setColorBottomLeft, getColorBottomLeft, read, write.
Rectangle::Rectangle() {
    
}

/**
 * Requires: Nothing.
 * Modifies: start, end, colorTopLeft, colorTopRight, colorBottomRight,
 *           colorBottomLeft.
 * Effects:  Overloaded contructor. Sets start, end and single color.
 */
Rectangle::Rectangle(Point pt1, Point pt2, Color color) {
    
}

/**
 * Requires: Nothing.
 * Modifies: start, end, colorTopLeft, colorTopRight, colorBottomRight,
 *           colorBottomLeft.
 * Effects:  Overloaded contructor. Sets start, end and four colors.
 */
Rectangle::Rectangle(Point pt1, Point pt2, Color cTopLeft, Color cTopRight,
                     Color cBottomRight, Color cBottomLeft) {
    
}


void Rectangle::setStart(Point pt) {
    
}


Point Rectangle::getStart() {
    
    return start;
}


void Rectangle::setEnd(Point pt) {
    
}


Point Rectangle::getEnd() {
    
    return end;
}


void Rectangle::setColor(Color color) {
    
    
}


void Rectangle::setColorTopLeft(Color color) {
    
}

    
Color Rectangle::getColorTopLeft() {
    return colorTopLeft;
}

/**
 * Requires: Nothing.
 * Modifies: colorTopRight.
 * Effects:  Sets top right color of rectangle.
 */
void Rectangle::setColorTopRight(Color color) {
    
}

/**
 * Requires: Nothing.
 * Modifies: Nothing.
 * Effects:  Returns top right color of rectangle.
 */
Color Rectangle::getColorTopRight() {
    
    return colorTopRight;
}

/**
 * Requires: Nothing.
 * Modifies: colorBottomRight.
 * Effects:  Sets bottom rihgt color of rectangle.
 */
void Rectangle::setColorBottomRight(Color color) {
    
}

/**
 * Requires: Nothing.
 * Modifies: Nothing.
 * Effects:  Returns bottom right color of rectangle.
 */
Color Rectangle::getColorBottomRight() {
    
    return colorBottomRight;
}

/**
 * Requires: Nothing.
 * Modifies: colorBottomLeft.
 * Effects:  Sets bottom left color of rectangle.
 */
void Rectangle::setColorBottomLeft(Color c) {
    
}

/**
 * Requires: Nothing.
 * Modifies: Nothing.
 * Effects:  Returns bottom left color of rectangle.
 */
Color Rectangle::getColorBottomLeft() {
    
    return colorBottomLeft;
}

/**
 * Requires: ins is in good state.
 * Modifies: ins, start, end, colorTopLeft, colorTopRight,
 *           colorBottomRight, colorBottomLeft.
 * Effects:  Reads rectangle in forms
 *           start end color
 *           start end cTopLeft cTopRight cBottomRight cBottomLeft
 */
void Rectangle::read(istream& ins) {
    
}

/**
 * Requires: outs is in good state.
 * Modifies: outs.
 * Effects:  Writes rectangle in form
 *           start end cTopLeft cTopRight cBottomRight cBottomLeft
 */
void Rectangle::write(ostream& outs) {
    
}





// Your code goes above this line.
// Don't change the implementations below!

istream& operator >> (istream& ins, Rectangle& rectangle)
{
    rectangle.read(ins);
    return ins;
}

ostream& operator << (ostream& outs, Rectangle rectangle)
{
    rectangle.write(outs);
    return outs;
}

void Rectangle::draw(Graphics & drawer)
{
    // four points of rectangles
    Point topLeft = start;
    Point topRight(end.getX(), start.getY());
    Point bottomRight = end;
    Point bottomLeft(start.getX(), end.getY());

    // center point and color by averaging
    Point center((start.getX() + end.getX()) / 2,
                 (start.getY() + end.getY()) / 2);
    Color colorCenter((colorTopLeft.getRed() + colorTopRight.getRed() +
                       colorBottomRight.getRed() +
                       colorBottomLeft.getRed()) / 4,
                      (colorTopLeft.getGreen() + colorTopRight.getGreen() +
                       colorBottomRight.getGreen() +
                       colorBottomLeft.getGreen()) / 4,
                      (colorTopLeft.getBlue() + colorTopRight.getBlue() +
                       colorBottomRight.getBlue() +
                       colorBottomLeft.getBlue()) / 4);

    // four triangles to represent rectangle
    Triangle top(topLeft, colorTopLeft, topRight, colorTopRight,
                 center, colorCenter);
    Triangle bottom(bottomLeft, colorBottomLeft, bottomRight, colorBottomRight,
                    center, colorCenter);
    Triangle left(topLeft, colorTopLeft, bottomLeft, colorBottomLeft,
                  center, colorCenter);
    Triangle right(topRight, colorTopRight, bottomRight, colorBottomRight,
                   center, colorCenter);
    top.draw(drawer);
    bottom.draw(drawer);
    left.draw(drawer);
    right.draw(drawer);
}
