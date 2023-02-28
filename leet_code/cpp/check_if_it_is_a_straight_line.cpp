#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        for (int i = 0; i < coordinates.size(); i++) // loop through the array
            for (int j = i + 1; j < coordinates.size(); j++) // loop through the array from the current element to the end
                if ((coordinates[j][1] - coordinates[i][1]) * (coordinates[j][0] - coordinates[0][0]) != (coordinates[j][1] - coordinates[0][1]) * (coordinates[j][0] - coordinates[i][0])) // if the slope of the line between the current element and the first element is not equal to the slope of the line between the current element and the next element 
                    return false; // return false
        return true; // return true
            
        
    }
};

int main() {
    Solution solution;
    vector<vector<int>> coordinates = { {1, 2}, {2, 3}, {3, 4}, {4, 5}, {5, 6}, {6, 7} };
    cout << solution.checkStraightLine(coordinates);
    return 0;
}