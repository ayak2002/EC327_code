//Point2D 
#include <iostream>
#include <cmath>
#include "Point2D.h"
#include "Vector2D.h"
using namespace std;


Point2D :: Point2D() 
{
    x = 0.0;
    y = 0.0;
}

Point2D :: Point2D(double in_x, double in_y)
{
    x = in_x;
    y = in_y;
}
double GetDistanceBetween(Point2D p1, Point2D p2)
{
    double x1 = p1.x;
    double y1 = p1.y;
    double x2 = p2.x;
    double y2 = p2.y;
    double distance = sqrt(pow((x2-x1),2)+pow((y2-y1),2));
    return distance;
}

ostream& operator<< (ostream& out, const Point2D& point)
{
    out << "(" << point.x << "," << point.y << ")";
    return out;
}

Point2D operator+ (const Point2D p1, const Vector2D v1)
{
    Point2D newPoint(p1.x+v1.x, p1.y+v1.y);
    return newPoint;
}

Vector2D operator- (const Point2D p1, const Point2D p2)
{
    Vector2D newPoint(p1.x-p2.x, p1.y-p2.y);
    return newPoint;
}
