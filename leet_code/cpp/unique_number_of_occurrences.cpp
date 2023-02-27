#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int, int> m; // key: number, value: count
        for (int i = 0; i < arr.size(); i++) // count the number of occurrences
            m[arr[i]]++; // if the key is not in the map, it will be added
        vector<int> v; // store the number of occurrences
        for (auto it = m.begin(); it != m.end(); it++) // traverse the map
            v.push_back(it->second); // store the number of occurrences
        sort(v.begin(), v.end()); // sort the vector
        for (int i = 0; i < v.size() - 1; i++) { // check if there are duplicates
            if (v[i] == v[i + 1]) // if there are duplicates
                return false; // return false
        }
        return true; // return true
        
    }
};

int main()
{
    Solution s;
    vector<int> v = {1, 2, 2, 1, 1, 3};
    cout << s.uniqueOccurrences(v) << endl;
    return 0;
}