#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> indices;
        if (words.empty()) return indices;

        int wordLength = words[0].size();
        int wordCount = words.size();
        int totalLength = wordLength * wordCount;
        if (s.length() < totalLength) return indices;

        unordered_map<string, int> wordFreq;
        for (const string& word : words) {
            ++wordFreq[word];
        }

        for (int i = 0; i < wordLength; ++i) {
            int left = i, right = i, count = 0;
            unordered_map<string, int> seen;
            while (right + wordLength <= s.length()) {
                string word = s.substr(right, wordLength);
                right += wordLength;
                if (wordFreq.find(word) != wordFreq.end()) {
                    ++seen[word];
                    ++count;
                    while (seen[word] > wordFreq[word]) {
                        string leftWord = s.substr(left, wordLength);
                        --seen[leftWord];
                        --count;
                        left += wordLength;
                    }
                    if (count == wordCount) {
                        indices.push_back(left);
                        string leftWord = s.substr(left, wordLength);
                        --seen[leftWord];
                        --count;
                        left += wordLength;
                    }
                } else {
                    seen.clear();
                    count = 0;
                    left = right;
                }
            }
        }
        return indices;
    }
};
