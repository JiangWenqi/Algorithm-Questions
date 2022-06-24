/*
 * @lc app=leetcode id=22 lang=cpp
 *
 * [22] Generate Parentheses
 *
 * https://leetcode.com/problems/generate-parentheses/description/
 *
 * algorithms
 * Medium (70.62%)
 * Likes:    13500
 * Dislikes: 514
 * Total Accepted:    1.1M
 * Total Submissions: 1.6M
 * Testcase Example:  '3'
 *
 * Given n pairs of parentheses, write a function to generate all combinations
 * of well-formed parentheses.
 *
 *
 * Example 1:
 * Input: n = 3
 * Output: ["((()))","(()())","(())()","()(())","()()()"]
 * Example 2:
 * Input: n = 1
 * Output: ["()"]
 *
 *
 * Constraints:
 *
 *
 * 1 <= n <= 8
 *
 *
 */

// @lc code=start
class Solution {
 public:
  vector<string> ans;

  vector<string> generateParenthesis(int n) {
    dfs(n, 0, 0, "");
    return ans;
  }

  void dfs(int n, int lc, int rc, string seq) {
    if (lc == n && rc == n)
      ans.push_back(seq);
    else {
      if (lc < n) dfs(n, lc + 1, rc, seq + '(');
      if (rc < n && lc > rc) dfs(n, lc, rc + 1, seq + ')');
    }
  }
};

// @lc code=end
