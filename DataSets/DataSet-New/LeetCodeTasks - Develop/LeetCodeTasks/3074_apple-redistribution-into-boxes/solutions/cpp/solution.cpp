#include <vector>
#include <algorithm>

class Solution {
public:
    int minimumBoxes(std::vector<int>& apple, std::vector<int>& capacity) {
        int totalApples = 0;
        for (int apples : apple) {
            totalApples += apples;
        }

        std::sort(capacity.rbegin(), capacity.rend());  // Sort in decreasing order
        
        int boxesUsed = 0;
        int currentCapacity = 0;
        for (int cap : capacity) {
            currentCapacity += cap;
            boxesUsed++;
            if (currentCapacity >= totalApples) {
                break;
            }
        }
        
        return boxesUsed;
    }
};
