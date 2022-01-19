//Preprocessor directives
#include <iostream>
#include <cstdlib>
#define ROCK 0  //defining ROCK as a constant of value 0
#define PAPER 1 //defining PAPER as a constant of value 1
#define SCISSORS 2 //defining SCISSORS as a constant of value 2
using namespace std;

//function declarations
int getUserChoice(void); // asks the user for their choice
int getCompChoice(void); // generates the computer's choice
void printCompChoice(int); // prints the computer's choice
void findWinner(int, int); // chooses and displays the winner of the game

// Main function: 
int main()
{
    int userChoice, compChoice;   //variable declarations
    userChoice = getUserChoice(); //function call, value is returned and placed in userChoice
    compChoice = getCompChoice(); //function call, value is returned and placed in compChoice
    printCompChoice(compChoice);  //function call to print compChoice in a sentence format
    findWinner(userChoice,compChoice); /*function call to find and display the winner
                                        between userChoice(the user) and compChoice(the computer)*/
    return 0;   
}

//function definitions / function bodies
int getUserChoice(void)
{
    int uChoice;
    cout << "Choose Rock (0), Paper (1), or Scissors (2): "; //Asks for user's choice
    cin >> uChoice; //puts the user's pick in uChoice variable 
    return uChoice; //uChoice is returned
}


int getCompChoice(void)
{
    srand(time(NULL));  //seeding the rand function
    return rand () % 3; //generates a random number ranging from 0 to 2
}


void printCompChoice(int cChoice)  /*displays to the user the computer's choice depending on
                                   the number passed as parameter*/
{
    cout << "Computer chooses: ";
    switch (cChoice)
    {
        case 0: cout << "Rock" << endl;
                break;
        case 1: cout << "Paper" << endl;
                break ;
        case 2: cout << "Scissors" << endl;
                break;
    }
}


void findWinner(int User,int Comp)       /*goes through all different possibilities with an if-else
                                         statement and displays who won in each case*/
{
    if ((User==ROCK)&&(Comp==SCISSORS))
    {
        cout << "You Win!" << endl;
    }
    else if ((User==ROCK)&&(Comp==PAPER))
    {
        cout << "You Lose!" << endl;
    }
    else if ((User==ROCK)&&(Comp==ROCK))
    {
        cout << "You Tie!" << endl;
    }
    else if ((User==PAPER)&&(Comp==SCISSORS))
    {
        cout << "You Lose!" << endl;
    }
    else if ((User==PAPER) && (Comp==ROCK))
    {
        cout << "You Win!" << endl;
    }
    else if ((User==PAPER)&&(Comp==PAPER))
    {
        cout << "You Tie!" << endl;
    }
    else if ((User==SCISSORS)&&(Comp==SCISSORS))
    {
        cout << "You Tie!" << endl;
    }
    else if ((User==SCISSORS)&&(Comp==ROCK))
    {
        cout << "You Lose!" << endl;
    }
    else if ((User==SCISSORS)&&(Comp==PAPER))
    {
        cout << "You Win!" << endl;
    }

}


