//Student code
#include <iostream>
#include "Student.h"
#include <math.h>
#include <ctime>
using namespace std;

Student :: ~Student()
{
    cout << "Student destructed. " << endl;
}

Student :: Student() : GameObject('S')
{
    speed = 5;
    is_at_doctor = false;
    is_in_class = false;
    current_class = NULL;
    current_office = NULL;
    antibodies = 20;
    credits = 0;
    dollars = 0;
    assignments_to_buy = 0;
    vaccines_to_buy = 0;
    cout << "Student default constructed" << endl;
}

Student :: Student(char in_code) : GameObject(in_code)
{
    speed = 5;
    is_at_doctor = false;
    is_in_class = false;
    current_class = NULL;
    current_office = NULL;
    antibodies = 20;
    credits = 0;
    dollars = 0;
    assignments_to_buy = 0;
    vaccines_to_buy = 0;
    cout << "Student constructed" << endl;
    state = STOPPED;
}

Student :: Student(string in_name, int in_id, char in_code, unsigned int in_speed, Point2D in_loc) : GameObject(in_loc, in_id, in_code)
{
    name = in_name;
    speed = in_speed;
    is_at_doctor = false;
    is_in_class = false;
    current_class = NULL;
    current_office = NULL;
    antibodies = 20;
    credits = 0;
    dollars = 0;
    assignments_to_buy = 0;
    vaccines_to_buy = 0;
    cout << "Student constructed" << endl;
}

bool Student :: IsInfected()
{
    if(antibodies == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Student :: StartMoving(Point2D dest)
{
    if((current_class != NULL) && (location.x == current_class->GetLocation().x) && (location.y == current_class->GetLocation().y))
    //checks if the student is leaving a class
    {
        current_class->RemoveOneStudent();
        is_in_class = false;
        current_class = NULL;
    }
    if((current_office != NULL) && (location.x == current_office->GetLocation().x) && (location.y == current_office->GetLocation().y))
    //checks if the student is leaving an office
    {
        current_office->RemoveOneStudent();
        is_at_doctor = false;
        current_office = NULL;
    }
    SetupDestination(dest);
    if (GetDistanceBetween(dest, location) == 0) //if student is already at destination
    {
        cout << display_code << id_num << ": I'm already there. See?" << endl;
    }
    else if(antibodies == 0)
    {
        cout << display_code << id_num << ": I'm infected. I may move but you cannot see me." << endl;
    }
    else
    {
        cout << display_code << id_num << ": On my way." << endl;
        state = MOVING;
    }
}

void Student :: StartMovingToClass(ClassRoom* classr)
{
    if((current_class != NULL) && (current_class != classr))
    {
        if((current_class != NULL) && (location.x == current_class->GetLocation().x) && (location.y == current_class->GetLocation().y))
        //checks if the student is leaving a classroom
        {
            current_class->RemoveOneStudent();
            is_in_class = false;
            current_class = NULL;
        }
    }
    if((current_office != NULL) && (location.x == current_office->GetLocation().x) && (location.y == current_office->GetLocation().y))
    //checks if the student is leaving an office
    {
        current_office->RemoveOneStudent();
        is_at_doctor = false;
        current_office = NULL;
    }
    current_class = classr;
    SetupDestination(current_class->location);
    if(antibodies == 0) //if student is infected
    {
        cout << "I am infected so I can't move to class..." << endl;
    }
    else if(GetDistanceBetween(location, current_class->location) == 0) 
    {
        cout << display_code << id_num << ":  I am already at the Classroom! " << endl;
    }
    else
    {
        cout << display_code << id_num << ": On my way to class " << current_class->id_num << "." << endl;
        state = MOVING_TO_CLASS;
    }

}

void Student :: StartMovingToDoctor(DoctorsOffice* office)
{
    if((current_class != NULL) && (location.x == current_class->GetLocation().x) && (location.y == current_class->GetLocation().y))
    //checks if the student is leaving a classroom
    {
        current_class->RemoveOneStudent();
        is_in_class = false;
        current_class = NULL;
    }
    if((current_office != NULL) && (current_office != office))
    {
        if((current_office != NULL) && (location.x == current_office->GetLocation().x) && (location.y == current_office->GetLocation().y))
        //checks if the student is leaving an office
        {
            current_office->RemoveOneStudent();
            is_at_doctor = false;
            current_office = NULL;
        }
    }
    current_office = office;
    SetupDestination(current_office->location);
    if (antibodies == 0)
    {
        cout << "I am infected so I should have gone to the doctor's.." << endl;
    }
    else if(GetDistanceBetween(location, current_office->location) == 0)
    {
        cout << display_code << id_num << ": I am already at the Doctor's!" << endl;
    }
    else
    {
        cout << display_code << id_num << ": On my way to doctor's office " << current_office->id_num << endl;
        state = MOVING_TO_DOCTOR;
    }
}

void Student :: StartLearning(unsigned int num_assignments) 
{
    if(antibodies == 0)
    {
        cout << display_code << id_num << ": I am infected so no more school for me..." << endl;
    }
    else if(!is_in_class)
    {
        cout << display_code << id_num << ": I can only learn in a ClassRoom!" << endl;
    }
    else if(!(current_class->IsAbleToLearn(num_assignments, dollars, antibodies)))
    {
        cout << display_code << id_num << ": Not enough antibodies and/or money for school" << endl;
    }
    else if(current_class->num_assignments_remaining == 0)
    {
        cout << display_code << id_num << ": Cannot learn! This class has no more assignments!" << endl;
    }
    else
    {
        state = STUDYING_IN_CLASS;
        if((current_class->num_assignments_remaining) >= num_assignments) //if class has enough assignments
        {
            assignments_to_buy = num_assignments;
        }
        else
        {
            assignments_to_buy = current_class->num_assignments_remaining;
        }
         cout << display_code << id_num << ": Started to learn at the ClassRoom " << current_class->id_num << " with " 
        << assignments_to_buy <<" assignment(s)" << endl;
    }

}

void Student :: StartRecoveringAntibodies(unsigned int num_vaccines) 
{
    if (!is_at_doctor)
    {
        cout << display_code << id_num << ": I can only recover antibodies at a Doctor's Office!" << endl;
    }
    else if (!(current_office->CanAffordVaccine(num_vaccines, dollars)))
    {
        cout << display_code << id_num << ": Not enough money to recover antibodies. " << endl;
    }
    else if((current_office->num_vaccine_remaining)==0)
    {
        cout << display_code << id_num << ": Cannot recover! No vaccine remaining in this Doctor's Office." << endl;
    }
    else
    {
        state = RECOVERING_ANTIBODIES;
        vaccines_to_buy = current_office->DistributeVaccine(num_vaccines);
        cout << display_code << id_num << ": Started recovering " << vaccines_to_buy << " vaccines at Doctor's Office " << current_office ->id_num << endl;
    } 
}

void Student :: Stop()
{
    state = STOPPED;
    cout << display_code << id_num << ": Stopping..." << endl;
}


bool Student :: ShouldBeVisible()
{
    if(antibodies >= 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Student :: ShowStatus()
{
    cout << name << " status:";
    GameObject :: ShowStatus();
    switch(state)
    {
        case STOPPED:
            cout << "       Stopped" << endl;
            break;
        case MOVING:
            cout << "       Moving at speed of " << speed << " to destination " << destination << " at each step of " << delta << endl;
            break;
        case MOVING_TO_CLASS:
            cout << "       Heading to Classroom " << current_class->id_num << " at a speed of "<< speed << " at each step of " << delta << endl;
            break;
        case MOVING_TO_DOCTOR:
            cout << "       Heading to Doctor's Office " << current_office->id_num << " at a speed of " << speed << " at each step of " << delta << endl;
            break;
        case IN_CLASS:
            cout << "       Inside Classroom " << current_class->id_num << endl;
            break;
        case AT_DOCTORS:
            cout << "       Inside Doctor's Office " << current_office->id_num << endl;
            break;
        case STUDYING_IN_CLASS:
            cout << "       Studying in Classroom " << current_class->id_num << endl;
            break;
        case RECOVERING_ANTIBODIES:
            cout << "       Recovering antibodies in Doctor's Office " << current_office->id_num << endl;
            break;
    }
    cout << "       Antibodies: " << antibodies << endl;
    cout << "       Dollars: " << dollars << endl;
    cout << "       Credits: " << credits << endl;
}

bool Student :: Update() 
{
    unsigned int credits_gained;
    unsigned int antibodies_recovered;
    bool returnBool = false;
    switch(state)
    {
        case STOPPED:
            returnBool = false;
            break;
        case MOVING:
            dollars = dollars + GetRandomAmountOfDollars();
            UpdateLocation();
            if (antibodies >= 1)
            {
                antibodies = antibodies - 1;
                if(antibodies == 0)
                {
                    cout << name << " is out of antibodies and can't move" << endl;
                    state = INFECTED;
                }
            }
            if ((location.x == destination.x)&&(location.y == destination.y))
            {
                state = STOPPED;
                returnBool = true;
                break;
            }
            else
            {
                returnBool =  false;
                break;
            }
        case MOVING_TO_CLASS:
            dollars = dollars + GetRandomAmountOfDollars();
            UpdateLocation();
            if (antibodies >= 1)
            {
                antibodies = antibodies - 1;
                if(antibodies == 0)
                {
                    cout << name << " is out of antibodies and can't move" << endl;
                    state = INFECTED;
                }
            }
            if ((location.x == destination.x)&&(location.y == destination.y)) //if student arrived to class
            {
                state = IN_CLASS;
                is_in_class = true;
                current_class->AddOneStudent();
                returnBool = true;
                break;
            }
            else
            {
                returnBool = false;
                break;
            }
        case MOVING_TO_DOCTOR:
            dollars = dollars + GetRandomAmountOfDollars();
            UpdateLocation();
            if (antibodies >= 1)
            {
                antibodies = antibodies - 1;
                if(antibodies == 0)
                {
                    cout << name << " is out of antibodies and can't move" << endl;
                    state = INFECTED;
                }
            }
            if ((location.x == destination.x)&&(location.y == destination.y)) //if student arrived to doctor's
            { 
                state = AT_DOCTORS;
                is_at_doctor = true;
                current_office->AddOneStudent();
                returnBool = true;
                break;
            }
            else
            {
                returnBool = false;
                break;
            }
        case IN_CLASS:
            returnBool = false;
            break;
        case AT_DOCTORS:
            returnBool = false;
            break;
        case STUDYING_IN_CLASS:
            //cout << "      Studying in Classroom " << current_class->id_num << endl;
            antibodies -= assignments_to_buy * (current_class->antibody_cost_per_assignment);
            if(antibodies == 0)
            {
                cout << name << " is out of antibodies and can't move" << endl;
                state = INFECTED;
            }
            dollars -= assignments_to_buy * (current_class->dollar_cost_per_assignment);
            credits_gained = current_class->TrainStudents(assignments_to_buy); //number of credits the student has gained
            credits += credits_gained;
            cout << "** " << name << " completed " << assignments_to_buy << " assignments! **" << endl;
            cout << "** " << name << " gained " << credits_gained << " credits! **" << endl;
            state = IN_CLASS;
            returnBool = true;
            break;
        case RECOVERING_ANTIBODIES:
            antibodies_recovered = vaccines_to_buy * 5;
            antibodies += antibodies_recovered;
            dollars -= vaccines_to_buy * (current_office->dollar_cost_per_vaccine);
            cout << "** " << name << " recovered " << antibodies_recovered << " antibodies! **" << endl;
            cout << "** " << name << " bought " << vaccines_to_buy << " vaccines! **" << endl;
            state = AT_DOCTORS;
            returnBool = true;
            break;
    }
    return returnBool;
}

bool Student :: UpdateLocation()
{
    Vector2D newVec = destination - location;
    if ((fabs(newVec.x)<=fabs(delta.x))&&(fabs(newVec.y)<=fabs(delta.y)))
    {
        location.x = destination.x;
        location.y = destination.y;
        cout << display_code << id_num << ": I'm there!" << endl;
        return true;
    }
    else
    {
        location.x = location.x + delta.x;
        location.y = location.y + delta.y;
        cout << display_code << id_num << ": step..." << endl;
        return false;
    }
}

void Student :: SetupDestination(Point2D dest)
{
    destination.x = dest.x;
    destination.y = dest.y;
    delta = (destination - location) * (speed/GetDistanceBetween(destination, location));
}

double GetRandomAmountOfDollars()
{
    srand(time(NULL));
    double div = RAND_MAX / 2.0;
    return (rand() / div);
}

string Student :: GetName()
{
    return name;
}