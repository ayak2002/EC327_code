//ClassRoom code
#include <iostream>
#include "ClassRoom.h"
#include "Building.h"
using namespace std;



ClassRoom :: ~ClassRoom()
{
    cout << "ClassRoom destructed. " << endl;
}

ClassRoom :: ClassRoom() : Building()
{
    display_code = 'C';
    state = NOT_PASSED;
    max_number_of_assignments = 10;
    num_assignments_remaining = max_number_of_assignments;
    antibody_cost_per_assignment = 1;
    dollar_cost_per_assignment = 1.0;
    credits_per_assignment = 2;
    cout << "ClassRoom default constructed" << endl;
}

ClassRoom :: ClassRoom(unsigned int max_assign, unsigned int antibody_cost, double dollar_cost, 
unsigned int crd_per_assign, int in_id, Point2D in_loc) :Building('C', in_id, in_loc)
{
    display_code = 'C';
    state = NOT_PASSED;
    id_num = in_id;
    location = in_loc;
    max_number_of_assignments = max_assign;
    num_assignments_remaining = max_number_of_assignments;
    antibody_cost_per_assignment = antibody_cost;
    credits_per_assignment = crd_per_assign;
    dollar_cost_per_assignment = dollar_cost;
    cout << "ClassRoom constructed" << endl;
}

double ClassRoom :: GetDollarCost(unsigned int unit_qty)
{
    return unit_qty * dollar_cost_per_assignment;
}

unsigned int ClassRoom :: GetAntibodyCost(unsigned int unit_qty)
{
    return unit_qty * antibody_cost_per_assignment;
}

unsigned int ClassRoom :: GetNumAssignmentsRemaining()
{
    return num_assignments_remaining;
}

 bool ClassRoom :: IsAbleToLearn(unsigned int unit_qty, double budget, unsigned int antibodies)
 {
     if((budget >= (unit_qty * dollar_cost_per_assignment)) && (antibodies >= (unit_qty * antibody_cost_per_assignment)))
     {
         return true;
     }
     else 
     {
         return false;
     }
 }

 unsigned int ClassRoom :: TrainStudents(unsigned int assignment_units)
 {
     if(num_assignments_remaining >= assignment_units) //if there are enough assignments remaining
     {
        num_assignments_remaining -= assignment_units;
        return assignment_units * credits_per_assignment;
     }
     else
     {
        assignment_units = num_assignments_remaining; //if there aren't enough assignments remaining
        num_assignments_remaining -= assignment_units;
        return assignment_units * credits_per_assignment;
     }
 }

bool ClassRoom :: Update()
{
    static bool hasPassed = false;
    static int count = 0;
    if(num_assignments_remaining == 0)
    {
        state = PASSED;
        display_code = 'c';
        if ((hasPassed == false) && (count == 0)) //only sets hasPassed to true when the classRoom is passed
        {
            cout << display_code << id_num << " has been passed" << endl;
            hasPassed = true;
            count++;
        }
        else
        {
            hasPassed = false;
        }
    }
    return hasPassed;
}

bool ClassRoom :: passed()
{
    if(num_assignments_remaining == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void ClassRoom :: ShowStatus()
{
    cout << "ClassRoom Status: ";
    Building :: ShowStatus();
    cout << "       Max number of assignments: " << max_number_of_assignments << endl;
    cout << "       Antibody cost per assignment: " << antibody_cost_per_assignment << endl;
    cout << "       Dollar cost per assignment: " << dollar_cost_per_assignment << endl;
    cout << "       Credits per assignment: " << credits_per_assignment << endl;
    cout << "       " << num_assignments_remaining << " assignment(s) are remaining for this ClassRoom" << endl;
}