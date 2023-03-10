#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;


class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int>> result; // initialize result vector
        vector<pair<int, int>> heights; // initialize heights vector
        for (auto building : buildings) {   // for each building
            heights.push_back({building[0], -building[2]});  // push back the left edge and the height of the building as a negative number to the heights vector
            heights.push_back({building[1], building[2]});  // push back the right edge and the height of the building to the heights vector
        }
        sort(heights.begin(), heights.end()); // sort the heights vector by the first element of the pair
        multiset<int> m; // initialize a multiset
        m.insert(0); // insert 0 into the multiset
        int prev = 0; // initialize prev to 0
        for (auto h : heights) { // for each pair in the heights vector
            if (h.second < 0) { // if the second element of the pair is negative
                m.insert(-h.second); // insert the negative second element into the multiset
            } else { // if the second element of the pair is positive
                m.erase(m.find(h.second)); // erase the second element from the multiset
            }
            int cur = *m.rbegin(); // set cur to the last element of the multiset
            if (cur != prev) { // if cur is not equal to prev
                result.push_back({h.first, cur}); // push back the first element of the pair and cur into the result vector
                prev = cur; // set prev to cur
            }
        }
        return result; // return the result vector
    }
};

int main() {
    Solution s;
    vector<vector<int>> buildings = {{2,9,10},{3,7,15},{5,12,12},{15,20,10},{19,24,8}};
    vector<vector<int>> result = s.getSkyline(buildings);
    for (auto v : result) {
        for (auto i : v) {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}