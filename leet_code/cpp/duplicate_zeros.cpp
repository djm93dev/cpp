#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int n = arr.size(); // store the size of the array
        for (int i = 0; i < n; i++) { // loop through the array
            if (arr[i] == 0) { // if the current element is 0
                for (int j = n - 1; j > i; j--) // loop through the array from the end to the current element
                    arr[j] = arr[j - 1]; // shift the elements to the right
                i++; // increment the current element
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