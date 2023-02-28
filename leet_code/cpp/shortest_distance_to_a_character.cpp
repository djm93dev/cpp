#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        vector<int> answer;
        for (int i = 0; i < s.size(); i++) // loop through the string
            if (s[i] == c) { // if the character is the target character
                answer.push_back(0); // push 0 to the answer vector
                continue; // continue to the next iteration
            } else { // if the character is not the target character
                int left = 0, right = 0; // initialize left and right to 0
                for (int j = i; j >= 0; j--) // loop from the current index to the beginning of the string
                    if (s[j] == c) { // if the character is the target character
                        left = i - j; // set left to the distance between the current index and the target character
                        break; // break out of the loop
                    }
                for (int j = i; j < s.size(); j++) // loop from the current index to the end of the string
                    if (s[j] == c) { // if the character is the target character
                        right = j - i; // set right to the distance between the current index and the target character
                        break; // break out of the loop
                    }
                if (left == 0) // if left is 0, push right to the answer vector
                    answer.push_back(right); 
                else if (right == 0) // if right is 0, push left to the answer vector
                    answer.push_back(left);
                else
                    answer.push_back(min(left, right)); // push the minimum of left and right to the answer vector
            } 
            
        return answer; // return the answer vector
    }
};

int main() {
    Solution s;
    vector<int> answer = s.shortestToChar("loveleetcode", 'e');
    for (int i = 0; i < answer.size(); i++)
        cout << answer[i] << " ";
    cout << endl;
    return 0;
}