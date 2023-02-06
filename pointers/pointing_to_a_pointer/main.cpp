#include <iostream>

int main()
{
    // int num = 10;
    // int* pNum = &num;
    // int** p2Num = &pNum;

    // std::cout << "&num: " << &num << std::endl;
    // std::cout << "pNum: " << pNum << std::endl;
    // std::cout << "&p2Num: " << &pNum << std::endl;
    // std::cout << "p2Num: " << p2Num << std::endl;

    int testScores[5]{ 100, 90, 80, 70, 60 };

    int* pointerArray[5];
    for(int i = 0; i < 5; i++)
    {
        pointerArray[i] = &testScores[i]; // assign the address of each element to the pointer array
        std::cout << pointerArray[i] << std::endl; // print the address of each element
        std::cout << *(pointerArray[i]) << std::endl; // print the value of each element with dereferencing
        std::cout << *(pointerArray + i) << std::endl; // print the address of each element with pointer arithmetic
        std::cout << **(pointerArray + i) << std::endl; // print the value of each element with pointer arithmetic and dereferencing
    }
    return 0;
}