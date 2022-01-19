//Vector2D
#include <iostream>
#include "Vector2D.h"
using namespace std;

Vector2D :: Vector2D() 
{
    x = 0.0;
    y = 0.0;
}

Vector2D :: Vector2D(double in_x, double in_y)
{
    x = in_x;
    y = in_y;
}

Vector2D operator* (Vector2D v, double d)
{
    Vector2D newVector((v.x)*d, (v.y)*d);
    return newVector;
}

Vector2D operator/ (Vector2D v, double d)
{
    if (d==0)
    {
        return v;
    }
    else
    {
        Vector2D newVector((v.x)/d, (v.y)/d);
        return newVector;
    }
}

ostream& operator<< (ostream& out, const Vector2D& v)
{
    out << "<" << v.x << "," << v.y << ">";
    return out;
}
