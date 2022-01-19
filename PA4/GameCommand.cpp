#include <iostream>
#include "GameCommand.h"
using namespace std;

void DoMoveCommand(Model & model, int student_id, Point2D p1)
{
    Student* sptr = model.GetStudentPtr(student_id);
    try
    {
        if(sptr == 0)
        {
            throw Invalid_Input("Error: Please enter a valid command!");
        }
        else
        {
            cout << "Moving " << sptr->GetName() << " to " << p1 << endl;
            sptr->StartMoving(p1);
        }   
    }
    catch (Invalid_Input& except)
    {
        cout << "Invalid input - " << except.msg_ptr << endl;
        // actions to be taken if the input is wrong
    }
}

void DoMoveToDoctorCommand(Model & model, int student_id, int office_id)
{
    DoctorsOffice* dptr = model.GetDoctorsOfficePtr(office_id);
    Student* sptr = model.GetStudentPtr(student_id);
    try
    {
        if ((dptr == 0) || (sptr == 0))
        {
            throw Invalid_Input("Error: Please enter a valid command!");
        }
        else
        {
            cout << "Moving " << sptr->GetName() << " to doctor's office " << office_id << endl;
            sptr->StartMovingToDoctor(dptr);
        }
    }
    catch (Invalid_Input& except)
    {
        cout << "Invalid input - " << except.msg_ptr << endl;
        // actions to be taken if the input is wrong
    }
}

void DoMoveToClassCommand(Model & model, int student_id, int class_id)
{
    ClassRoom* cptr = model.GetClassRoomPtr(class_id);
    Student* sptr = model.GetStudentPtr(student_id);
    try
    {
        if ((cptr == 0) || (sptr == 0))
        {
            throw Invalid_Input("Error: Please enter a valid command!");
        }
        else
        {
            cout << "Moving " << sptr->GetName() << " to class " << class_id << endl;
            sptr->StartMovingToClass(cptr);
        }
    }
    catch (Invalid_Input& except)
    {
        cout << "Invalid input - " << except.msg_ptr << endl;
        // actions to be taken if the input is wrong
    }   
}

void DoStopCommand(Model & model, int student_id)
{
    Student* sptr = model.GetStudentPtr(student_id);
    try
    {
        if(sptr == 0)
        {
            throw Invalid_Input("Error: Please enter a valid command!");
        }
        else
        {
            cout << "Stopping " << sptr->GetName() << endl;
            sptr->Stop();
        }
    }
    catch (Invalid_Input& except)
    {
        cout << "Invalid input - " << except.msg_ptr << endl;
        // actions to be taken if the input is wrong
    }
}

void DoLearningCommand(Model & model, int student_id, unsigned int assignments)
{
    Student* sptr = model.GetStudentPtr(student_id);
    try{
        if(sptr == 0)
        {
            throw Invalid_Input("Error: Please enter a valid command!");
        }
        else
        {
            cout << "Teaching " << sptr->GetName() << endl;
            sptr->StartLearning(assignments);
        }
    }
    catch (Invalid_Input& except)
    {
        cout << "Invalid input - " << except.msg_ptr << endl;
        // actions to be taken if the input is wrong
    }
}

void DoRecoverInOfficeCommand(Model& model, int student_id, unsigned int vaccine_needs)
{
    Student* sptr = model.GetStudentPtr(student_id);
    try
    {
        if (sptr == 0)
        {
            throw Invalid_Input("Error: Please enter a valid command!");
        }
        else
        {
            cout << "Recovering " << sptr->GetName() << "'s antibodies" << endl;
            sptr->StartRecoveringAntibodies(vaccine_needs);
        }
    }
    catch (Invalid_Input& except)
    {
        cout << "Invalid input - " << except.msg_ptr << endl;
        // actions to be taken if the input is wrong
    }
}

void DoGoCommand(Model& model, View& view)
{
    cout << "Advancing one tick." << endl;
    model.Update();
    model.ShowStatus();
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

    cin >> command;
    try{
    switch (command){
        case 'm':
            if(!(cin >> sId))
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize> :: max(), '\n');
                throw Invalid_Input("Was expecting an integer");
                
            }
            if (!(cin >> x) || (!(cin >> y)))
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize> :: max(), '\n');
                throw Invalid_Input("Was expecting a double");
            }
            p.x = x;
            p.y = y;
            DoMoveCommand(model, sId, p);
            break;
        case 'd':
            if(!(cin >> sId))
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize> :: max(), '\n');
                throw Invalid_Input("Was expecting an integer");
                
            }
            if(!(cin >> dId))
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize> :: max(), '\n');
                throw Invalid_Input("Was expecting an integer"); 
            }
            DoMoveToDoctorCommand(model, sId, dId);
            break;
        case 'c':
            if(!(cin >> sId))
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize> :: max(), '\n');
                throw Invalid_Input("Was expecting an integer");
                
            }
            if(!(cin >> cId))
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize> :: max(), '\n');
                throw Invalid_Input("Was expecting an integer"); 
            }
            DoMoveToClassCommand(model, sId, cId);
            break;
        case 's':
            if(!(cin >> sId))
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize> :: max(), '\n');
                throw Invalid_Input("Was expecting an integer");
                
            }
            DoStopCommand(model, sId);
            break;
        case 'v':
            if(!(cin >> sId))
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize> :: max(), '\n');
                throw Invalid_Input("Was expecting an integer");
                
            }
            if(!(cin >> vaccine_amount))
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize> :: max(), '\n');
                throw Invalid_Input("Was expecting an unsigned integer");
                
            }
            DoRecoverInOfficeCommand(model, sId, vaccine_amount);
            break;
        case 'a':
            if(!(cin >> sId))
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize> :: max(), '\n');
                throw Invalid_Input("Was expecting an integer");
                
            }
            if(!(cin >> assignment_amount))
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize> :: max(), '\n');
                throw Invalid_Input("Was expecting an unsigned integer");
                
            }
            DoLearningCommand(model, sId, assignment_amount);
            break;
        case 'g':
            DoGoCommand(model, view);
            break;
        case 'r':
            DoRunCommand(model, view);
            break;
        case 'n':
            model.NewCommand();
            break;
        case 'q':
            exit(0);
            break;
        default: 
            throw Invalid_Input("Invalid command code");
    }
    }
    catch (Invalid_Input& except)
    {
        cout << "Invalid input - " << except.msg_ptr << endl;
        // actions to be taken if the input is wrong
    }
    
    model.Display(view);
}

