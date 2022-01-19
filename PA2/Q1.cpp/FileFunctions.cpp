//preprocessor directives
#include <iostream>
#include <cmath>
#include <string>
#include <string.h>
#include "pa2Functions.h"
using namespace std;

int main()
{ 
    int firstInt,
        lastInt, 
        i;      //for cases where the parameters are integers
    double first, 
           delta, 
           last, 
           j;  //for the other cases where the parameters are doubles
    char* fileName;
    int count = 0;              //counts the number of entries
    bool isCodeO = 0;           //can be checked to determine whether or not to write the output to a file
    bool isCodeI=0;
    int readCount = 0;
    int intCount = 0;
    int fileCount = 0;
    int doubCount = 0; 
    initialize();               //writes the header of the program
    char code;
    do{
            if(isCodeI)
            {
                readCount++;
                if (readCount == commandCount)
                {
                    isCodeI=0;
                }

            }
            if(!isCodeI)
            {                              
                cout << "Please enter command code: ";
                cin >> code;                             //asks user for command code and puts it in code variable
                if (!checkCode(code))                    //checks if the code is valid, if not, display an error
                {
                    cout << "Invalid command code" << endl;
                }
                else if((code == 'q') || (code == 'Q'))  //if users wants to quit, end the program
                {
                    return 0;
                }
                else
                {
                    cout << "Please enter command parameters: ";          //if not, prompt the user for parameters
                }
                if((code == 'i') || (code == 'I'))
                {
                    string userInput;
                    cin >> userInput;
                    fileName = &userInput[0];
                    isCodeI = 1;
                    readDataFromFile(fileName);
                }
            }
            if(isCodeI)
            {
                code = commArr[readCount];
                if((code == 'f')||(code=='F')||(code=='b')||(code=='B'))
                {
                    firstInt = intArr[intCount];
                    intCount++;
                }
                else if ((code == 'e')||(code == 'E')||(code == 'd')||(code == 'D'))
                {
                    firstInt = intArr[intCount];
                    lastInt = intArr[intCount + 1];
                    intCount+=2;
                }
                else if ((code == 'o') || (code == 'O'))
                {
                    string fileString(fileArr[fileCount]);
                    fileName = &fileString[0];
                    fileCount++;
                }
                else
                {
                    first = doubArr[doubCount];
                    last = doubArr[doubCount + 1];
                    delta = doubArr[doubCount + 2];
                    doubCount+=3;
                }
            }
            if((code == 'o') || (code == 'O'))  //if user wants to write to outfile
            {
                if (!isCodeI)
                {
                    string userInput;
                    cin >> userInput;
                    fileName = &userInput[0];       //store fileName in a character array
                }
                isCodeO = 1;                    //isCodeO becomes true
            }
            if((code == 'f') || (code == 'F'))      //if user wants to compute the factorial
            {
                count++;
                if(!isCodeI)
                {
                    cin >> firstInt;                    //take the user's input as a single integer and put it in a var
                }
                int fact = factorial (firstInt);    //compute the factorial
                sprintf(funOutput, "Factorial of %d: %d", firstInt, fact);  //format the output of the function into a char array
                cout << funOutput << endl;     //print the char array
                if(isCodeO)
                {
                    writeDataToFile(fileName);  //if user wants to write to an outfile, print the char array in the outfile
                }
                    
            }
            if((code == 'b') || (code == 'B'))  //if user wants to compute fibonacci numbers
            {
                if (!isCodeI)
                {
                    cin >> firstInt;                //take the user's input as a single integer and put it in a var
                }
                int fib = fibonacci (firstInt); //compute the fibonacci number
                sprintf(funOutput, "Fibonacci at index %d: %d", firstInt, fib); //format the output of the function into a char array
                cout << funOutput << endl;  //print the char array
                if(isCodeO)
                {
                    writeDataToFile(fileName);  //if user wants to write to an outfile, print the char array in the outfile
                }
                count++;
            }
            if((code == 'r') || (code == 'R')) //if user wants to compute square roots
            {
                if(!isCodeI)
                {
                    cin >> first >> last >> delta; //take three user inputs and put them in double variables
                }
                if ((delta <= 0) || (first > last))   //if delta<=0 or if first > last, no computations are needed
                {
                    sprintf(funOutput,"No computation needed."); //format output in a char array
                    cout << funOutput << endl; //print the char array
                    if(isCodeO)
                    {
                        writeDataToFile(fileName);  //if user wants to write to an outfile, print the char array in the outfile
                    }
                }
                else
                {
                    for (j=first; j<=last; j=j+delta)  //iterate from first to last in steps of delta
                    {
                        double root = findSqrtValue (j);  //compute the sqrt value for each step
                        sprintf(funOutput, "Square root of %.2f: %.2f", j, root); //format output in a char array
                        cout << funOutput << endl;  //print the char array
                        if(isCodeO)
                        {
                            writeDataToFile(fileName);  //if user wants to write to an outfile, print the char array in the outfile
                        }
                        count++;
                        if(count == ENTRIES)
                        {
                            break;
                        }
                    }
                    if (((j-delta)!=last) && (count!=ENTRIES))  //check if delta increment exceeds the "last" value
                    {
                        double rootLast = findSqrtValue (last);  //if yes, "last" is used for the final computation
                        sprintf(funOutput, "Square root of %.2f: %.2f", last, rootLast); //format output in char array
                        cout << funOutput << endl;  //print char array 
                        if(isCodeO)
                        {
                            writeDataToFile(fileName);  //if user wants to write to an outfile, print the char array in the outfile
                        }
                        count++;
                    }
                }
            }
            if ((code == 'u') || (code == 'U'))  //if user wants to compute square areas
            {
                if(!isCodeI)
                {
                    cin >> first >> last >> delta;  //take three user inputs and put them in double variables
                }
                if ((delta <= 0) || (first > last))  //check if computations are needed, if not print a message
                {
                    sprintf(funOutput,"No computation needed.");
                    cout << funOutput << endl;
                    if(isCodeO)
                    {
                        writeDataToFile(fileName);  //if user wants to write to an outfile, print the char array in the outfile
                    }
                }
                else
                {  
                    for (j=first; j<=last; j=j+delta)  //iterate from first to last in steps of delta
                    {
                        double squareArea = areaSquare(j);  //compute area of square for each side length
                        sprintf(funOutput, "Area of a square of side %.2f: %.2f", j, squareArea);  //put output in a char array
                        cout << funOutput << endl; //print char array
                        if(isCodeO)
                        {
                            writeDataToFile(fileName);  //if user wants to write to an outfile, print the char array in the outfile
                        }
                        count++;
                        if(count == ENTRIES)
                        {
                            break;
                        }
                    }
                    if (((j-delta)!=last) && (count!=ENTRIES)) //if delta increment exceeds "last" value
                    {
                        double squareAreaLast = areaSquare(last); //use "last" value for final computation
                        sprintf(funOutput, "Area of a square of side %.2f: %.2f", last, squareAreaLast); //put output in a char array
                        cout << funOutput << endl; //print char array 
                        if(isCodeO)
                        {
                            writeDataToFile(fileName);  //if user wants to write to an outfile, print the char array in the outfile
                        }
                        count++;
                    }
                }
            }
            if ((code == 'c') || (code == 'C')) //if user wants to compute circle area
            {
                if(!isCodeI)
                {
                    cin >> first >> last >> delta;  //take three user inputs and put them in double variables
                }
                if ((delta <= 0) || (first > last))  //check if computations are needed, if not print a message
                {
                    sprintf(funOutput,"No computation needed.");
                    cout << funOutput << endl;
                     if(isCodeO)
                    {
                        writeDataToFile(fileName);  //if user wants to write to an outfile, print the char array in the outfile
                    }
                }
                else
                {  
                    for (j=first; j<=last; j=j+delta)  //iterate from first to last in steps of delta
                    {
                        double circleArea = areaCircle(j);  //compute area of circle for each radius
                        sprintf(funOutput, "Area of a circle of radius %.2f: %.2f", j, circleArea);  //put output in a char array
                        cout << funOutput << endl; //print char array
                        if(isCodeO)
                        {
                            writeDataToFile(fileName);  //if user wants to write to an outfile, print the char array in the outfile
                        }
                        count++;
                        if(count == ENTRIES)
                        {
                            break;
                        }
                    }
                    if (((j-delta)!=last) && (count!=ENTRIES))  //if delta increment exceeds "last" value
                    {
                        double circleAreaLast = areaCircle(last); //use "last" value for final computation
                        sprintf(funOutput, "Area of a circle of radius %.2f: %.2f", last, circleAreaLast); //put output in a char array
                        cout << funOutput << endl; //print char array 
                        if(isCodeO)
                        {
                            writeDataToFile(fileName);  //if user wants to write to an outfile, print the char array in the outfile
                        }
                        count++;
                    }
                }
            }
            if((code == 'e') || (code == 'E')) //if user wants to compute even numbers
            {
                if(!isCodeI)
                {
                    cin >> firstInt >> lastInt;
                }
                if (firstInt > lastInt)
                {
                    sprintf(funOutput,"No computation needed.");
                    cout << funOutput << endl;
                    if(isCodeO)
                    {
                        writeDataToFile(fileName);  //if user wants to write to an outfile, print the char array in the outfile
                    }
                }
                else
                {
                    int countEven = 1;
                    for (i = firstInt-1; i <= lastInt; i+=2, countEven++)
                    {
                        int even = findNextEvenValue(i);
                        if (even <= lastInt)
                        {
                            sprintf(funOutput, "Even value %d from %d to %d: %d", countEven, firstInt, lastInt, even);
                            cout << funOutput << endl; //print char array 
                            if(isCodeO)
                            {
                                writeDataToFile(fileName);  //if user wants to write to an outfile, print the char array in the outfile
                            }
                            count++;
                        }
                        if(count == ENTRIES)
                        {
                            break;
                        }
                    }
                }
            }
            if((code == 'k') || (code == 'K')) //if user wants to compute lucky numbers
            {
                if(!isCodeI)
                {
                    cin >> first >> last >> delta;  //take three user inputs and put them in double variables
                }
                if ((delta <= 0) || (first > last))  //check if computations are needed, if not print a message
                {
                    sprintf(funOutput,"No computation needed.");
                    cout << funOutput << endl;
                    if(isCodeO)
                    {
                        writeDataToFile(fileName);  //if user wants to write to an outfile, print the char array in the outfile
                    }
                }
                else
                {  
                    for (j=first; j<=last; j=j+delta)  //iterate from first to last in steps of delta
                    {
                        double luckyNum = lucky(j);  //compute lucky number for each seed
                        sprintf(funOutput, "Lucky number for seed %.2f: %.2f", j, luckyNum);  //put output in a char array
                        cout << funOutput << endl; //print char array
                        if(isCodeO)
                        {
                            writeDataToFile(fileName);  //if user wants to write to an outfile, print the char array in the outfile
                        }
                        count++;
                        if(count == ENTRIES)
                        {
                            break;
                        }
                    }
                    if (((j-delta)!=last) && (count!=ENTRIES))  //if delta increment exceeds "last" value 
                    {
                        double luckyNumLast = lucky(last); //use "last" value for final computation
                        sprintf(funOutput, "Lucky number for seed %.2f: %.2f", last, luckyNumLast); //put output in a char array
                        cout << funOutput << endl; //print char array 
                        if(isCodeO)
                        {
                            writeDataToFile(fileName);  //if user wants to write to an outfile, print the char array in the outfile
                        }
                        count++;
                    }
                }
            }
            if((code == 's') || (code == 'S')) //if user wants to compute sin values
            {
                if(!isCodeI)
                {
                    cin >> first >> last >> delta;  //take three user inputs and put them in double variables
                }
                if ((delta <= 0) || (first > last))  //check if computations are needed, if not print a message
                {
                    sprintf(funOutput,"No computation needed.");
                    cout << funOutput << endl;
                    if(isCodeO)
                    {
                        writeDataToFile(fileName);  //if user wants to write to an outfile, print the char array in the outfile
                    }
                }
                else
                { 
                    for (j=first; j<=last; j=j+delta)  //iterate from first to last in steps of delta
                    {
                        double sinVal = doMath(j,code);  //compute sine value of each number
                        sprintf(funOutput, "Sine value of %.2f: %.2f", j, sinVal);  //put output in a char array
                        cout << funOutput << endl; //print char array
                        if(isCodeO)
                        {
                            writeDataToFile(fileName);  //if user wants to write to an outfile, print the char array in the outfile
                        }
                        count++;
                        if(count == ENTRIES)
                        {
                            break;
                        }
                    }
                    if (((j-delta)!=last) && (count!=ENTRIES))  //if delta increment exceeds "last" value 
                    {
                        double sinValLast = doMath(last, code); //use "last" value for final computation
                        sprintf(funOutput, "Sine value of %.2f: %.2f", last, sinValLast); //put output in a char array
                        cout << funOutput << endl; //print char array 
                        if(isCodeO)
                        {
                            writeDataToFile(fileName);  //if user wants to write to an outfile, print the char array in the outfile
                        }
                        count++;
                    }
                }
            }
            if((code == 'n') || (code == 'N')) //if user wants to compute cos values
            {
                if(!isCodeI)
                {
                    cin >> first >> last >> delta;  //take three user inputs and put them in double variables
                }
                if ((delta <= 0) || (first > last))  //check if computations are needed, if not print a message
                {
                    sprintf(funOutput,"No computation needed.");
                    cout << funOutput << endl;
                    if(isCodeO)
                    {
                        writeDataToFile(fileName);  //if user wants to write to an outfile, print the char array in the outfile
                    }  
                }
                else
                { 
                    for (j=first; j<=last; j=j+delta)  //iterate from first to last in steps of delta
                    {
                        double cosVal = doMath(j,code);  //compute cos value of each number
                        sprintf(funOutput, "Cosine value of %.2f: %.2f", j, cosVal);  //put output in a char array
                        cout << funOutput << endl; //print char array
                        if(isCodeO)
                        {
                            writeDataToFile(fileName);  //if user wants to write to an outfile, print the char array in the outfile
                        }
                        count++;
                        if(count == ENTRIES)
                        {
                            break;
                        }
                    }
                    if (((j-delta)!=last) && (count!=ENTRIES))  //if delta increment exceeds "last" value 
                    {
                        double cosValLast = doMath(last, code); //use "last" value for final computation
                        sprintf(funOutput, "Cos value of %.2f: %.2f", last, cosValLast); //put output in a char array
                        cout << funOutput << endl; //print char array 
                        if(isCodeO)
                        {
                            writeDataToFile(fileName);  //if user wants to write to an outfile, print the char array in the outfile
                        }
                        count++;
                    }
                }
            }
            if((code == 'x') || (code == 'X')) //if user wants to compute exponential values
            {
                if(!isCodeI)
                {
                    cin >> first >> last >> delta;  //take three user inputs and put them in double variables
                }
                if ((delta <= 0) || (first > last))  //check if computations are needed, if not print a message
                {
                    sprintf(funOutput,"No computation needed.");
                    cout << funOutput << endl;
                    if(isCodeO)
                    {
                        writeDataToFile(fileName);  //if user wants to write to an outfile, print the char array in the outfile
                    }
                }
                else
                { 
                    for (j=first; j<=last; j=j+delta)  //iterate from first to last in steps of delta
                    {
                        double xVal = doMath(j,code);  //compute exponential value of each number
                        sprintf(funOutput, "Exponential of %.2f: %.2f", j, xVal);  //put output in a char array
                        cout << funOutput << endl; //print char array
                        if(isCodeO)
                        {
                            writeDataToFile(fileName);  //if user wants to write to an outfile, print the char array in the outfile
                        }
                        count++;
                        if(count == ENTRIES)
                        {
                            break;
                        }
                    }
                    if (((j-delta)!=last) && (count!=ENTRIES))  //if delta increment exceeds "last" value 
                    {
                        double xValLast = doMath(last, code); //use "last" value for final computation
                        sprintf(funOutput, "Exponential of %.2f: %.2f", last, xValLast); //put output in a char array
                        cout << funOutput << endl; //print char array 
                        if(isCodeO)
                        {
                            writeDataToFile(fileName);  //if user wants to write to an outfile, print the char array in the outfile
                        }
                        count++;
                    }
                }
            }
            if((code == 'l') || (code == 'L')) //if user wants to compute natural log values
            {
                if(!isCodeI)
                {
                    cin >> first >> last >> delta;  //take three user inputs and put them in double variables
                }
                if ((delta <= 0) || (first > last))  //check if computations are needed, if not print a message
                {
                    sprintf(funOutput,"No computation needed.");
                    cout << funOutput << endl;
                    if(isCodeO)
                    {
                        writeDataToFile(fileName);  //if user wants to write to an outfile, print the char array in the outfile
                    }
                }
                else
                { 
                    for (j=first; j<=last; j=j+delta)  //iterate from first to last in steps of delta
                    {
                        double logVal = naturalLog(j);  //compute natural log value of each number
                        sprintf(funOutput, "Natural log of %.2f: %.2f", j, logVal);  //put output in a char array
                        cout << funOutput << endl; //print char array
                        if(isCodeO)
                        {
                            writeDataToFile(fileName);  //if user wants to write to an outfile, print the char array in the outfile
                        }
                        count++;
                        if(count == ENTRIES)
                        {
                            break;
                        }
                    }
                    if (((j-delta)!=last) && (count!=ENTRIES))  //if delta increment exceeds "last" value 
                    {

                        double logValLast = naturalLog(last); //use "last" value for final computation
                        sprintf(funOutput, "Natural log of %.2f: %.2f", last, logValLast); //put output in a char array
                        cout << funOutput << endl; //print char array 
                        if(isCodeO)
                        {
                            writeDataToFile(fileName);  //if user wants to write to an outfile, print the char array in the outfile
                        }
                        count++;
                    }
                }
            }
            if((code == 'y') || (code == 'Y')) //if user wants to compute nyancat values
            {
                if(!isCodeI)
                {
                    cin >> first >> last >> delta;  //take three user inputs and put them in double variables
                }
                if ((delta <= 0) || (first > last))  //check if computations are needed, if not print a message
                {
                    sprintf(funOutput,"No computation needed.");
                    cout << funOutput << endl;
                    if(isCodeO)
                    {
                        writeDataToFile(fileName);  //if user wants to write to an outfile, print the char array in the outfile
                    }
                }
                else
                { 
                    for (j=first; j<=last; j=j+delta)  //iterate from first to last in steps of delta
                    {
                        double ncVal = findNyanCatValue(j);  //compute NyanCat value of each number
                        sprintf(funOutput, "NyanCat value of %.2f: %.2f", j, ncVal);  //put output in a char array
                        cout << funOutput << endl; //print char array
                        if(isCodeO)
                        {
                            writeDataToFile(fileName);  //if user wants to write to an outfile, print the char array in the outfile
                        }
                        count++;
                        if(count == ENTRIES)
                        {
                            break;
                        }
                    }
                    if (((j-delta)!=last) && (count!=ENTRIES))  //if delta increment exceeds "last" value 
                    {
                        double ncValLast = findNyanCatValue(last); //use "last" value for final computation
                        sprintf(funOutput, "NyanCat value of %.2f: %.2f", last, ncValLast); //put output in a char array
                        cout << funOutput << endl; //print char array 
                        if(isCodeO)
                        {
                            writeDataToFile(fileName);  //if user wants to write to an outfile, print the char array in the outfile
                        }
                        count++;
                    }
                }
            }
            if((code == 'd') || (code == 'D')) //if user wants to compute odd numbers
            {
                if(!isCodeI)
                {
                    cin >> firstInt >> lastInt;
                }
                if (firstInt > lastInt)
                {
                    sprintf(funOutput,"No computation needed.");
                    cout << funOutput << endl;
                    if(isCodeO)
                    {
                        writeDataToFile(fileName);  //if user wants to write to an outfile, print the char array in the outfile
                    }
                }
                else
                {
                    int countOdd = 1;
                    for (i = firstInt-1; i <= lastInt; i+=2, countOdd++)
                    {
                        int odd = findNextOddValue(i);
                        if (odd <= lastInt)
                        {
                            sprintf(funOutput, "Odd value %d from %d to %d: %d", countOdd, firstInt, lastInt, odd);
                            cout << funOutput << endl; //print char array 
                            if(isCodeO)
                            {
                                writeDataToFile(fileName);  //if user wants to write to an outfile, print the char array in the outfile
                            }
                            count++;
                            if(count == ENTRIES)
                            {
                                break;
                            }
                        }
                    }
                }
            }

    }while ((code != 'q') && (code != 'Q') && (count != ENTRIES)); //loop until user wants to quit or exceeds number of allowed entries
    delete [](funOutput);
    return 0;
}
