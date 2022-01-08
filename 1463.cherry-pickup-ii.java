/*
 * @lc app=leetcode id=1463 lang=java
 *
 * [1463] Cherry Pickup II
 */

// @lc code=start
class Solution {
    public int cherryPickup(int[][] grid) {
        int Rows = grid.length, Cols = grid[0].length;
        int[][][] dp = new int[2][Cols][Cols]; // we just need previous row memories
        dp[0][0][Cols - 1] = grid[0][0] + grid[0][Cols - 1]; // init
        int[] dirs = new int[] { -1, 0, 1 };
        int res = 0;

        for (int r = 1; r < Rows; r++) {
            int prevR = (r - 1) % 2, curR = r % 2;

            for (int c1 = 0; c1 < Cols && c1 <= r; c1++) { // robot 1 start top-left
                for (int c2 = Cols - 1; c2 > c1 && c2 >= (Cols - 1 - r); c2--) { // robot 2 start top-right
                    // So all can be reached
                    // We just need to be careful to not double dip
                    int cherries = grid[r][c1] + grid[r][c2];
                    int prevCherries = 0;

                    // Go direction
                    for (int d1 : dirs) {
                        for (int d2 : dirs) {
                            int prevC1 = c1 + d1, prevC2 = c2 + d2;
                            if (0 <= prevC1 && prevC1 < Cols && 0 <= prevC2 && prevC2 < Cols && prevC1 != prevC2) {
                                prevCherries = Math.max(prevCherries, dp[prevR][prevC1][prevC2]);
                            }
                        }
                    }
                    dp[curR][c1][c2] = cherries + prevCherries;
                    res = Math.max(res, dp[curR][c1][c2]);
                }
            }
        }
        return res;
    }
}
// @lc code=end
