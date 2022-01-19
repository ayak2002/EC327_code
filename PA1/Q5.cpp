//Preprocessor directives
#include <iostream>
#define  CASE 32 //defining the offset between upper and lower case characters as a constant
#define MAX 126 //defining the max possible ascii value acceptable (127 corresponds to [DEL] and there are no characters after that)
using namespace std;

//Function prototypes
char getChar(void); //gets the character input from the user
int getOffset(void); //gets the offset from the user
void findNewChar(char, int); //finds and displays the new character


//Main funtion: variable declarations and function calls
int main()
{
    char userPick = getChar();   //stores the user's input character in a variable
    int offset = getOffset();    //stores the user's input offset in another variable
    findNewChar(userPick, offset); //finds the new character given the input character variable and the offset variable
    return 0;
}


//Function definitions
char getChar(void)
{   
    char pick;  //declares a variable for the user's input
    cout << "Enter character: "; //asks the user to enter a character
    cin >> pick;  //puts the user's input in a declared variable
    return pick;  //returns the variable containing the user's input
}

int getOffset(void)
{
    int offset;   //declares a variable for the offset
    do
    {
    cout << "Offset (enter 0 to convert case): "; //asks the user to input an offset
    cin >> offset;   //puts the offset entered by the user in the declared variable
    } while (offset < 0); //makes sure the offset if greater than or equal to 0, if not ask again
    return offset; //returns the variable containing the offset
}

void findNewChar(char charPick, int offset)
{
    char newChar;  //declares a variable for the new character
    int newCharCode = static_cast<int> (charPick) + offset; /*finds the ascii equivalent of the new character by
                                                            typecasting the original character to an integer and adding
                                                            the offset to it*/
    if (newCharCode > MAX) //checks if the new ascii equivalent is outside the acceptable range
    {
        cout << "Error: out of range." << endl; //if yes, dsplays an error message
    } 
    else
    {
        if (offset==0) //checks if the offset is 0
        {
            if (isalpha(charPick))  //checks if the original character is a letter of the alphabet
            {
                if (islower(charPick)) //if yes and the letter is in lower case, 
                {
                    newCharCode = newCharCode - CASE; //get the ascii equivalent of its higher case version
                }
                else
                {
                    newCharCode = newCharCode + CASE; //if it's in higher case, get the ascii equivalent of it lower case version
                }
            }

        }
    newChar = static_cast<char> (newCharCode); //typecasts the new ascii equivalent to find the new character
    cout << "New Character: " << newChar << endl; //displays the new character to the user
    }
   
}
