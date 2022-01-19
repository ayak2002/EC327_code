//preprocessor directives
#include <iostream>
using namespace std;

//function protoypes
int getDigit(void);      //gets the input from the user
void PrintRhombus(int);  //prints the numbers in the Rhombus

int current; //global variable for the number that currently needs to be printed

//Main Function
int main()
{
    int n;
        n = getDigit();      //gets the user's input and puts it in n
    if (n < 1 || n > 9)      //checks if number if out of range
    {
        cout << "Error: number outside of [1,9] range." << endl; 
        return 0;
    }

    for (int i=1; i<=n; i++)  //for the first n lines of the rhombus
    {
        current = 1;           //current is reset to 1 for every line
        for (int j=1; j<=((2*n)-(2*i)); j++)  //the number of spaces before each line of numbers is 2*n - 2*i
        {
            cout << " ";      //prints the spaces for line i 
        }
        PrintRhombus(i);      //prints the numbers for line i
        cout << endl;
    }
    for (int i=n-1; i>=1; i--) //for the last n-1 lines of the rhombus
    {
        current = 1;           //current is reset to 1 for every line
        for (int j=1; j<=((2*n)-(2*i)); j++)   //the number of spaces before each line of numbers is 2*n - 2*i
        {
            cout << " ";      //prints the spaces for line i
        }
        PrintRhombus(i);      //prints the numbers for line i
        cout << endl;
    }
    return 0;
}

//function definitions/ bodies
int getDigit(void)            //gets the user's input
{
    int userInput;
    cout << "Enter a number [1-9]: ";
    cin >> userInput;
    return userInput;
}

void PrintRhombus(int n)    //recursive function to print the number sequence for each line
{
    if (current == n)       //if the current number to be printed is n
    {
        for (int i=current; i>= 1; i--)  //print all the numbers from n to 1 separated by spaces
        {
            cout << i << ' ';
        }
    }
    else
    {
        cout << current << ' ';  //else print the current number
        current++;   //increment the current variable
        PrintRhombus(n); //the function calls itself to print the next number until current == n
    }
    return;
}
