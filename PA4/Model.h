#ifndef MODEL_H
#define MODEL_H
#include "Student.h"
#include "Virus.h"
#include "View.h"
#include "Input_Handling.h"
#include <limits>
#include <list>
#include <iterator>

class Model
{
    private: 
        int time;
        list <GameObject*> object_ptrs;
        list <GameObject*> active_ptrs;
        list <Student*> student_ptrs;
        list <DoctorsOffice*> office_ptrs;
        list <ClassRoom*> class_ptrs;
        list <Virus*> virus_ptrs;
        list <Student*> active_student_ptrs;
    public:
        Model();
        virtual ~Model();
        Student * GetStudentPtr(int);
        DoctorsOffice * GetDoctorsOfficePtr(int); 
        ClassRoom * GetClassRoomPtr(int); 
        Virus* GetVirusPtr(int);
        bool Update();
        void Display(View&); 
        void ShowStatus(); 
        void NewCommand();
};

#endif