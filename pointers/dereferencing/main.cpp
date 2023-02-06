#include <iostream>

int main()
{
    double testScores[5], sum=0;
    double* pTestScores;
    pTestScores = testScores;
    for (int i=0; i<5; i++)
    {
        std::cout << "Enter test score " << std::endl;
        std::cin >> *(pTestScores+i);
        sum += *(pTestScores+i);

    }
    std::cout << "testScores: " <<testScores << std::endl;
    std::cout << "Total for all students: " << sum << std::endl;
    std::cout << "Average for all students: " << sum/5 << std::endl;


    return 0;
}