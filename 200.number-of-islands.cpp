// @before-stub-for-debug-begin
#include <string>
#include <vector>

#include "commoncppproblem200.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=200 lang=cpp
 *
 * [200] Number of Islands
 *
 * https://leetcode.com/problems/number-of-islands/description/
 *
 * algorithms
 * Medium (54.22%)
 * Likes:    13921
 * Dislikes: 332
 * Total Accepted:    1.6M
 * Total Submissions: 2.9M
 * Testcase Example:
 * '[["1","1","1","1","0"],["1","1","0","1","0"],["1","1","0","0","0"],["0","0","0","0","0"]]'
 *
 * Given an m x n 2D binary grid grid which represents a map of '1's (land) and
 * '0's (water), return the number of islands.
 *
 * An island is surrounded by water and is formed by connecting adjacent lands
 * horizontally or vertically. You may assume all four edges of the grid are
 * all surrounded by water.
 *
 *
 * Example 1:
 *
 *
 * Input: grid = [
 * ⁠ ["1","1","1","1","0"],
 * ⁠ ["1","1","0","1","0"],
 * ⁠ ["1","1","0","0","0"],
 * ⁠ ["0","0","0","0","0"]
 * ]
 * Output: 1
 *
 *
 * Example 2:
 *
 *
 * Input: grid = [
 * ⁠ ["1","1","0","0","0"],
 * ⁠ ["1","1","0","0","0"],
 * ⁠ ["0","0","1","0","0"],
 * ⁠ ["0","0","0","1","1"]
 * ]
 * Output: 3
 *
 *
 *
 * Constraints:
 *
 *
 * m == grid.length
 * n == grid[i].length
 * 1 <= m, n <= 300
 * grid[i][j] is '0' or '1'.
 *
 *
 */

 // @lc code=start
class Solution {
private:
  int dirs[5] = { 0, 1, 0, -1, 0 };
  int res, m, n;

  void dfs(int x, int y, vector<vector<char>>& grid) {
    grid[x][y] = '0';
    for (int i = 0; i < 4; i++) {
      int nx = x + dirs[i], ny = y + dirs[i + 1];
      if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == '1')
        dfs(nx, ny, grid);
    }
  }

public:
  int numIslands(vector<vector<char>>& grid) {
    res = 0, m = grid.size(), n = grid[0].size();

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (grid[i][j] == '1') {
          res++;
          dfs(i, j, grid);
        }
      }
    }
    return res;
  }
};
// @lc code=end
