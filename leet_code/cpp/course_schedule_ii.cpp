#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses, vector<int>()); // initialize a 2D vector with numCourses rows and 0 columns
        vector<int> inDegree(numCourses, 0);  // initialize a 1D vector with numCourses elements and 0 value
        for (auto& p : prerequisites) { // for each vector<int> in prerequisites
            graph[p[1]].push_back(p[0]); // add p[0] to the end of graph[p[1]]
            inDegree[p[0]]++; // increment inDegree[p[0]]
        }
        vector<int> queue; // initialize a 1D vector with 0 elements
        for (int i = 0; i < numCourses; i++) { // for each element in inDegree
            if (inDegree[i] == 0) { // if inDegree[i] is 0
                queue.push_back(i); // add i to the end of queue
            }
        }
        vector<int> result; // initialize a 1D vector with 0 elements
        while (!queue.empty()) { // while queue is not empty
            int node = queue.back(); // set node to the last element in queue
            queue.pop_back(); // remove the last element in queue
            result.push_back(node); // add node to the end of result
            for (auto& n : graph[node]) { // for each element in graph[node]
                inDegree[n]--; // decrement inDegree[n]
                if (inDegree[n] == 0) { // if inDegree[n] is 0
                    queue.push_back(n); // add n to the end of queue
                }
            }
        }
        return (result.size() == numCourses) ? result : vector<int>(); // return result if result.size() is equal to numCourses, otherwise return an empty vector
        
    }
};

int main() {
    Solution s;
    vector<vector<int>> prerequisites = {{1,0},{0,1}};
    cout << s.findOrder(2, prerequisites) << endl;
    return 0;
}