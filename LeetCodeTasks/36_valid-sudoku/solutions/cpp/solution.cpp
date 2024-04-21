#include <vector>
#include <unordered_set>

class Solution {
public:
    bool isValidSudoku(std::vector<std::vector<char>>& board) {
        std::unordered_set<std::string> seen;

        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                char number = board[i][j];
                if (number != '.') {
                    std::string rowKey = std::to_string(number) + " in row " + std::to_string(i);
                    std::string colKey = std::to_string(number) + " in col " + std::to_string(j);
                    std::string boxKey = std::to_string(number) + " in box " + std::to_string(i / 3) + "-" + std::to_string(j / 3);

                    if (seen.count(rowKey) || seen.count(colKey) || seen.count(boxKey)) {
                        return false;
                    }

                    seen.insert(rowKey);
                    seen.insert(colKey);
                    seen.insert(boxKey);
                }
            }
        }

        return true;
    }
};
