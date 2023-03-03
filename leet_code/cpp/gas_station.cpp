#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total = 0; // create a variable to store the total
        int j = -1; // create a variable to store the index
        for (int i = 0, sum = 0; i < gas.size(); ++i) { // for loop to iterate through the gas vector
            sum += gas[i] - cost[i]; // calculate the sum
            total += gas[i] - cost[i]; // calculate the total
            if (sum < 0) { // if the sum is less than 0
                j = i; // set the index to i
                sum = 0; // set the sum to 0
            }
        }
        return total >= 0 ? j + 1 : -1; // return the index
        
    }
};

int main()
{
    Solution s;
    s.canCompleteCircuit();
    return 0;
}