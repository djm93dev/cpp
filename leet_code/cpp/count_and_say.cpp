#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        string ans = "1"; // initialize the result string to 1
        for(int i = 1; i < n; i++){ // iterate through the numbers 1 to n
            string temp = ""; // initialize a temporary string
            int count = 1; // initialize a count variable to 1
            for(int j = 0; j < ans.size(); j++){ // iterate through the result string
                if(ans[j] == ans[j + 1]) // if the current element is equal to the next element
                    count++; // increment the count
                else{ // otherwise
                    temp += to_string(count) + ans[j]; // add the count and the current element to the temporary string
                    count = 1; // reset the count to 1
                }
            }
            ans = temp; // set the result string to the temporary string
        }
        return ans; // return the result string
        
    }
};

int main(){
    int n = 4;
    Solution s;
    cout << s.countAndSay(n) << endl;
    return 0;
}