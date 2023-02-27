#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int max = 0; // max number of words in a sentence
        for (int i = 0; i < sentences.size(); i++) { // loop through each sentence
            int count = 0; // number of words in a sentence
            for (int j = 0; j < sentences[i].size(); j++) // loop through each character in a sentence
                if (sentences[i][j] == ' ') // if a space is found, increment count
                    count++; 
            if (count > max) // if count is greater than max, set max to count
                max = count; // max is the max number of words in a sentence
        }
        return max + 1; // return max + 1 because the number of words is 1 more than the number of spaces
        
    }
};

int main()
{
    Solution s;
    vector<string> sentences = { "i love eating burger", "this problem is an easy problem", "i am tired of writing this code" };
    int result = s.mostWordsFound(sentences);
    std::cout << result << std::endl;

}

