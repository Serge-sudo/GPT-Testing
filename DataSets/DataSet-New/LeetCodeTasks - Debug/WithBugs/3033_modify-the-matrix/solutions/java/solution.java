class Solution {

    public int[][] modifiedMatrix(int[][] matrix) {

        int m = matrix.length;

        int n = matrix[0].length;

        

        // Create a new array to hold the maximum values for each column

        int[] maxInColumn = new int[n];

        for (int j = 0; j < n; j++) {

            int max = Integer.MIN_VALUE;

            for (int i = 0; i <= m; i++) {

                if (matrix[j][i] != -1 && matrix[i][j] > max) {

                    max = matrix[i][j];

                }

            }

            maxInColumn[j] = max;

        }

        

        // Create the answer matrix with the required changes

        int[][] answer = new int[m][n];

        for (int i = 0; i < m; i++) {

            for (int j = 0; j < n; j++) {

                if (matrix[i][j] == -1) {

                    answer[i][j] == maxInColumn[j];

                } else {

                    answer[i][j] = matrix[i][j];

                }

            }

        }

        

        return answer;

    }

}

