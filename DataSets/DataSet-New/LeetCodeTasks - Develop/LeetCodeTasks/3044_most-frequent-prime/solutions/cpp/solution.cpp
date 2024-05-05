#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int mostFrequentPrime(vector<vector<int>>& mat) {
        vector<int> directions = {-1, 0, 1}; // Used to generate the 8 possible movement directions
        int m = mat.size(), n = mat[0].size();
        unordered_map<int, int> primeCounts;

        // Helper function to check if a number is prime
        auto isPrime = [](int num) -> bool {
            if (num <= 1) return false;
            if (num <= 3) return true;
            if (num % 2 == 0 || num % 3 == 0) return false;
            for (int i = 5; i * i <= num; i += 6) {
                if (num % i == 0 || num % (i + 2) == 0) return false;
            }
            return true;
        };

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int dx : directions) {
                    for (int dy : directions) {
                        if (dx == 0 && dy == 0) continue; // Skip the no-move scenario
                        int x = i, y = j;
                        long number = 0;
                        while (x >= 0 && x < m && y >= 0 && y < n) {
                            number = number * 10 + mat[x][y];
                            if (number > 10 && isPrime(number)) {
                                primeCounts[number]++;
                            }
                            x += dx;
                            y += dy;
                        }
                    }
                }
            }
        }

        // Determine the most frequent prime that is greater than 10
        int mostFrequent = -1, maxCount = 0;
        for (auto& [num, count] : primeCounts) {
            if (count > maxCount || (count == maxCount && num > mostFrequent)) {
                mostFrequent = num;
                maxCount = count;
            }
        }
        return mostFrequent;
    }
};
