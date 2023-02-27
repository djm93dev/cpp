#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int, int> m;
        for (int i = 0; i < arr.size(); i++)
            m[arr[i]]++;
        vector<int> v;
        for (auto it = m.begin(); it != m.end(); it++)
            v.push_back(it->second);
        sort(v.begin(), v.end());
        for (int i = 0; i < v.size() - 1; i++) {
            if (v[i] == v[i + 1])
                return false;
        }
        cout << "v: ";
        for (auto i : v)
            cout << i << " ";
        cout << endl;
        return true;
        
    }
};

int main()
{
    Solution s;
    vector<int> v = {1, 2, 2, 1, 1, 3};
    cout << s.uniqueOccurrences(v) << endl;
    return 0;
}