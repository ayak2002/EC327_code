#include <iostream>
#include <fstream>
#include <ctime>
using namespace std;


void WriteRandomData(int N, int M, const char *filename)
{
    ofstream myFile;
    myFile.open(filename);
    if (!myFile.is_open())    //checks if file is open, if not prints a message
    {
        cout << "File could not be opened." << endl;
    }
    srand(time(NULL));   //seeds the rand function
    cout << "Writing file: " << filename << endl;
    for(int i = 0; i < N; i++)   //loops N times to print N numbers to the file
    {
        int randInt = rand() % (M+1);   //gets a random integer from 0 to M (inclusive)
        myFile << randInt << endl;
    }
}

void ReadData(const char *filename, int &size, int myArray[])
{
    int num;
    ifstream myFile;
    myFile.open(filename);
    if (!myFile.is_open())    //checks if file is open, if not prints a message
    {
        cout << "File could not be opened." << endl;
    }
    cout << "Reading file: " << filename << endl;
    size = 0;
    while (myFile >> num)     //counts how many lines are in the file (which is also the number of elements of the array)
    {
        size++;
    }
    myFile.clear();   
    myFile.seekg(0);         //goes back to the top of the file
    for (int i = 0; i < size; i++)
    {
        myFile >> myArray[i];   //puts every element of the file in the array
    }

}