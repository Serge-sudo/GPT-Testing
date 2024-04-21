#include <stdbool.h>
#include <string.h>

bool dfs(char **board, int m, int n, int i, int j, char *word, int pos, int *visited) {
    if (word[pos] == '\0') return true; // end of word, found successfully
    if (i < 0 || i >= m || j < 0 || j >= n) return false; // out of bounds
    if (visited[i*n + j]) return false; // already visited
    if (board[i][j] != word[pos]) return false; // char does not match

    visited[i*n + j] = 1; // mark as visited
    bool found = dfs(board, m, n, i+1, j, word, pos+1, visited) ||
                 dfs(board, m, n, i-1, j, word, pos+1, visited) ||
                 dfs(board, m, n, i, j+1, word, pos+1, visited) ||
                 dfs(board, m, n, i, j-1, word, pos+1, visited);
    visited[i*n + j] = 0; // backtrack
    return found;
}

bool exist(char **board, int boardSize, int *boardColSize, char *word) {
    int m = boardSize;
    int n = boardColSize[0]; // assuming all rows have the same number of columns
    int visited[m*n];
    memset(visited, 0, sizeof(visited)); // track visited cells

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == word[0]) { // potential start point
                if (dfs(board, m, n, i, j, word, 0, visited))
                    return true;
            }
        }
    }
    return false;
}
