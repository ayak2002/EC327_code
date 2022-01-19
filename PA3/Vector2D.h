//Vector2D header file
#ifndef VECTOR2D_H
#define VECTOR2D_H
using namespace std;

class Vector2D
{
    public:
            double x;
            double y;
            Vector2D(); 
            Vector2D(double, double);
};

Vector2D operator* (Vector2D, double);
Vector2D operator/ (Vector2D, double);
ostream& operator<< (ostream&, const Vector2D&);

#endif