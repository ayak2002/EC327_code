//main function
#include <iostream>
#include "GameCommand.h"
using namespace std;

int main()
{
    static Model model;
    View view;
    model.ShowStatus();
    model.Display(view);
    while(true) //loops until user exits or loses or wins
    {
        cout << "Enter command: ";
        HandleCommands(model, view);
    }
    return 0;
}