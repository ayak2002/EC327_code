#ifndef VIRUS_H
#define VIRUS_H
#include "Student.h"
#include <ctime>
#include <list>


class Virus : public GameObject
{
    enum VirusStates 
    {
        IN_ENVIRONMENT = 0,
        DEAD =           1,
        IN_STUDENT =     2
    };
    protected:
        double virulence;
        double resistance;
        bool variant;
        double energy;
        bool is_in_student;
        string name;
        Student * current_student;
        double speed;
        Point2D destination;
        Vector2D delta;
        bool GotToStudent;
        int step_count;
    public:
        Virus();
        Virus(string name, double virulence, double resistance, double energy, bool variant, int id, Point2D in_loc);
        virtual ~Virus();
        void infect(Student* s);
        bool get_variant();
        double get_virulence();
        double get_resistance();
        double get_energy();
        bool get_in_student();
        bool Update();
        void ShowStatus();
        bool IsAlive();
        void MoveToStudent(Student*);
        void SetupDestination(Point2D dest);
        bool UpdateLocation();
        Student* getMinDistance(list <Student*>); //returns a pointer to the student closest to the virus given a list of student pointers
};

#endif