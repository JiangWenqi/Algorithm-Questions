// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem79.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=79 lang=cpp
 *
 * [79] Word Search
 *
 * https://leetcode.com/problems/word-search/description/
 *
 * algorithms
 * Medium (39.84%)
 * Likes:    9690
 * Dislikes: 366
 * Total Accepted:    1M
 * Total Submissions: 2.5M
 * Testcase Example:
 * '[["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]\n"ABCCED"'
 *
 * Given an m x n grid of characters board and a string word, return true if
 * word exists in the grid.
 *
 * The word can be constructed from letters of sequentially adjacent cells,
 * where adjacent cells are horizontally or vertically neighboring. The same
 * letter cell may not be used more than once.
 *
 *
 * Example 1:
 *
 *
 * Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word
 * = "ABCCED"
 * Output: true
 *
 *
 * Example 2:
 *
 *
 * Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word
 * = "SEE"
 * Output: true
 *
 *
 * Example 3:
 *
 *
 * Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word
 * = "ABCB"
 * Output: false
 *
 *
 *
 * Constraints:
 *
 *
 * m == board.length
 * n = board[i].length
 * 1 <= m, n <= 6
 * 1 <= word.length <= 15
 * board and word consists of only lowercase and uppercase English letters.
 *
 *
 *
 * Follow up: Could you use search pruning to make your solution faster with a
 * larger board?
 *
 */

// @lc code=start
class Solution
{
private:
  int dirs[5] = {0, 1, 0, -1, 0};
  bool dfs(vector<vector<char>> &board, string word, int x, int y, int idx)
  {
    if (board[x][y] != word[idx])
      return false;
    if (idx == word.size() - 1)
      return true;
    char ogi = board[x][y];
    board[x][y] = '*';
    for (int i = 0; i < 4; i++)
    {
      int dx = x + dirs[i], dy = y + dirs[i + 1];
      if (dx >= 0 && dx < board.size() && dy >= 0 && dy < board[0].size())
      {
        if (dfs(board, word, dx, dy, idx + 1))
          return true;
      }
    }
    board[x][y] = ogi;
    return false;
  }

public:
  bool exist(vector<vector<char>> &board, string word)
  {
    int m = board.size(), n = board[0].size();
    for (int i = 0; i < m; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (dfs(board, word, i, j, 0))
          return true;
      }
    }
    return false;
  }
};

// @lc code=end
