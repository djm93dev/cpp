#include <iostream>

int main()
{
    int* pointer(new int(55)); // allocate an integer
    std::cout << "Value: " << *pointer << std::endl;
    delete pointer; // delete the integer
    int* pArray(new int[5]{ 1, 2, 3, 4, 5 }); // allocate an array of 5 integers
    *(pArray+1) += 10; // add 10 to the second element of the array
    std::cout << "Value: " << *pArray << "," << *(pArray+1) << std::endl;
    delete pArray; // delete the array

    return 0;
}