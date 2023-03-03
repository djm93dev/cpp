#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        if (points.size() < 3) { // If the number of points is less than 3.
            return points.size(); // Return the number of points.
        }
        int max_points = 0; // Create a variable to store the maximum number of points.
        for (int i = 0; i < points.size(); i++) { // Iterate through the points.
            unordered_map<double, int> slopes; // Create a map to store the slopes.
            int duplicates = 0; // Create a variable to store the number of duplicates.
            int verticals = 0; // Create a variable to store the number of verticals.
            int current_max = 0; // Create a variable to store the current maximum number of points.
            for (int j = i + 1; j < points.size(); j++) { // Iterate through the points.
                if (points[i][0] == points[j][0] && points[i][1] == points[j][1]) { // If the points are the same.
                    duplicates++; // Increment the duplicates.
                }
                else if (points[i][0] == points[j][0]) { // If the points are vertical.
                    verticals++; // Increment the verticals.
                }
                else { // If the points are not the same and not vertical.
                    double slope = (double)(points[i][1] - points[j][1]) / (double)(points[i][0] - points[j][0]); // Calculate the slope.
                    slopes[slope]++; // Increment the slope.
                    current_max = max(current_max, slopes[slope]); // Update the current maximum.
                }
            }
            current_max = max(current_max, verticals); // Update the current maximum.
            max_points = max(max_points, current_max + duplicates + 1); // Update the maximum number of points.
        }
        return max_points; // Return the maximum number of points.
    }
};

int main()
{
    vector<vector<int>> points = {{1,1},{2,2},{3,3}};
    Solution s;
    cout << s.maxPoints(points) << endl;
    return 0;
}