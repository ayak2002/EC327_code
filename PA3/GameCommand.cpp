#include <iostream>
#include "GameCommand.h"
using namespace std;

void DoMoveCommand(Model & model, int student_id, Point2D p1)
{
    Student* sptr = model.GetStudentPtr(student_id);
    if(sptr == 0)
    {
        cout << "Error: Please enter a valid command!" << endl;
    }
    else
    {
        cout << "Moving " << sptr->GetName() << " to " << p1 << endl;
        sptr->StartMoving(p1);
    }
}

void DoMoveToDoctorCommand(Model & model, int student_id, int office_id)
{
    DoctorsOffice* dptr = model.GetDoctorsOfficePtr(office_id);
    Student* sptr = model.GetStudentPtr(student_id);
    if ((dptr == 0) || (sptr == 0))
    {
        cout << "Error: Please enter a valid command!" << endl;
    }
    else
    {
        cout << "Moving " << sptr->GetName() << " to doctor's office " << office_id << endl;
        sptr->StartMovingToDoctor(dptr);
    }
}

void DoMoveToClassCommand(Model & model, int student_id, int class_id)
{
    ClassRoom* cptr = model.GetClassRoomPtr(class_id);
    Student* sptr = model.GetStudentPtr(student_id);
    if ((cptr == 0) || (sptr == 0))
    {
        cout << "Error: Please enter a valid command!" << endl;
    }
    else
    {
        cout << "Moving " << sptr->GetName() << " to class " << class_id << endl;
        sptr->StartMovingToClass(cptr);
    }
}

void DoStopCommand(Model & model, int student_id)
{
    Student* sptr = model.GetStudentPtr(student_id);
    if(sptr == 0)
    {
        cout << "Error: Please enter a valid command!" << endl;
    }
    else
    {
        cout << "Stopping " << sptr->GetName() << endl;
        sptr->Stop();
    }
}

void DoLearningCommand(Model & model, int student_id, unsigned int assignments)
{
    Student* sptr = model.GetStudentPtr(student_id);
    if(sptr == 0)
    {
        cout << "Error: Please enter a valid command!" << endl;
    }
    else
    {
        cout << "Teaching " << sptr->GetName() << endl;
        sptr->StartLearning(assignments);
    }
}

void DoRecoverInOfficeCommand(Model& model, int student_id, unsigned int vaccine_needs)
{
    Student* sptr = model.GetStudentPtr(student_id);
    if (sptr == 0)
    {
        cout << "Error: Please enter a valid command!" << endl;
    }
    else
    {
        cout << "Recovering " << sptr->GetName() << "'s antibodies" << endl;
        sptr->StartRecoveringAntibodies(vaccine_needs);
    }
}

void DoGoCommand(Model& model, View& view)
{
    cout << "Advancing one tick." << endl;
    model.Update();
    model.ShowStatus();
    //model.Display(view);
}

void DoRunCommand(Model& model, View& view)
{
    cout << "Advancing to next event. " << endl;
    int count = 1;
    bool modUpdate = model.Update();
    while((count < 5) && (modUpdate == false))
    {
        modUpdate = model.Update();
        count++;
    }
    model.ShowStatus();
    //model.Display(view);
}

void HandleCommands(Model& model, View& view)
{
    char command;
    double x, y;
    Point2D p;
    int sId;
    int dId;
    int cId;
    unsigned int vaccine_amount, assignment_amount;

    cout << "Enter command: ";
    cin >> command;
    switch (command)
    {
        case 'm':
            cin >> sId >> x >> y;
            p.x = x;
            p.y = y;
            DoMoveCommand(model, sId, p);
            break;
        case 'd':
            cin >> sId >> dId;
            DoMoveToDoctorCommand(model, sId, dId);
            break;
        case 'c':
            cin >> sId >> cId;
            DoMoveToClassCommand(model, sId, cId);
            break;
        case 's':
            cin >> sId;
            DoStopCommand(model, sId);
            break;
        case 'v':
            cin >> sId >> vaccine_amount;
            DoRecoverInOfficeCommand(model, sId, vaccine_amount);
            break;
        case 'a':
            cin >> sId >> assignment_amount;
            DoLearningCommand(model, sId, assignment_amount);
            break;
        case 'g':
            DoGoCommand(model, view);
            break;
        case 'r':
            DoRunCommand(model, view);
            break;
        case 'q':
            exit(0);
            break;
    }
    model.Display(view);
}

