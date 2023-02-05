#include <iostream>

// continue statement

int main()
{
    for (int i = 0; i < 5; i++)
    {
        if (i == 3)
        {
            continue; // skip the rest of the loop body when i is 3
        }
        std::cout << i << std::endl;
    }

    return 0;
}