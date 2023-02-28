#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        for (int i = 0; i < image.size(); i++) // loop trough rows
            for (int j = 0; j < image.size(); j++) // loop trough columns
                if (j < image.size() / 2) // if j is less than half of the size of the row
                    swap(image[i][j], image[i][image.size() - j - 1]); // swap the values of the first and last element of the row
        for (int i = 0; i < image.size(); i++) // loop trough rows
            for (int j = 0; j < image.size(); j++) // loop trough columns
                if (image[i][j] == 0) // if the value is 0
                    image[i][j] = 1; // change it to 1
                else 
                    image[i][j] = 0; // else change it to 0
        return image; // return the image
    }
};

int main() {
    Solution solution;
    vector<vector<int>> image = { {1, 1, 0}, {1, 0, 1}, {0, 0, 0} };
    vector<vector<int>> result = solution.flipAndInvertImage(image);
    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result.size(); j++)
            cout << result[i][j] << " ";
        cout << endl;
    }
    return 0;
}