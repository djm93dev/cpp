#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> result; // initialize the result vector
        if (intervals.size() == 0) // if the input vector is empty, return the result vector
            return result; // return the result vector
        sort(intervals.begin(), intervals.end()); // sort the input vector
        vector<int> temp = intervals[0]; // initialize the temp vector
        for (int i = 1; i < intervals.size(); i++) { // iterate through the input vector
            if (intervals[i][0] <= temp[1]) // if the start of the current interval is less than or equal to the end of the previous interval
                temp[1] = max(intervals[i][1], temp[1]); // update the end of the previous interval
            else {
                result.push_back(temp); // push the previous interval into the result vector
                temp = intervals[i]; // update the temp vector
            }
        }
        result.push_back(temp); // push the last interval into the result vector
        return result; // return the result vector

    }
};

int main() {
    vector<vector<int>> intervals = {{1,3},{2,6},{8,10},{15,18}};
    Solution sol;
    vector<vector<int>> result = sol.merge(intervals);
    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++)
            cout << result[i][j] << " ";
        cout << endl;
    }
    return 0;
}