class Solution {
    public boolean exist(char[][] board, String word) {
        if (board == null || board.length == 0) {
            return false;
        }

        for (int i = 0; i < board.length; i++) {
            for (int j = 0; j < board[i].length; j++) {
                if (backtrack(board, word, i, j, 0)) {
                    return true;
                }
            }
        }
        
        return false;
    }

    private boolean backtrack(char[][] board, String word, int i, int j, int index) {
        if (index == word.length()) {
            return true;
        }
        
        if (i < 0 || i >= board.length || j < 0 || j >= board[i].length || board[i][j] != word.charAt(index)) {
            return false;
        }

        board[i][j] = '#'; // Temporarily mark the cell as visited
        
        boolean result = (backtrack(board, word, i + 1, j, index + 1) ||
                          backtrack(board, word, i - 1, j, index + 1) ||
                          backtrack(board, word, i, j + 1, index + 1) ||
                          backtrack(board, word, i, j - 1, index + 1));
        
        board[i][j] = word.charAt(index); // Unmark the cell
        
        return result;
    }
}
