//Preprocessor directives
#include <iostream>
#include <cmath> //needed for the pow function
#define MAXPOW 7 //32 bits max precision means max of 8 hex digits-> max power of 16 is 7
using namespace std;

//function protoypes
void getInt(int *, int *); //gets two integers from the user
int getHammingDist(int, int); // finds the hamming distance between the integers in hex
void dispHammingDist(int, int, int); //displays the hamming distance for the two integers


//Main Function:
int main()
{
    int num1, num2, hDist;    //variable declarations
    do
    {
        getInt(&num1, &num2);
    }while ((num1 <= 0) || (num2 <= 0));  //error checks to make sure numbers are positive
    hDist = getHammingDist(num1, num2); //function call to assign the hamming distance result to a variable
    dispHammingDist(num1, num2, hDist); //function call to display the result
    return 0;
}

//function definitions
void getInt(int *a, int *b) //uses pass by pointers method to modify the values of the variables
{
    cout << "Enter two positive integers: "; //asks user to input two integers
    cin >> *a >> *b;                         //puts the values entered by the users in the variables
}

int getHammingDist(int a, int b) 
{
    int hDist=0;                       //initializes the hamming distance to 0
    for (int i = MAXPOW; i>=0; i--)    //i is initialized to 7 amd is decremented by 1 until it becomes 0
    {
        int div = pow(16, i);
        int aMult = a/div;    //perfrom integer division on the first number by 16^i
        int bMult = b/div;    //perform integer division on the second number by 16^i
        if (aMult != bMult)            //if the result is not the same
        {
            hDist++;                   //increment the hamming distance by 1
        }
        a = a % div;            //the first number becomes the remainder of its division by 16^i
        b = b % div;            //the second number becomes the remainder of its division by 16^i
    }
    return hDist;                      //return the hamming distance
}

void dispHammingDist(int a, int b, int dist) /*displays the hamming distance in a sentence format 
                                               given the two integers and the hamming distance between them*/         
{
    cout << "Hamming Distance between " <<  a << " and " << b <<
    " when numbers are in hex format is: " << dist << "." << endl;
}