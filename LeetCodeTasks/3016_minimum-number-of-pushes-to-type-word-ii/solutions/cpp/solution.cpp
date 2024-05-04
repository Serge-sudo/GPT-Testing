#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minimumPushes(string word) {
        unordered_map<char, int> keypad = {
            {'a', 2}, {'b', 3}, {'c', 4},
            {'d', 5}, {'e', 6}, {'f', 7},
            {'g', 8}, {'h', 9}, {'i', 9},
            {'j', 10}, {'k', 11}, {'l', 12},
            {'m', 13}, {'n', 14}, {'o', 15},
            {'p', 16}, {'q', 17}, {'r', 18},
            {'s', 19}, {'t', 20}, {'u', 21},
            {'v', 22}, {'w', 23}, {'x', 24},
            {'y', 25}, {'z', 26}
        };
        
        int pushes = 0;
        char prev_key = ' ';
        for (char c : word) {
            int key = keypad[c];
            if (prev_key == ' ' || key == prev_key)
                pushes++;
            else if (key > prev_key)
                pushes += key - prev_key;
            else
                pushes += prev_key - key;
            prev_key = key;
        }
        
        return pushes;
    }
};
