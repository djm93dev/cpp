#include <iostream>

double averageCost(double* priceArray, int* count)
{
    double sum = 0;
    for(int i = 0; i < *count; i++)
    {
        sum += *(priceArray + i);
    }
    double avg = sum / *count;
    *count += 5;
    std::cout << "Count: " << *count << std::endl;
    return avg;
}

int main()
{
    double prices[5]{ 1.99, 2.99, 3.99, 4.99, 5.99 };
    int quantity = 5;
    double average = averageCost(prices, &quantity);
    std::cout << "Average price: $" << average << std::endl;
    std::cout << "Quantity value: " << quantity << std::endl;

    return 0;
}