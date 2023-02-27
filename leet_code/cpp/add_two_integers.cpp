#include <iostream>

class Solution {
public:
    int sum(int num1, int num2) {
        int sum = num1 + num2;
        return sum;
        
    }
};

int main()
{
    Solution s;
    int num1 = 5;
    int num2 = 10;
    int result = s.sum(num1, num2);
    std::cout << result << std::endl;

}