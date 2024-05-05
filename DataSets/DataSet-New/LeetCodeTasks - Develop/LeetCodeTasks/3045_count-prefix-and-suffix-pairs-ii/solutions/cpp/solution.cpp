#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    long long countPrefixSuffixPairs(vector<string>& words) {
        unordered_map<string, int> prefixSuffixCount;
        long long result = 0;
        
        for (const string& word : words) {
            for (int len = 1; len <= word.length(); ++len) {
                string sub = word.substr(0, len);
                if (sub == word.substr(word.length() - len)) {
                    result += prefixSuffixCount[sub];
                }
            }
            prefixSuffixCount[word]++;
        }
        
        return result;
    }
};
