#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        vector<int> result;
        
        for (const string& query : wordsQuery) {
            int maxLength = -1;
            int minIndex = -1;
            int minLength = numeric_limits<int>::max();

            for (int i = 0; i < wordsContainer.size(); ++i) {
                const string& containerWord = wordsContainer[i];
                int commonLength = 0;
                int l = containerWord.length() - 1;
                int r = query.length() - 1;
                
                // Calculate longest common suffix length
                while (l >= 0 && r >= 0 && containerWord[l] == query[r]) {
                    ++commonLength;
                    --l;
                    --r;
                }
                
                if (commonLength > maxLength || (commonLength == maxLength && containerWord.length() < minLength) || (commonLength == maxLength && containerWord.length() == minLength && (minIndex == -1 || i < minIndex))) {
                    maxLength = commonLength;
                    minIndex = i;
                    minLength = containerWord.length();
                }
            }
            
            result.push_back(minIndex);
        }
        
        return result;
    }
};
