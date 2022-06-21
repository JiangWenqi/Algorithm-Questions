// @before-stub-for-debug-begin
#include <string>
#include <vector>

#include "commoncppproblem130.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=130 lang=cpp
 *
 * [130] Surrounded Regions
 *
 * https://leetcode.com/problems/surrounded-regions/description/
 *
 * algorithms
 * Medium (34.50%)
 * Likes:    5024
 * Dislikes: 1249
 * Total Accepted:    426.6K
 * Total Submissions: 1.2M
 * Testcase Example:
 * '[["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]'
 *
 * Given an m x n matrix board containing 'X' and 'O', capture all regions that
 * are 4-directionally surrounded by 'X'.
 *
 * A region is captured by flipping all 'O's into 'X's in that surrounded
 * region.
 *
 *
 * Example 1:
 *
 *
 * Input: board =
 * [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]
 * Output:
 * [["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]
 * Explanation: Surrounded regions should not be on the border, which means
 * that any 'O' on the border of the board are not flipped to 'X'. Any 'O' that
 * is not on the border and it is not connected to an 'O' on the border will be
 * flipped to 'X'. Two cells are connected if they are adjacent cells connected
 * horizontally or vertically.
 *
 *
 * Example 2:
 *
 *
 * Input: board = [["X"]]
 * Output: [["X"]]
 *
 *
 *
 * Constraints:
 *
 *
 * m == board.length
 * n == board[i].length
 * 1 <= m, n <= 200
 * board[i][j] is 'X' or 'O'.
 *
 *
 */

// @lc code=start
class Solution {
 private:
  int dirs[5] = {0, 1, 0, -1, 0};
  int m, n;
  vector<vector<bool>> visited;
  void dfs(int x, int y, vector<vector<char>>& board) {
    visited[x][y] = true;
    for (int i = 0; i < 4; i++) {
      int nx = x + dirs[i], ny = y + dirs[i + 1];
      if (nx >= 0 && nx < m && ny >= 0 && ny < n && !visited[nx][ny] && board[nx][ny] == 'O') {
        visited[nx][ny] = true;
        dfs(nx, ny, board);
      }
    }
  }

 public:
  void solve(vector<vector<char>>& board) {
    m = board.size(), n = board[0].size();
    visited = vector<vector<bool>>(m, vector<bool>(n, false));
    // the first row and the last row
    for (int i = 0; i < n; i++) {
      if (board[0][i] == 'O') dfs(0, i, board);
      if (board[m - 1][i] == 'O') dfs(m - 1, i, board);
    }
    // the firs column and the last column
    for (int i = 0; i < m; i++) {
      if (board[i][0] == 'O') dfs(i, 0, board);
      if (board[i][n - 1] == 'O') dfs(i, n - 1, board);
    }
    // the rest of cells are 'x'
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (!visited[i][j]) board[i][j] = 'X';
      }
    }
  }
};
// @lc code=end
