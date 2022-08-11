// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem576.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=576 lang=cpp
 *
 * [576] Out of Boundary Paths
 *
 * https://leetcode.com/problems/out-of-boundary-paths/description/
 *
 * algorithms
 * Medium (40.31%)
 * Likes:    2108
 * Dislikes: 204
 * Total Accepted:    81.9K
 * Total Submissions: 194.5K
 * Testcase Example:  '2\n2\n2\n0\n0'
 *
 * There is an m x n grid with a ball. The ball is initially at the position
 * [startRow, startColumn]. You are allowed to move the ball to one of the four
 * adjacent cells in the grid (possibly out of the grid crossing the grid
 * boundary). You can apply at most maxMove moves to the ball.
 *
 * Given the five integers m, n, maxMove, startRow, startColumn, return the
 * number of paths to move the ball out of the grid boundary. Since the answer
 * can be very large, return it modulo 10^9 + 7.
 *
 *
 * Example 1:
 *
 *
 * Input: m = 2, n = 2, maxMove = 2, startRow = 0, startColumn = 0
 * Output: 6
 *
 *
 * Example 2:
 *
 *
 * Input: m = 1, n = 3, maxMove = 3, startRow = 0, startColumn = 1
 * Output: 12
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= m, n <= 50
 * 0 <= maxMove <= 50
 * 0 <= startRow < m
 * 0 <= startColumn < n
 *
 *
 */

 // @lc code=start
class Solution {
private:
    int MOD = 1e9 + 7;
    int dirs[5] = { 0, 1, 0, -1, 0 };

public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        int res = 0;
        if (!maxMove) return res;
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(maxMove + 1, 0)));

        // init the first and the last row
        for (int i = 0; i < n; i++) {
            dp[0][i][1] ++;
            dp[m - 1][i][1] ++;
        }
        // init the first and the last column
        // Note: the 4 conners will be 2, and rest of them will be 1
        for (int i = 0; i < m; i++) {
            dp[i][0][1] ++;
            dp[i][n - 1][1] ++;
        }

        for (int k = 1; k <= maxMove;k++) {
            for (int i = 0; i < m;i++) {
                for (int j = 0; j < n; j++) {
                    for (int d = 0; d < 4; d++) {
                        int nx = i + dirs[d], ny = j + dirs[d + 1];
                        if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
                            dp[nx][ny][k] += dp[i][j][k - 1];
                            dp[nx][ny][k] %= MOD;
                        }
                    }
                }
            }
        }

        for (int i = 1; i <= maxMove; i++) {
            res += dp[startRow][startColumn][i];
            res %= MOD;
        }

        return res;
    }
};
// @lc code=end

