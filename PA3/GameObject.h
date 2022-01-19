//GameObject header file
#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include "Point2D.h"
using namespace std;

class GameObject
{   
    protected:
        Point2D location;
        int id_num;
        char display_code;
        int state;
    public:
        friend class Student;
        GameObject(char);
        virtual ~GameObject();
        GameObject(Point2D, int, char);
        Point2D GetLocation();
        int GetId();
        int GetState();
        virtual void ShowStatus();
        virtual bool Update() = 0;
        virtual bool ShouldBeVisible() = 0;
        void DrawSelf(char *);
};

#endif