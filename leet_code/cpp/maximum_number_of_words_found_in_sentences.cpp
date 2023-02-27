#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int max = 0;
        for (int i = 0; i < sentences.size(); i++) {
            int count = 0;
            for (int j = 0; j < sentences[i].size(); j++)
                if (sentences[i][j] == ' ')
                    count++;
            if (count > max)
                max = count;
        }
        return max + 1;
        
    }
};

int main()
{
    Solution s;
    vector<string> sentences = { "i love eating burger", "this problem is an easy problem", "i am tired of writing this code" };
    int result = s.mostWordsFound(sentences);
    std::cout << result << std::endl;

}

