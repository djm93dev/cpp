#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        string shuffled; // to store the shuffled string
        for (int i = 0; i < s.size(); i++) // loop through the s string
            for (int j = 0; j < s.size(); j++) // loop through the indices vector
                if (indices[j] == i) // if the index of the indices vector is equal to the index of the s string
                    shuffled += s[j]; // add the character of the s string to the shuffled string
        return shuffled;
        
    }
};

int main()
{
    Solution s;
    string s1 = "codeleet";
    vector<int> indices = { 4,5,6,7,0,2,1,3 };
    string result = s.restoreString(s1, indices);
    std::cout << result << std::endl;

}