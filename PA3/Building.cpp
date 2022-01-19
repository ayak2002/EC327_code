//Building code
#include <iostream>
#include "Building.h"
using namespace std;

Building :: Building() : GameObject('B')
{
    student_count = 0;
    cout << "Building default constructed" << endl;
}

Building :: ~Building()
{
    cout << "Building destructed" << endl;
}

Building :: Building(char in_code, int in_Id, Point2D in_loc) : GameObject(in_loc, in_Id, in_code)
{
    student_count = 0;
    cout << "Building constructed" << endl;
}

void Building :: AddOneStudent()
{
    student_count++;
    return;
}

void Building :: RemoveOneStudent()
{
    student_count--;
    return;
}

void Building :: ShowStatus()
{
    cout << display_code << id_num << " located at " << location << endl;
    cout << "       " << student_count;
    if (student_count == 1) //checks if there are more than 1 student to have correct output format
    {
        cout << " student is located in this building" << endl;
    }
    else
    {
        cout << " students are located in this building" << endl;
    }
}

bool Building :: ShouldBeVisible()
{
    return true;
}
