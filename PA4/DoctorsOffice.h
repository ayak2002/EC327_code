//DoctorsOffice header file
#ifndef DOCTORSOFFICE_H
#define DOCTORSOFFICE_H
#include "Building.h"
using namespace std;


class DoctorsOffice : public Building
{
    enum DoctorsOfficeStates 
    {
        VACCINE_AVAILABLE = 0,
        NO_VACCINE_AVAILABLE = 1
    };
    private:
        unsigned int vaccine_capacity;
        unsigned int num_vaccine_remaining; 
        double dollar_cost_per_vaccine;
    public:
        friend class Student;
        DoctorsOffice();
        virtual ~DoctorsOffice();
        DoctorsOffice (int, double, unsigned int, Point2D);
        bool HasVaccine();
        unsigned int GetNumVaccineRemaining();
        bool CanAffordVaccine(unsigned int vaccine, double budget);
        double GetDollarCost(unsigned int vaccine);
        unsigned int DistributeVaccine(unsigned int vaccine_needed);
        bool Update();
        void ShowStatus();
};
#endif