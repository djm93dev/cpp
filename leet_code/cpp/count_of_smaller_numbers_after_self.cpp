#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:
    void merge(vector<int> &count, vector<pair<int, int> > &v, int left, int mid, int right) {
        vector<pair<int, int> > tmp(right-left+1); // tmp is a vector of pairs of ints
        int i = left; // set i to left
        int j = mid+1; // set j to mid + 1
        int k = 0; // set k to 0

        while (i <= mid && j <= right) { // while i is less than or equal to mid and j is less than or equal to right
            // mind that we're sorting in descending order
            if (v[i].first <= v[j].first) {  // if v[i].first is less than or equal to v[j].first
                tmp[k++] = v[j++]; // set tmp[k] to v[j] and increment j and k
            }
            else {
                // only line responsible to update count, related to problem constraint, 
                // remaining part is just regular mergeSort 
                count[v[i].second] += right - j + 1; // set count[v[i].second] to count[v[i].second] + right - j + 1
                tmp[k++] = v[i++]; // set tmp[k] to v[i] and increment i and k
            }
        }
        while (i <= mid) { // while i is less than or equal to mid
            tmp[k++] = v[i++]; // set tmp[k] to v[i] and increment i and k
        }
        while (j <= right) { // while j is less than or equal to right
            tmp[k++] = v[j++]; // set tmp[k] to v[j] and increment j and k
        }
        for (int i = left; i <= right; i++) // for each int i in left to right
            v[i] = tmp[i-left]; // set v[i] to tmp[i-left]
    }        

    void mergeSort(vector<int> &count, vector<pair<int, int> > &v, int left, int right) { // mergeSort function
        if (left >= right)  // if left is greater than or equal to right
            return; // return

        int mid = left + (right-left)/2; // set mid to left + (right-left)/2
        mergeSort(count, v, left, mid); // call mergeSort with count, v, left, mid
        mergeSort(count, v, mid+1, right); // call mergeSort with count, v, mid+1, right
        merge(count, v, left, mid, right); // call merge with count, v, left, mid, right
    }

    vector<int> countSmaller(vector<int>& nums) { // countSmaller function
        int N = nums.size(); // set N to nums.size()

        vector<pair<int, int> > v(N); // set v to a vector of pairs of ints with size N
        for (int i = 0; i < N; i++) // for each int i in 0 to N   
            v[i] = make_pair(nums[i], i); // set v[i] to make_pair(nums[i], i)

        vector<int> count(N, 0); // set count to a vector of ints with size N and all values set to 0
        // sorting in descending order
        mergeSort(count, v, 0, N-1); // call mergeSort with count, v, 0, N-1

        return count; // return count
    }
};

int main() {
    Solution s;
    vector<int> nums = {5,2,6,1};
    vector<int> res = s.countSmaller(nums);
    for (int i : res) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}