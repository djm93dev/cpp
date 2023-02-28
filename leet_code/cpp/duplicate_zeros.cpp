#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int n = arr.size();
        for (int i = 0; i < n; i++) {
            if (arr[i] == 0) {
                for (int j = n - 1; j > i; j--)
                    arr[j] = arr[j - 1];
                i++;
            }
        }
        

        
    }
};

int main() {
    Solution solution;
    vector<int> arr = { 1, 0, 2, 3, 0, 4, 5, 0 };
    solution.duplicateZeros(arr);
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    return 0;
}