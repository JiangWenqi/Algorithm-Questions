// @before-stub-for-debug-begin
#include <string>
#include <vector>

#include "commoncppproblem542.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=542 lang=cpp
 *
 * [542] 01 Matrix
 *
 * https://leetcode.com/problems/01-matrix/description/
 *
 * algorithms
 * Medium (43.83%)
 * Likes:    4672
 * Dislikes: 229
 * Total Accepted:    248.5K
 * Total Submissions: 566.9K
 * Testcase Example:  '[[0,0,0],[0,1,0],[0,0,0]]'
 *
 * Given an m x n binary matrix mat, return the distance of the nearest 0 for
 * each cell.
 *
 * The distance between two adjacent cells is 1.
 *
 *
 * Example 1:
 *
 *
 * Input: mat = [[0,0,0],[0,1,0],[0,0,0]]
 * Output: [[0,0,0],[0,1,0],[0,0,0]]
 *
 *
 * Example 2:
 *
 *
 * Input: mat = [[0,0,0],[0,1,0],[1,1,1]]
 * Output: [[0,0,0],[0,1,0],[1,2,1]]
 *
 *
 *
 * Constraints:
 *
 *
 * m == mat.length
 * n == mat[i].length
 * 1 <= m, n <= 10^4
 * 1 <= m * n <= 10^4
 * mat[i][j] is either 0 or 1.
 * There is at least one 0 in mat.
 *
 *
 */

// @lc code=start
class Solution

{
 private:
  int dirs[5] = {1, 0, -1, 0, 1};

 public:
  vector<vector<int>> updateMatrix(vector<vector<int>> &mat) {
    int m = mat.size(), n = mat[0].size();
    vector<vector<int>> res(m, vector<int>(n, -1));
    queue<pair<int, int>> q;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (mat[i][j] == 0) {
          res[i][j] = 0;
          q.push(make_pair(i, j));
        }
      }
    }
    while (!q.empty()) {
      int x = q.front().first, y = q.front().second;
      q.pop();
      for (int i = 0; i < 4; i++) {
        int nx = x + dirs[i], ny = y + dirs[i + 1];
        if (nx >= 0 && nx < m && ny >= 0 && ny < n && res[nx][ny] == -1) {
          res[nx][ny] = res[x][y] + 1;
          q.push(make_pair(nx, ny));
        }
      }
    }

    return res;
  }
};
// @lc code=end
