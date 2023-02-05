#include <iostream>

// break statement

int main()
{
    for (int i = 0; i < 5; i++)
    {
        std::cout << i << std::endl;
        if (i == 3)
        {
            break; // break out of the loop when i is 3
        }
    }
    
    return 0;
}