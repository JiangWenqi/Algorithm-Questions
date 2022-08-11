/*
 * @lc app=leetcode id=304 lang=java
 *
 * [304] Range Sum Query 2D - Immutable
 */

// @lc code=start
class NumMatrix {

    private int[][] dp;

    public NumMatrix(int[][] matrix) {
        int rows = matrix.length, cols = matrix[0].length;
        dp = new int[rows + 1][cols + 1];

        for (int row = 1; row <= rows; row++) {
            for (int col = 1; col <= cols; col++) {
                dp[row][col] = dp[row - 1][col] + dp[row][col - 1] - dp[row - 1][col - 1] + matrix[row - 1][col - 1];
            }
        }

    }

    // [2,1,4,3] -> 8 x 3
    public int sumRegion(int row1, int col1, int row2, int col2) {
        return dp[row2 + 1][col2 + 1] - dp[row2 + 1][col1] - dp[row1][col2 + 1] + dp[row1][col1];
    }
}

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * int param_1 = obj.sumRegion(row1,col1,row2,col2);
 */
// @lc code=end
