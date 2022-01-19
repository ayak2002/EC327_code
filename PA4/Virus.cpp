#include <iostream>
#include "Virus.h"

Virus :: Virus() : GameObject('V')
{
    this->virulence = 5;
    this->resistance = 2;
    this->variant = false;
    this->energy = 10;
    this->is_in_student = false;
    this->state = IN_ENVIRONMENT;
    this->speed = 2;
    this->step_count = 0;
    this->GotToStudent = false;
    cout << "Virus constructed" << endl;
}

Virus :: Virus(string name, double virulence, double resistance, double energy,
bool variant, int id, Point2D in_loc) : GameObject(in_loc, id, 'V')
{
    this->name = name;
    this->virulence = virulence;
    this->resistance = resistance;
    this->energy = energy;
    this->variant = variant;
    this->is_in_student = false;
    this->state = IN_ENVIRONMENT;
    this->speed = 2;
    this->GotToStudent = false;
    cout << "Virus constructed" << endl;
}

Virus :: ~Virus()
{
    cout << "Virus destructed." << endl;
}

void Virus :: infect(Student * studentPtr)
{
    studentPtr->setAntibodies(0);
    return;
}

bool Virus :: get_variant()
{
    return variant;
}

double Virus :: get_virulence()
{
    return virulence;
}

double Virus :: get_resistance()
{
    return resistance;
}

double Virus :: get_energy()
{
    return energy;
}

bool Virus :: get_in_student()
{
    return is_in_student;
}

void Virus :: MoveToStudent(Student* studentPtr)
{
    if(IsAlive())
    {
        destination = studentPtr->GetLocation();
        SetupDestination(destination);
        if(UpdateLocation()) //if virus is within a distance 1 of the student
        {
            GotToStudent = true;
            if((studentPtr->getAntibodies() <= resistance) && (studentPtr->getAntibodies() != 0)) //if student has less antibodies than resistance, student gets infected
            {
                infect(studentPtr);
                is_in_student = true;
                cout << name << " virus has infected " << studentPtr->GetName() << "!" << endl;
                resistance = resistance + 2;
            }
            else //else, student loses 2 antibodies
            {
                if(studentPtr->getAntibodies() != 0)
                {
                    cout << studentPtr->GetName() << " is resistant to " << name << "!" << endl;
                    studentPtr->setAntibodies(studentPtr->getAntibodies() - 2);
                }
            }
        }
        else //else, virus moves towards student
        {
            GotToStudent = false;
            cout << name << " virus moving towards " << studentPtr->GetName() << endl;
        }
    }
}

bool Virus :: Update()
{
    static int srand(time(NULL));
    if(GotToStudent)
    {
        GotToStudent = false;
        if(is_in_student)
        {
            energy = energy + 10;
            state = IN_STUDENT;
        }
        else
        {
            state = IN_ENVIRONMENT;
        }
        double div = RAND_MAX / 20.0;
        location.x = (rand() / div); //if the virus gets to a student, this student will always be closest to the virus so
        location.y = (rand() / div); //we place the virus in another random location to make sure it does not stop moving
        cout << name <<" virus moved away from student" << endl;
        return true;
    }
    if(energy >=1)
    {
        step_count ++;
        if (step_count == 2)
        {
            energy--;
            if (energy == 0)
            {
                state = DEAD;
                cout << name << " virus has ran out of energy and is now dead" << endl;
                return true;
            }
            else
            {
                state = IN_ENVIRONMENT;
            }
            step_count = 0;
        }
    }
    return false;
}

void Virus :: ShowStatus()
{
    cout << name << " status:";
    GameObject :: ShowStatus();
    switch(state)
    {
        case (IN_ENVIRONMENT):
            cout << "       Virus moving in environment" << endl;
            break;
        case (DEAD):
            cout << "       Virus dead" << endl;
            break;
        case(IN_STUDENT):
            cout << "       Virus has infected a student" << endl; //only displayed when student is first infected, 
            break;                                                 //after that student is not visible and virus is back to the environment
    }
    is_in_student = false;
    cout << "       Virulence: " << virulence << endl;
    cout << "       Resistance: " << resistance << endl;
    cout << "       Energy: " << energy << endl;
}

bool Virus :: IsAlive()
{
    if(energy != 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Virus :: SetupDestination(Point2D dest)
{
    destination.x = dest.x;
    destination.y = dest.y;
    delta = (destination - location) * (speed/GetDistanceBetween(destination, location));
}

bool Virus :: UpdateLocation()
{
    if(GetDistanceBetween(location, destination) <= 2)
    {
        return true;
    }
    else
    {
        location.x = location.x + delta.x;
        location.y = location.y + delta.y;
        return false;
    }
}

Student* Virus :: getMinDistance(list <Student*> studentList)
{
    Student* minPtr = *(studentList.begin());
    double minDistance = GetDistanceBetween(minPtr->GetLocation(), location);
    for (list <Student *> ::  iterator it = studentList.begin(); it != studentList.end(); it++)
    {
        if (GetDistanceBetween((*it)->GetLocation(), location) <= minDistance)
        {
            minPtr = (*it);
        }
    }
    return minPtr;
}
