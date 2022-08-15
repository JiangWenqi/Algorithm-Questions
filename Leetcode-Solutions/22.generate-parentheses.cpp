// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem22.h"

using namespace std;
// @before-stub-for-debug-end

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
private:
  vector<string> res;
  void dfs(int l, int r, int n, string path) {
    if (l == n && r == n) {
      res.push_back(path);
    } else {
      if (l < n) dfs(l + 1, r, n, path + '(');
      if (r < l) dfs(l, r + 1, n, path + ')');
    }
  }
public:
  vector<string> generateParenthesis(int n) {
    dfs(0, 0, n, "");
    return res;
  }
};

// @lc code=end
