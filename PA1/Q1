//Preprocessor directives
#include <iostream>
#include <iomanip> //needed for the setprecision() function
#include <cmath> //needed for the math function such as sqrt() and pow()
using namespace std;


//function prototypes
void getCoordinates(float*, float*, float*, float*, float*, float*); /*gets the coordinates from the user
                                                                      given the location of the variables
                                                                      corresponding to the coordinates*/
float findA(float, float); //finds a of the line ax+by+c=0 given x1 and x2.
float findB(float, float); //finds b of the line ax+by+c=0 given y1 and y2.
float findC(float, float, float, float); // finds c of the line ax+by+c=0 given x1, y1, x2,and y2.
float findDistance(float, float , float, float, float); /* finds the shortest distance between a line
                                                           ax+by+c=0 and a point (x3,y3) given a, b, c,
                                                           x3 and y3.*/
void dispDistance(float, float, float, float, float, float, float); //displays the shortest distance with a precision of 2.



//Main function
int main()
{
    float x1, y1, //Variable declarations: point 1 coordinates
          x2, y2, //point 2 coordinates
          x3, y3, //point 3 coordinates
          a, b, c,//line equation coefficients
          dist;
    getCoordinates(&x1, &y1, &x2, &y2, &x3, &y3); //Function calls
    a=findA(y1, y2); 
    b=findB(x1, x2);
    c=findC(x1, y1, x2, y2);
    dist=findDistance(a, b, c, x3, y3);
    dispDistance(x1, y1, x2, y2, x3, y3, dist);
    return 0;
}
    


//Function definitions
void getCoordinates(float *x1, float *y1, float *x2, float *y2, float *x3, float *y3)
{
    cout << "Enter three x, y coordinates: " << endl; //asks the user for coordinates of three points
    cin >> *x1 >> *y1 >> *x2 >> *y2 >> *x3 >> *y3; //puts the coordinates in the variables from cin
}


float findA(float y1, float y2)
{
    return y1-y2; //finds coefficient a of line equation ax+by+c=0
}


float findB(float x1, float x2)
{
    return x2-x1; //finds coefficient b of line equation ax+by+c=0
}


float findC(float x1, float y1, float x2, float y2)
{
    return (x1*y2)-(x2*y1); //finds coefficient c of line equation ax+by+c=0
}


float findDistance(float a, float b, float c, float x, float y)
{
    float distance=(abs((a*x)+(b*y)+c))/(sqrt(pow(a,2)+pow(b,2))); //uses formula to find the distance
    return distance;
}


void dispDistance(float x1, float y1, float x2, float y2, float x3, float y3, float dist)
{
    cout << "The shortest distance for (" << x3 << "," << y3 << ") to the line composed " <<
    "of (" << x1 << "," << y1 << ") and (" << x2 << "," << y2 << ") is " << fixed << setprecision(2) <<
    dist<< "." <<endl;  //prints out the result for three given points
}

