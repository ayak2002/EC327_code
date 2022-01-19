#include <iostream>
#include <iomanip>
#include "FileFunctions.h"
#include "Statistics.h"
using namespace std;

int * DoubleAndReverse (int *list, int size);

int main()
{
    const int N = 4;
    const int M = 5;
    int myArray[1000]; 
    int size = 0;
    WriteRandomData(N, M, "data.txt");  //writes N random numbers ranging from 0 to M to a data.txt
    ReadData("data.txt", size, myArray); //reads the data written to the file and puts it in an array and finds its size
    cout << "Array size is: " << size << endl;  //prints the array's size
    cout << "Doubled and reversed is: [";
    int* doubRev;
    doubRev = DoubleAndReverse (myArray, size); //finds the doubled and reversed array
    int i;
    for (i=0; i<size*2-1; i++)
    {
        cout << *(doubRev + i) << " ";
    }
    cout << *(doubRev + i) << "]" << endl;
    cout << fixed << showpoint;
    cout << "Median is: " << setprecision(1) << getMedian(doubRev, size*2) << endl;  //finds the median of the doubled and reversed array
    cout << "Largest is: " << getLargest(doubRev, size*2) << endl; //finds the largest number of the doubled and reversed array
    return 0;
}

int * DoubleAndReverse (int *list, int size)
{
    int* doubRev = new int [size*2];  //dynamically allocates an array with size 2*original size
    for (int i = 0; i < size; i++)
    {
        *(doubRev + i) = list[i];   //for the first half of the array, copy the elements from the original array into the new one
    }
    int j=1;
    for (int i = size; i < size*2; i++)
    {
        *(doubRev + i) = list[size-j];  //For the second half of the array, copy the elements from the original one in reverse.
        j++;
    }
    return doubRev;
}
