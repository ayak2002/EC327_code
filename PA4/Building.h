//Building header file
#ifndef BUILDING_H
#define BUILDING_H
#include "GameObject.h"
using namespace std;


class Building : public GameObject
{
    private:
        unsigned int student_count = 0;
    public: 
        Building();
        virtual ~Building();
        Building(char, int, Point2D);
        void AddOneStudent();
        void RemoveOneStudent();
        void ShowStatus();
        bool ShouldBeVisible();
};

#endif