#include <string>
#include <vector>

class Solution {
public:
    string convert(std::string s, int numRows) {
        if (numRows == 1) return s;

        std::vector<std::string> rows(std::min(numRows, int(s.size())));
        int curRow = 0;
        bool goingDown = false;

        for (char c : s) {
            rows[curRow] += c;
            if (curRow == 0 || curRow == numRows - 1) goingDown = !goingDown;
            curRow += goingDown ? 1 : -1;
        }

        std::string result;
        for (std::string row : rows) result += row;
        return result;
    }
};
