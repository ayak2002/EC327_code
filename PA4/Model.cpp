//Model code
#include <iostream>
#include "Model.h"
using namespace std;


Model :: Model()
{
    time = 0;
    Point2D p1(5,1);
    Student* ptrS1 = new Student("Homer", 1, 'S', 2, p1);
    object_ptrs.push_back(ptrS1);
    active_ptrs.push_back(ptrS1);
    student_ptrs.push_back(ptrS1);
    Point2D p2(10,1);
    Student* ptrS2 = new Student("Marge", 2, 'S', 1, p2);
    object_ptrs.push_back(ptrS2);
    active_ptrs.push_back(ptrS2);
    student_ptrs.push_back(ptrS2);
    Point2D p3(1, 20);
    DoctorsOffice* ptrD1 = new DoctorsOffice(1, 1, 100, p3);
    object_ptrs.push_back(ptrD1);
    active_ptrs.push_back(ptrD1);
    office_ptrs.push_back(ptrD1);
    Point2D p4(10, 20);
    DoctorsOffice* ptrD2 = new DoctorsOffice(2, 2, 200, p4);
    object_ptrs.push_back(ptrD2);
    active_ptrs.push_back(ptrD2);
    office_ptrs.push_back(ptrD2);
    Point2D p5(0,0);
    ClassRoom* ptrC1 = new ClassRoom(10, 1, 2, 3, 1, p5);
    object_ptrs.push_back(ptrC1);
    active_ptrs.push_back(ptrC1);
    class_ptrs.push_back(ptrC1);
    Point2D p6(5, 5);
    ClassRoom* ptrC2 = new ClassRoom(20, 5, 7.5, 4, 2, p6);
    object_ptrs.push_back(ptrC2);
    active_ptrs.push_back(ptrC2);
    class_ptrs.push_back(ptrC2);
    cout << "Model default constructed" << endl;
    Point2D p7(10, 12);
    Virus* ptrV1 = new Virus("COVID-19", 5, 2, 10, false, 1, p7);
    object_ptrs.push_back(ptrV1);
    active_ptrs.push_back(ptrV1);
    virus_ptrs.push_back(ptrV1);
    Point2D p8(15, 5);
    Virus* ptrV2 = new Virus("Influenza", 5, 2, 10, false, 2, p8);
    object_ptrs.push_back(ptrV2);
    active_ptrs.push_back(ptrV2);
    virus_ptrs.push_back(ptrV2);
}

Model :: ~Model()
{
    for (list <GameObject*> :: iterator it = object_ptrs.begin(); it != object_ptrs.end(); it++)
    {
        delete(*it); //destructs each object 
    }
    cout << "Model destructed." << endl;
}

Student* Model :: GetStudentPtr(int id)
{   
    for (list <Student*> :: iterator it = student_ptrs.begin(); it != student_ptrs.end(); it++)
    {
        if((*it)->GetId() == id)
        {
            return *it;
        }
    }
    return 0;
}

DoctorsOffice* Model :: GetDoctorsOfficePtr(int id)
{
    for (list <DoctorsOffice*> :: iterator it = office_ptrs.begin(); it != office_ptrs.end(); it++)
    {
        if((*it)->GetId() == id)
        {
            return *it;
        }
    }
    return 0;
}

ClassRoom* Model :: GetClassRoomPtr(int id)
{ 
    for (list <ClassRoom*> :: iterator it = class_ptrs.begin(); it != class_ptrs.end(); it++)
    {
        if((*it)->GetId() == id)
        {
            return *it;
        }
    }
    return 0;
}

Virus* Model :: GetVirusPtr(int id)
{
    for (list <Virus*> :: iterator it = virus_ptrs.begin(); it != virus_ptrs.end(); it++)
    {
        if((*it)->GetId() == id)
        {
            return *it;
        }
    }
    return 0;
}

bool Model :: Update()
{
    bool isActive;
    bool updateBool = false;
    bool won = true;
    bool lost = true;
    bool emptyOffice = false;
    bool deadVirus = false;
    time++;
    for (list <Virus*> :: iterator it = virus_ptrs.begin(); it != virus_ptrs.end(); it++)
    {
        for(list <Student*> :: iterator itStudent = student_ptrs.begin() ; itStudent != student_ptrs.end(); itStudent++)
        {
            isActive = false;
            for(list <GameObject*> :: iterator itActive = active_ptrs.begin(); itActive != active_ptrs.end(); itActive++)
            {
                if(*itStudent == *itActive)
                {
                    isActive = true;
                }
            }
            if (isActive)
            {
                active_student_ptrs.push_back(*itStudent);
            }
        }
        Student* closest = (*it)->getMinDistance(active_student_ptrs); //finds active closest student
        (*it)->MoveToStudent(closest); //moves towards closest student
        if((*it)->Update() == true)
        {
            updateBool = true;
        }
        if((*it)->IsAlive())
        {
            deadVirus = false;
        }
        else
        {
            for(list <GameObject*> :: iterator it2 = active_ptrs.begin(); it2 != active_ptrs.end(); it2++)
            {
                if(*it2 == *it)
                {
                    active_ptrs.remove(*it2);
                    cout << "Dead Virus removed" << endl;
                    break;
                }
            }
        }
    }
    for (list <Student*> :: iterator it = student_ptrs.begin(); it != student_ptrs.end(); it++)
    {
        if((*it)->Update() == true)
        {
            updateBool = true;
        }
        if((*it)->IsInfected() == false)
        {
            lost = false;
        }
        else
        {
            for(list <GameObject*> :: iterator it2 = active_ptrs.begin(); it2 != active_ptrs.end(); it2++)
            {
                if(*it2 == *it)
                {
                    active_ptrs.remove(*it2);
                    cout << "Infected Student removed" << endl;
                    break;
                }
            }
        }
    }
    for (list <DoctorsOffice*> :: iterator it = office_ptrs.begin(); it != office_ptrs.end(); it++)
    {
        if((*it)->Update() == true)
        {
            updateBool = true;
        }
        if ((*it)->GetNumVaccineRemaining() > 0)
        {
            emptyOffice = false;
        }
        else
        {
            for(list <GameObject*> :: iterator it2 = active_ptrs.begin(); it2 != active_ptrs.end(); it2++)
            {
                if(*it2 == *it)
                {
                    active_ptrs.remove(*it2);
                    cout << "Empty office removed" << endl;
                    break;
                }
            }
        }
    }
    for (list <ClassRoom*> :: iterator it = class_ptrs.begin(); it != class_ptrs.end(); it++)
    {
        if((*it)->Update() == true)
        {
            updateBool = true;
        }
        if ((*it)->passed() == false)
        {
            won = false;
        }
        else
        {
            for(list <GameObject*> :: iterator it2 = active_ptrs.begin(); it2 != active_ptrs.end(); it2++)
            {
                if(*it2 == *it)
                {
                    active_ptrs.remove(*it2);
                    cout << "Passed ClassRoom removed" << endl;
                    break;
                }
            }
        }
    }
    if (won == true)
    {
        cout << "GAME OVER: You win! All assignments done!" << endl;
        exit(0);
    }
    if (lost == true)
    {
        cout << "GAME OVER: You lose! All of your students are infected!" << endl;
        exit(0);
    }
    return updateBool;
}

void Model :: Display(View& view)
{
    view.Clear();
    for (list <GameObject*> :: iterator it = active_ptrs.begin(); it != active_ptrs.end(); it++)
    {
        view.Plot(*it); //plots all visible objects 
    }
    view.Draw();
}

void Model :: ShowStatus()
{
    cout << "Time: " << time << endl;
    for (list <GameObject*> :: iterator it = object_ptrs.begin(); it != object_ptrs.end(); it++)
    {
        (*it)->ShowStatus();
    }
}

void Model ::  NewCommand()
{
    char type;
    int id;
    Point2D location;
    cin >> type ;
    if((type != 'd') && (type != 'c') && (type != 's') && (type != 'v'))
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize> :: max(), '\n');
        throw Invalid_Input("Invalid type");
    }
    if(!(cin >> id))
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize> :: max(), '\n');
        throw Invalid_Input("Was expecting an integer");
    }
    if(id > 9)
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize> :: max(), '\n');
        throw Invalid_Input("ID cannot be bigger than 9");
    }
    if (!(cin >> location.x) || !(cin >> location.y))
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize> :: max(), '\n');
        throw Invalid_Input("Was expecting a double");
    }
    if (type == 'd')
    {
        for(list <DoctorsOffice*> :: iterator it = office_ptrs.begin(); it != office_ptrs.end(); it++)
        {
            if ((*it)->GetId() == id)
            {
                for(list <GameObject*> :: iterator itActive = active_ptrs.begin(); itActive != active_ptrs.end(); itActive++)
                {
                    if ((*it) == (*itActive))
                    {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize> :: max(), '\n');
                        throw Invalid_Input("An active Doctor's Office already has this ID");
                    }
                }
            }
            if(((*it)->GetLocation().x == location.x) && ((*it)->GetLocation().y == location.y))
            {
                for(list <GameObject*> :: iterator itActive = active_ptrs.begin(); itActive != active_ptrs.end(); itActive++)
                {
                    if ((*it) == (*itActive))
                    {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize> :: max(), '\n');
                        throw Invalid_Input("A building already exists in this location");
                    }
                }
            }
        }
        for(list <ClassRoom*> :: iterator it = class_ptrs.begin(); it != class_ptrs.end(); it++)
        {
            if(((*it)->GetLocation().x == location.x) && ((*it)->GetLocation().y == location.y))
            {
                for(list <GameObject*> :: iterator itActive = active_ptrs.begin(); itActive != active_ptrs.end(); itActive++)
                {
                    if ((*it) == (*itActive))
                    {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize> :: max(), '\n');
                        throw Invalid_Input("A building already exists in this location");
                    }
                }
            }
        }
        DoctorsOffice* ptrD = new DoctorsOffice(id, 5, 100, location);
        object_ptrs.push_back(ptrD);
        active_ptrs.push_back(ptrD);
        office_ptrs.push_back(ptrD);
        }
    else if(type == 'c')
    {
        for(list <ClassRoom*> :: iterator it = class_ptrs.begin(); it != class_ptrs.end(); it++)
        {
            if ((*it)->GetId() == id)
            {
                for(list <GameObject*> :: iterator itActive = active_ptrs.begin(); itActive != active_ptrs.end(); itActive++)
                {
                    if ((*it) == (*itActive))
                    {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize> :: max(), '\n');
                        throw Invalid_Input("An active ClassRoom already has this ID");
                    }
                }
            }
            if(((*it)->GetLocation().x == location.x) && ((*it)->GetLocation().y == location.y))
            {
                for(list <GameObject*> :: iterator itActive = active_ptrs.begin(); itActive != active_ptrs.end(); itActive++)
                {
                    if ((*it) == (*itActive))
                    {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize> :: max(), '\n');
                        throw Invalid_Input("A building already exists in this location");
                    }
                }
            }
        }
        for(list <DoctorsOffice*> :: iterator it = office_ptrs.begin(); it != office_ptrs.end(); it++)
        {
            if(((*it)->GetLocation().x == location.x) && ((*it)->GetLocation().y == location.y))
            {
                for(list <GameObject*> :: iterator itActive = active_ptrs.begin(); itActive != active_ptrs.end(); itActive++)
                {
                    if ((*it) == (*itActive))
                    {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize> :: max(), '\n');
                        throw Invalid_Input("A building already exists in this location");
                    }
                }
            }
        }
        ClassRoom* ptrC = new ClassRoom(10, 1, 1, 2, id, location);
        object_ptrs.push_back(ptrC);
        active_ptrs.push_back(ptrC);
        class_ptrs.push_back(ptrC);
    }
    else if(type == 's')
    {
        for(list <Student*> :: iterator it = student_ptrs.begin(); it != student_ptrs.end(); it++)
        {
            if ((*it)->GetId() == id)
            {
                for(list <GameObject*> :: iterator itActive = active_ptrs.begin(); itActive != active_ptrs.end(); itActive++)
                {
                    if ((*it) == (*itActive))
                    {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize> :: max(), '\n');
                        throw Invalid_Input("An active Student already has this ID");
                    }
                }
            }
        }
        string name = "Student" + to_string(id);
        Student* ptrS = new Student(name, id, 'S', 1, location);
        object_ptrs.push_back(ptrS);
        active_ptrs.push_back(ptrS);
        student_ptrs.push_back(ptrS);
    }
    else if(type == 'v')
    {
        for(list <Virus*> :: iterator it = virus_ptrs.begin(); it != virus_ptrs.end(); it++)
        {
            if((*it)->GetId() == id)
            {
                for (list <GameObject*> :: iterator itActive = active_ptrs.begin(); itActive != active_ptrs.end(); itActive++)
                {
                    if ((*it) == (*itActive))
                    {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize> :: max(), '\n');
                        throw Invalid_Input("An active Virus already has this ID");
                    }
                }
            }
        }
        string name = "Virus" + to_string(id);
        Virus* ptrV = new Virus(name, 5, 2, 10, false, id, location);
        object_ptrs.push_back(ptrV);
        active_ptrs.push_back(ptrV);
        virus_ptrs.push_back(ptrV);
    }
}

