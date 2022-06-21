// @before-stub-for-debug-begin
#include <string>
#include <vector>

#include "commoncppproblem1091.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=1091 lang=cpp
 *
 * [1091] Shortest Path in Binary Matrix
 *
 * https://leetcode.com/problems/shortest-path-in-binary-matrix/description/
 *
 * algorithms
 * Medium (44.41%)
 * Likes:    3547
 * Dislikes: 158
 * Total Accepted:    237.7K
 * Total Submissions: 535.2K
 * Testcase Example:  '[[0,1],[1,0]]'
 *
 * Given an n x n binary matrix grid, return the length of the shortest clear
 * path in the matrix. If there is no clear path, return -1.
 *
 * A clear path in a binary matrix is a path from the top-left cell (i.e., (0,
 * 0)) to the bottom-right cell (i.e., (n - 1, n - 1)) such that:
 *
 *
 * All the visited cells of the path are 0.
 * All the adjacent cells of the path are 8-directionally connected (i.e., they
 * are different and they share an edge or a corner).
 *
 *
 * The length of a clear path is the number of visited cells of this path.
 *
 *
 * Example 1:
 *
 *
 * Input: grid = [[0,1],[1,0]]
 * Output: 2
 *
 *
 * Example 2:
 *
 *
 * Input: grid = [[0,0,0],[1,1,0],[1,1,0]]
 * Output: 4
 *
 *
 * Example 3:
 *
 *
 * Input: grid = [[1,0,0],[1,1,0],[1,1,0]]
 * Output: -1
 *
 *
 *
 * Constraints:
 *
 *
 * n == grid.length
 * n == grid[i].length
 * 1 <= n <= 100
 * grid[i][j] is 0 or 1
 *
 *
 */

// @lc code=start
class Solution {
 private:
  int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1}, dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

 public:
  int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    if (grid[0][0] || grid[m - 1][n - 1]) return -1;
    queue<pair<int, int>> q;
    q.push(make_pair(0, 0));
    int res = 0;
    while (!q.empty()) {
      int sz = q.size();
      res++;
      for (int i = 0; i < sz; i++) {
        int x = q.front().first, y = q.front().second;
        q.pop();
        if (x == m - 1 && y == n - 1) return res;
        grid[x][y] = 1;
        for (int i = 0; i < 8; i++) {
          int nx = x + dx[i], ny = y + dy[i];
          if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == 0) {
            q.push(make_pair(nx, ny));
            grid[nx][ny] = 1;
          }
        }
      }
    }
    return -1;
  }
};
// @lc code=end
