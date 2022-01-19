#include <iostream>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <cstring>
#include <string.h>
#include <cassert>
using namespace std;

const int ENTRIES = 10;
char* funOutput = new char [100];
int commandCount;
char* commArr = NULL;
int* intArr = NULL;
double* doubArr = NULL;
char** fileArr = NULL;


void initialize()
{
    cout << "EC327: Introduction to Software Engineering" << endl;
    cout << "Fall 2021" <<  endl;
    cout << "Programming Assignment 2" << endl;
    cout << "Value of Entries is: " << ENTRIES << endl;
    return;
}

bool checkCode(char code)
{
    bool valid = 0;
    char validChars[] = {'F', 'f', 'B', 'b',
    'R', 'r', 'U', 'u', 'C', 'c', 'E', 'e', 'K', 'k',
    'S', 's', 'N', 'n', 'X', 'x', 'L', 'l', 'Y','y',
    'D', 'd', 'I', 'i', 'O', 'o', 'Q', 'q', '\0'};
   
   for (int i = 0; i < strlen(validChars); i++)
   {
       if(validChars[i] == code)
       {
           valid = 1;
       }
   }
    return valid;
} 

void writeDataToFile(const char * fileName)
{
    ofstream myFile;
    myFile.open(fileName, ios::out | ios::app);
    if(!myFile.is_open())
    {
        cout << "File could not be opened. " << endl;
    }
    else 
    {
        myFile << funOutput << endl;
        myFile.close();
    }
    return;
}

void readDataFromFile(const char * fileName)
{
    int lineCount=0;
    commandCount=0;
    int intParamCount=0;
    int doubParamCount=0;
    int fileParamCount=0;
    bool isCodeQ=0;
    ifstream myFile;
    myFile.open(fileName);
    if(!myFile.is_open())
    {
        cout << "File could not be opened. " << endl;
    }
    else
    {
        char command;
        string myString;
        while((getline(myFile,myString)) && (isCodeQ == 0))
        {
            lineCount++;
            command = myString[0];
            if((lineCount % 2) != 0)
            {
                commandCount++;
                if((command == 'q') || (command == 'Q'))
                {
                    isCodeQ == 1;
                    break;
                }
                else if ((command == 'f')||(command == 'F')||(command == 'b')||(command == 'B'))
                {
                    intParamCount++;
                }
                else if((command == 'd')||(command == 'D')||(command == 'e')||(command == 'E'))
                {
                    intParamCount+=2;
                }
                else if((command == 'o')||(command == 'O'))
                {
                    fileParamCount++;
                }
                else
                {
                    doubParamCount+=3;
                }
            }
        }
        commArr = new char [commandCount];
        intArr = new int [intParamCount];
        doubArr = new double [doubParamCount];
        fileArr = new char* [fileParamCount];
        for (int i = 0; i < fileParamCount; i++)
        {
            fileArr[i] = new char [100];
        }
        myFile.clear();
        myFile.seekg(0);
        int i=0;
        int j=0;
        int intCount = 0;
        int doubCount = 0;
        int fileCount = 0;
        for (int line = 0; line < lineCount; line++)
        {
            if ((line % 2) == 0)
            {
                 myFile >> commArr[line-i];
                 i++;
            }
            else 
            {
                j++;
                if ((commArr[line-j] == 'f')||(commArr[line-j] == 'F')||(commArr[line-j] == 'b')||(commArr[line-j] == 'B'))
                {
                    myFile >> intArr[intCount];
                    intCount++;
                }
                else if ((commArr[line-j] == 'e')||(commArr[line-j] == 'E')||(commArr[line-j] == 'd')||(commArr[line-j] == 'D'))
                {
                    myFile >> intArr[intCount] >> intArr[intCount+1];
                    intCount+=2;
                }
                else if ((commArr[line-j] == 'o')||(commArr[line-j] == 'O'))
                {
                    string myLine;
                    myFile >> myLine;
                    for(int i=0; i<myLine.length();i++)
                    {
                        *(fileArr[fileCount]+i) = myLine[i];
                    }
                    fileCount++;
                }
                else 
                {
                    myFile >> doubArr[doubCount] >> doubArr[doubCount+1] >> doubArr[doubCount+2];
                    doubCount+=3;
                }
            }
        }
    }
    myFile.close();
    return;
}



int factorial (int num)
{
    int fact = 1;
    for (int i = 1; i <= num; i++)
    {
        fact = fact * i;
    }
    return fact;
}


int fibonacci(int i) 
{
    int* fibNum = new int [i];
    if (i == 0 || i == 1)
    {
        fibNum[i]= i;
    }
    else 
    {
        fibNum[i] = fibonacci(i - 1) + fibonacci(i - 2);
    }
    return fibNum[i];
}

double findSqrtValue(double num)
{
    return sqrt(num);
}

double naturalLog(double num)
{
    return log(num);
}

double areaCircle(double radius)
{
    const double PI = 3.14159;
    double area = PI * radius * radius;
    return area;
}

double areaSquare(double side)
{
    return side * side;
}

int findNextOddValue(int num)
{
    int i = num + 1;
    while ((i % 2) != 1)
    {
        i++;
    }
    return i;
}

int findNextEvenValue(int num)
{
    int i = num + 1;
    while ((i % 2) != 0)
    {
        i++;
    }
    return i;
}

double findNyanCatValue(double num)
{
    double result = pow((4*num),num) + num + 10;
    return result;
}

double doMath(double num, char code)
{
    double result;
    if ((code == 's') || (code == 'S'))
    {
        result = sin(num);
    }
    else if ((code == 'n') || (code == 'N'))
    {
        result = cos(num);
    }
    else if((code == 'x') || (code == 'X'))
    {
        result = exp(num);
    }
    return result;
}

double lucky(double randSeed)
{
    srand(static_cast<unsigned int> (randSeed));
    return (static_cast <double> (rand()) / static_cast <double> (rand())) ;
}