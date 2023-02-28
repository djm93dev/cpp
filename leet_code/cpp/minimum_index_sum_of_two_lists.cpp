#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        map<string, int> m1; // map to hold the index of each restaurant in list1
        for (int i = 0; i < list1.size(); i++) // populate the map
            m1[list1[i]] = i; // the value of the map is the index of the restaurant in list1
        vector<string> answer; // vector to hold the answer
        int min_index_sum = INT_MAX; // variable to hold the minimum index sum
        for (int i = 0; i < list2.size(); i++) // iterate through list2
            if (m1.find(list2[i]) != m1.end()) // if the restaurant is in list1
            {
                if (m1[list2[i]] + i < min_index_sum) // if the index sum is less than the current minimum
                {
                    min_index_sum = m1[list2[i]] + i; // update the minimum index sum
                    answer.clear(); // clear the answer vector
                    answer.push_back(list2[i]); // add the restaurant to the answer vector
                }
                else if (m1[list2[i]] + i == min_index_sum) // if the index sum is equal to the current minimum
                    answer.push_back(list2[i]); // add the restaurant to the answer vector
            }
        return answer; // return the answer vector
        
    }
};

int main () {
    Solution s;
    vector<string> list1 = {"Shogun", "Tapioca Express", "Burger King", "KFC"};
    vector<string> list2 = {"Piatti", "The Grill at Torrey Pines", "Hungry Hunter Steakhouse", "Shogun"};
    vector<string> answer = s.findRestaurant(list1, list2);
    for (int i = 0; i < answer.size(); i++)
        cout << answer[i] << endl;
    return 0;
}