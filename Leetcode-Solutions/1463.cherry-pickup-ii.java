/*
 * @lc app=leetcode id=1463 lang=java
 *
 * [1463] Cherry Pickup II
 */

// @lc code=start
class Solution {
    private static final int[] DIRS = { -1, 0, 1 };

    public int cherryPickup(int[][] grid) {
        int rows = grid.length, cols = grid[0].length;
        int[][][] dp = new int[rows][cols][cols];
        dp[0][0][cols - 1] = grid[0][0] + grid[0][cols - 1];
        int res = 0;

        // from row 1 to bottom
        for (int row = 1; row < rows; row++) {

            // robot#1 from left top \
            for (int col1 = 0; col1 < cols && col1 <= row; col1++) {
                // robot#2 form right top /
                for (int col2 = cols - 1; col2 > col1 && col2 >= (cols - 1 - row); col2--) {

                    int prevCherries = 0;
                    for (int dir1 : DIRS) {
                        for (int dir2 : DIRS) {
                            int prevRow = row - 1, prevCol1 = col1 + dir1, prevCol2 = col2 + dir2;
                            if (prevCol1 >= 0 && prevCol1 < cols && prevCol2 >= 0 && prevCol2 < cols
                                    && prevCol1 != prevCol2) {
                                prevCherries = Math.max(prevCherries, dp[prevRow][prevCol1][prevCol2]);
                            }

                        }
                    }
                    int cherries = grid[row][col1] + grid[row][col2];
                    dp[row][col1][col2] = cherries + prevCherries;
                    res = Math.max(res, dp[row][col1][col2]);
                }

            }

        }
        return res;
    }
}
// @lc code=end
