#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxPalindromesAfterOperations(vector<string>& words) {
        int totalEven = 0;  // Total count of pairs we can make from all letters
        unordered_map<char, int> freq;  // Frequency of each character across all strings
        
        // Collect total frequency of each character
        for (const string& word : words) {
            unordered_map<char, int> localFreq;
            for (char c : word) {
                localFreq[c]++;
            }
            for (auto& [ch, count] : localFreq) {
                freq[ch] += count;
            }
        }
        
        // Calculate total even counts (pairs)
        for (auto& [ch, count] : freq) {
            totalEven += count / 2;
        }
        
        int wordsPossible = 0;
        int totalWords = words.size();
        int totalCharsNeeded = 0;  // Total characters needed to make all words palindromic

        for (const string& word : words) {
            int n = word.length();
            unordered_map<char, int> localFreq;
            for (char c : word) {
                localFreq[c]++;
            }
            int oddCount = 0;  // Count of characters with an odd frequency in this word
            for (auto& [ch, count] : localFreq) {
                if (count % 2 != 0) {
                    oddCount++;
                }
            }
            totalCharsNeeded += std::max(0, oddCount - 1);  // We need oddCount - 1 additional characters to be even
        }

        // We can make each word a palindrome if we can supply the necessary even characters
        // to pair up the odd ones from the total pool of even pairs.
        wordsPossible = std::min(totalWords, totalEven - totalCharsNeeded + totalWords);
        
        return wordsPossible;
    }
};
