#include <vector>
#include <string>

class Solution {
public:
    bool exist(std::vector<std::vector<char>>& board, std::string word) {
        int m = board.size(), n = board[0].size();
        std::vector<std::vector<bool>> visited(m, std::vector<bool>(n, false));

        std::function<bool(int, int, int)> dfs = [&](int x, int y, int index) -> bool {
            if (index == word.size())
                return true;
            if (x < 0 || x >= m || y < 0 || y >= n || visited[x][y] || board[x][y] != word[index])
                return false;
            visited[x][y] = true;
            bool found = dfs(x + 1, y, index + 1) ||
                         dfs(x - 1, y, index + 1) ||
                         dfs(x, y + 1, index + 1) ||
                         dfs(x, y - 1, index + 1);
            visited[x][y] = false;
            return found;
        };

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dfs(i, j, 0))
                    return true;
            }
        }
        return false;
    }
};
