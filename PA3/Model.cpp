//Model code
#include <iostream>
#include "Model.h"
#include "View.h"
using namespace std;

const int objectTotal = 6;

Model :: Model()
{
    time = 0;
    Point2D p1(5,1);
    Student* ptrS1 = new Student("Homer", 1, 'S', 2, p1);
    object_ptrs[0] = ptrS1;
    student_ptrs[0] = ptrS1;
    Point2D p2(10,1);
    Student* ptrS2 = new Student("Marge", 2, 'S', 1, p2);
    object_ptrs[1] = ptrS2;
    student_ptrs[1] = ptrS2;
    Point2D p3(1, 20);
    DoctorsOffice* ptrD1 = new DoctorsOffice(1, 1, 100, p3);
    object_ptrs[2] = ptrD1;
    office_ptrs[0] = ptrD1; 
    Point2D p4(10, 20);
    DoctorsOffice* ptrD2 = new DoctorsOffice(2, 2, 200, p4);
    object_ptrs[3] = ptrD2;
    office_ptrs[1] = ptrD2;
    Point2D p5(0,0);
    ClassRoom* ptrC1 = new ClassRoom(10, 1, 2, 3, 1, p5);
    object_ptrs[4] = ptrC1;
    class_ptrs[0] = ptrC1;
    Point2D p6(5, 5);
    ClassRoom* ptrC2 = new ClassRoom(20, 5, 7.5, 4, 2, p6);
    object_ptrs[5] = ptrC2;
    class_ptrs[1] = ptrC2;
    cout << "Model default constructed" << endl;
}

Model :: ~Model()
{
    for (int i=0; i<objectTotal; i++)
    {
        delete(object_ptrs[i]); //destructs each object 
    }
    cout << "Model destructed." << endl;
}

Student* Model :: GetStudentPtr(int id)
{
    if(id == 1)
    {
        return student_ptrs[0];
    }
    else if(id == 2)
    {
        return student_ptrs[1];
    }
    else
    {
        return 0;
    }
}

DoctorsOffice* Model :: GetDoctorsOfficePtr(int id)
{
    if(id == 1)
    {
        return office_ptrs[0];
    }
    else if(id == 2)
    {
        return office_ptrs[1];
    }
    else
    {
        return 0;
    }
}

ClassRoom* Model :: GetClassRoomPtr(int id)
{
    if(id == 1)
    {
        return class_ptrs[0];
    }
    else if(id == 2)
    {
        return class_ptrs[1];
    }
    else
    {
        return 0;
    }
}

bool Model :: Update()
{
    bool updateBool = false;
    time++;
    for (int i=0; i<objectTotal; i++)
    {
        if((object_ptrs[i]->Update()) == true)
        {
            updateBool = true;
        }
    }
    if((class_ptrs[0]->passed()) && (class_ptrs[1]->passed()))
    {
        cout << "GAME OVER: You win! All assignments done!" << endl;
        exit(0);
    }
    if((student_ptrs[0]->IsInfected()) && (student_ptrs[1]->IsInfected()))
    {
        cout << "GAME OVER: You lose! All of your students are infected!" << endl;
        exit(0);
    }
    return updateBool;
}

void Model :: Display(View& view)
{
    view.Clear();
    for (int i=0; i<objectTotal; i++)
    {
        view.Plot(object_ptrs[i]); //plots all visible objects 
    }
    view.Draw();
}

void Model :: ShowStatus()
{
    cout << "Time: " << time << endl;
    for (int i=0; i<objectTotal; i++)
    {
        object_ptrs[i]->ShowStatus();
    }
}


