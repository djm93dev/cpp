#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        int count = 0; // initialize count to 0
        vector<bool> primes(n, true); // create a vector of booleans and set all elements to true
        for (int i = 2; i < n; i++) { // loop through the vector
            if (primes[i]) { // if the current element is true
                count++; // increment count
                for (int j = 2; i * j < n; j++) { // loop through the vector
                    primes[i * j] = false; // set the element at i * j to false
                }
            }
        }
        return count; // return count
        
    }
};

int main()
{
    Solution s;
    cout << s.countPrimes(10) << endl;
    return 0;
}