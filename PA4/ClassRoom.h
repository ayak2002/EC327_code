//ClassRoom header file
#ifndef CLASSROOM_H
#define CLASSROOM_H
#include "Building.h"
using namespace std;

class ClassRoom : public Building
{
    enum ClassRoomStates 
    {
        NOT_PASSED = 0,
        PASSED = 1
    };
    private:
        unsigned int num_assignments_remaining;
        unsigned int max_number_of_assignments;
        unsigned int antibody_cost_per_assignment;
        double dollar_cost_per_assignment;
        unsigned int credits_per_assignment;
    public:
        friend class Student;
        ClassRoom();
        virtual ~ClassRoom();
        ClassRoom(unsigned int, unsigned int, double, unsigned int, int, Point2D);
        double GetDollarCost(unsigned int);
        unsigned int GetAntibodyCost(unsigned int);
        unsigned int GetNumAssignmentsRemaining();
        bool IsAbleToLearn(unsigned int, double, unsigned int);
        unsigned int TrainStudents(unsigned int);
        bool Update();
        bool passed ();
        void ShowStatus();
};

#endif