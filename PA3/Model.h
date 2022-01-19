#ifndef MODEL_H
#define MODEL_H
#include "Student.h"
#include "View.h"

class Model
{
    private: 
        int time;
        GameObject * object_ptrs[10];
        int num_objects;
        Student * student_ptrs[10];
        int num_students;
        DoctorsOffice * office_ptrs[10];
        int num_offices;
        ClassRoom * class_ptrs[10];
        int num_classes;
    public:
        Model();
        virtual ~Model();
        Student * GetStudentPtr(int);
        DoctorsOffice * GetDoctorsOfficePtr(int); 
        ClassRoom * GetClassRoomPtr(int); 
        bool Update();
        void Display(View&); 
        void ShowStatus(); 
};

#endif