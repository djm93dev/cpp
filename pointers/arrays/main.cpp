#include <iostream>

using namespace std;

int main()
{
    double values[10]; // array of 10 doubles
    double* pValue = values; // pointer to the first element of the array
    cout << "value array address: " << values << endl;
    cout << "pValue array address: " << pValue << endl;

    int numbers[10];
    int* pNumbers = numbers;

    for(int i=0; i<10; i++)
    {
        cout << "numbers[" << i << "] = " << pNumbers + i << endl; // each element is 4 bytes apart
    }

    return 0;
}