#include <iostream>

// goto statement

int main()
{
    for (int i = 0; i < 5; i++)
    {
        std::cout << i << std::endl;
        if (i == 3)
        {
            goto end; // jump to the end of the loop when i is 3
        }
    }
    
    end: // end of the loop is marked with a label
    return 0;
}