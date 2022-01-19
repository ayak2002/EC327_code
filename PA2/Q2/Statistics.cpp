#include <iostream>
using namespace std;

double getMedian(int intArray[], int size)
{
    double median;
    for (int i=0; i< size; i++)
    {
        {
            for (int j=i+1; j < size; j++)
            {
                if (intArray[i] > intArray[j])
                {
                   int temp = intArray[i];      //rearranges the elements of the array in ascending order by swapping elements
                   intArray[i]= intArray[j];
                   intArray[j] = temp;
                }
            }
        }
    }
    if ((size % 2) == 0)    //if array has an even number of elements
    {
        median = (intArray[size/2] + intArray[(size/2)-1])/2.0
        ;
    }
    else    //if array has an odd number of elements
    {
        median = intArray[size/2];
    }
    return median;
}

int getLargest (int intArray[], int size)
{
    int largest = intArray[0];    //sets largest to first element
    for (int i=1; i<size; i++)    //loops across all elements of the array 
    {
        if (largest < intArray[i])
        {
            largest = intArray[i];   //if current element is bigger than current largest, current element becomes the largest
        }
    }
    return largest;
}