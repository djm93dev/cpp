#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        map<string, int> m1;
        for (int i = 0; i < list1.size(); i++)
            m1[list1[i]] = i;
        vector<string> answer;
        int min_index_sum = INT_MAX;
        for (int i = 0; i < list2.size(); i++)
            if (m1.find(list2[i]) != m1.end())
            {
                if (m1[list2[i]] + i < min_index_sum)
                {
                    min_index_sum = m1[list2[i]] + i;
                    answer.clear();
                    answer.push_back(list2[i]);
                }
                else if (m1[list2[i]] + i == min_index_sum)
                    answer.push_back(list2[i]);
            }
        return answer;
        
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