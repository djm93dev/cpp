#include <iostream>

using namespace std;

class Solution {
public:
    int addDigits(int num) {
        int sum = 0;
        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }
        if (sum < 10) {
            return sum;
        } else {
            return addDigits(sum);
        }
        
    }
};

int main() {
    Solution s;
    cout << s.addDigits(38) << endl;
    return 0;
}