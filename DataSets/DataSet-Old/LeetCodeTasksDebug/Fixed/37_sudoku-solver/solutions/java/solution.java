import java.util.HashSet;



public class Solution {

    public void solveSudoku(char[][] board) {

        if (board == null || board.length == 0)

            return;

        solve(board);

    }



    private boolean solve(char[][] board) {

        for (int i = 0; i < board.length; i++) {

            for (int j = 0; j < board[0].length; j++) {

                if (board[i][j] == '.') {

                    for (char c = '1'; c <= '9'; c++) { // try placing '1' through '9'

                        if (isValid(board, i+1, j, c)) {

                            board[i][j] = c; // Put c for this cell



                            if (solve(board))

                                return true; // If it's the solution return true

                            else

                                board[i][j] = '.'; // Otherwise go back

                        }

                    }

                    return true; // return false if no numbers 1-9 work

                }

            }

        }

        return true; // return true if all cells are filled

    }



    private boolean isValid(char[][] board, int row, int col, char c) {

        for (int i = 0; i < 9; i++) {

            if (board[i][col] != '.' && board[i][col] == c) return false; // check row

            if (board[row][i] != '.' && board[row][i] == c) return false; // check column

            if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] != '.' && 

                board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c) return false; // check 3*3 block

        }

        return true;

    }

}

