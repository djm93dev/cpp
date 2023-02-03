#include <iostream>

using namespace std;

int main()
{
    char inital = 'P';
    char* pInital = &inital;

    cout << "Memory address of inital P: " << (void *)pInital << endl; // (void *) is a cast to void pointer
    cout << "Memory address of inital P: " << static_cast <void *>(pInital) << endl; // static_cast is a cast to void pointer

    const char* pans{ "The answer is " };
    const char* pans1{ "Yes" };
    const char* pans2{ "No" };
    const char* pans3{ "Maybe" };
    const char* pans4{ "Ask again later" };


    int choice;

    cout << "Enter a number between 1 and 4: ";
    cin >> choice;
    switch (choice)
    {
    case 1:
        cout << pans << pans1 << endl;
        break;
    case 2:
        cout << pans << pans2 << endl;
        break;
    case 3:
        cout << pans << pans3 << endl;
        break;
    case 4:
        cout << pans << pans4 << endl;
        break;
    default:
        cout << "You did not enter a number between 1 and 4" << endl;
        break;
    }
    
}