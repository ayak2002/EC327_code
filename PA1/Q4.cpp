#include <iostream>
#include <string>
#define MINLIM 48  //ascii equivalent of '0'
#define MAXLIM 57  //ascii equivalent of '9'
using namespace std;

//function prototypes
string getNum(void); //gets number from user 
bool isPalindrome(string, int); //checks if number is a palindrome given a string and its size

//Main function
int main()
{
    string inputNum = getNum();         //function call to get the user's input as a string
    const int SIZE = inputNum.size();   //stores the size of the input string as a constant
    if (isPalindrome(inputNum, SIZE))   //checks if the number is a string by calling isPalindrome
    {
        cout << "The number " << inputNum << " is a palindrome. " << endl;     //if yes, display the result
    }
    else
    {
        cout << "The number " << inputNum << " is not a palindrome. " << endl; //if not, display the result
    }
    return 0;
}

//function definitions

string getNum(void)
{
    string inputStr;            //declares inputStr string variable
    cout << "Enter a number: "; //asks the user to input a number
    cin >> inputStr;            //puts the user's input in inputStr
    return inputStr;            //returns inputStr
}


bool isPalindrome(string inStr, int SIZE)
{
    string revStr;              //declares revStr variable (reverse string)
    bool result = 1;            //initialize a result variable to 1
    int maxIndex = SIZE - 1;    //finds the maximum index of the string
    for (int i = maxIndex; i>=0; i--) //i is initialized to maxIndex and is decremented by 1 until it's 0
    {
        if (((static_cast<int> (inStr.at(i))) < MINLIM) || ((static_cast<int> (inStr.at(i))) > MAXLIM))/*makes sure each character 
                                                                                                        of the string is a digit*/
        {
            result = 0;   //if not, the result becomes 0
        }
        else 
        {
            revStr.push_back(inStr.at(i)); //appends number of index i of inStr to revStr
        }
    }
    
    if (inStr.compare(revStr) != 0) //if inStr and revStr are not the same (aka if inStr.compare(revStr) does not return 0)
    {
        result = 0;   //the result becomes 0
    }       

    return result; //returns the result (1 or 0)

}
