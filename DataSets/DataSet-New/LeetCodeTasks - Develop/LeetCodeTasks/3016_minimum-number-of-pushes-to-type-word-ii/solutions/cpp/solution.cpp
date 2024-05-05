#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>

class Solution {
public:
    int minimumPushes(std::string word) {
        std::unordered_map<char, int> frequency;
        for (char c : word) {
            frequency[c]++;
        }
        
        // Move frequencies to a sortable container
        std::vector<int> freqs;
        for (auto& pair : frequency) {
            freqs.push_back(pair.second);
        }
        
        // Sort frequencies in descending order
        std::sort(freqs.begin(), freqs.end(), std::greater<int>());
        
        int total_pushes = 0;
        int num_keys = 8; // Number of keys from 2 to 9
        
        for (int i = 0; i < freqs.size(); i++) {
            int key_number = i / num_keys + 1; // Determine number of presses required
            total_pushes += key_number * freqs[i];
        }
        
        return total_pushes;
    }
};
