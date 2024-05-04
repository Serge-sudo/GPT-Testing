#include <unordered_map>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minimumPushes(string word) {
        unordered_map<char, pair<int, int>> keypad = {
            {'a', {0, 0}}, {'b', {0, 1}}, {'c', {0, 2}},
            {'d', {1, 0}}, {'e', {1, 1}}, {'f', {1, 2}},
            {'g', {2, 0}}, {'h', {2, 1}}, {'i', {2, 2}},
            {'j', {3, 0}}, {'k', {3, 1}}, {'l', {3, 2}},
            {'m', {4, 0}}, {'n', {4, 1}}, {'o', {4, 2}},
            {'p', {5, 0}}, {'q', {5, 1}}, {'r', {5, 2}}, {'s', {5, 3}},
            {'t', {6, 0}}, {'u', {6, 1}}, {'v', {6, 2}},
            {'w', {7, 0}}, {'x', {7, 1}}, {'y', {7, 2}}, {'z', {7, 3}}
        };
        
        int pushes = 0;
        pair<int, int> current = {0, 0};
        
        for (char c : word) {
            auto target = keypad[c];
            pushes += abs(target.first - current.first) + abs(target.second - current.second) + 1;
            current = target;
        }
        
        return pushes;
    }
};
