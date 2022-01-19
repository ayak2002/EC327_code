//DoctorsOffice code
#include <iostream>
#include "DoctorsOffice.h"
#include "Building.h"
using namespace std;


DoctorsOffice :: ~DoctorsOffice()
{
    cout << "DoctorsOffice destructed. " << endl;
}

DoctorsOffice :: DoctorsOffice() : Building()
{
    display_code = 'D';
    vaccine_capacity = 100;
    num_vaccine_remaining = vaccine_capacity;
    dollar_cost_per_vaccine = 5;
    state = VACCINE_AVAILABLE;
    cout << "DoctorsOffice default constructed" << endl;
}

DoctorsOffice :: DoctorsOffice (int in_id, double vaccine_cost, unsigned int vaccine_cap, Point2D in_loc) : Building('D', in_id, in_loc)
{
    dollar_cost_per_vaccine = vaccine_cost;
    vaccine_capacity = vaccine_cap;
    state = VACCINE_AVAILABLE;
    num_vaccine_remaining = vaccine_capacity;
    cout << "DoctorsOffice constructed" << endl;
}

bool DoctorsOffice :: HasVaccine()
{
    if(num_vaccine_remaining >= 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

unsigned int DoctorsOffice :: GetNumVaccineRemaining()
{
    return num_vaccine_remaining;
}

bool DoctorsOffice :: CanAffordVaccine(unsigned int vaccine, double budget)
{
    if(budget >= (vaccine*dollar_cost_per_vaccine)) //checks if student has enough money
    {
        return true;
    }
    else
    {
        return false;
    }
}

double DoctorsOffice :: GetDollarCost(unsigned int vaccine)
{
    return vaccine*dollar_cost_per_vaccine;
}

unsigned int DoctorsOffice :: DistributeVaccine(unsigned int vaccine_needed)
{
    if(num_vaccine_remaining >= vaccine_needed) //if there are enough vaccines in the office
    {
        num_vaccine_remaining -= vaccine_needed;
        return vaccine_needed;
    }
    else
    {
        vaccine_needed = num_vaccine_remaining; //if there aren't enough vaccines
        num_vaccine_remaining -= vaccine_needed;
        return vaccine_needed;
    }
}

bool DoctorsOffice :: Update()
{
    static bool vaccineDepleted = false;
    static int count = 0;
    if (num_vaccine_remaining == 0)
    {
        state = NO_VACCINE_AVAILABLE;
        display_code = 'd';
        if ((vaccineDepleted == false) && (count == 0)) //vaccineDepleted is only set to true when the office runs out of vaccines
        {
            vaccineDepleted = true;
            cout << "DoctorsOffice " << id_num << " has ran out of vaccine" << endl;
            count ++;
        }
        else
        {
            vaccineDepleted = false;
        }
    }
    return vaccineDepleted;
}

void DoctorsOffice :: ShowStatus()
{
    cout << "DoctorsOffice Status: ";
    Building :: ShowStatus();
    cout << "       Dollars per vaccine: " << dollar_cost_per_vaccine << endl;
    cout << "       has " << num_vaccine_remaining << " vaccine(s) remaining." << endl;
}

