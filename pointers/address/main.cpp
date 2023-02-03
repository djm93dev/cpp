#include <iostream>

using namespace std;

int main()
{
    int number = 240; // number is an integer variable
    int* numPtr; // numPtr is a pointer to an integer
    numPtr = &number; // numPtr is assigned the address of number

    cout << "The address of number is: " << numPtr << endl;

    double number2 = 240.5; // number2 is a double variable
    // numPtr = &number2; // cannot assign a double* to an int*

    return 0;
}