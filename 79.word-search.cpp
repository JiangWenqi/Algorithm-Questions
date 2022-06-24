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
class Solution {
 public:
  bool exist(vector<vector<char>>& board, string word) {
    for (int i = 0; i < board.size(); i++) {
      for (int j = 0; j < board[i].size(); j++) {
        if (dfs(board, word, 0, i, j)) return true;
      }
    }
    return false;
  }

  int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

  bool dfs(vector<vector<char>>& board, string& word, int u, int x, int y) {
    if (board[x][y] != word[u]) return false;
    if (u == word.size() - 1) return true;

    char t = board[x][y];
    board[x][y] = '.';
    for (int i = 0; i < 4; i++) {
      int a = x + dx[i], b = y + dy[i];
      if (a < 0 || a >= board.size() || b < 0 || b >= board[0].size() ||
          board[a][b] == '.')
        continue;
      if (dfs(board, word, u + 1, a, b)) return true;
    }
    board[x][y] = t;
    return false;
  }
};

// @lc code=end
