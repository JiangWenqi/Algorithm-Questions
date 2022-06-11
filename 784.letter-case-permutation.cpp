// @before-stub-for-debug-begin
#include <string>
#include <vector>

#include "commoncppproblem784.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=784 lang=cpp
 *
 * [784] Letter Case Permutation
 *
 * https://leetcode.com/problems/letter-case-permutation/description/
 *
 * algorithms
 * Medium (72.68%)
 * Likes:    3395
 * Dislikes: 145
 * Total Accepted:    220.3K
 * Total Submissions: 303.1K
 * Testcase Example:  '"a1b2"'
 *
 * Given a string s, you can transform every letter individually to be
 * lowercase or uppercase to create another string.
 *
 * Return a list of all possible strings we could create. Return the output in
 * any order.
 *
 *
 * Example 1:
 *
 *
 * Input: s = "a1b2"
 * Output: ["a1b2","a1B2","A1b2","A1B2"]
 *
 *
 * Example 2:
 *
 *
 * Input: s = "3z4"
 * Output: ["3z4","3Z4"]
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 12
 * s consists of lowercase English letters, uppercase English letters, and
 * digits.
 *
 *
 */

// @lc code=start
class Solution {
 private:
  vector<string> res;

  void dfs(int idx, string s) {
    if (idx == s.size()) {
      res.push_back(s);
    } else {
      dfs(idx + 1, s);
      if (s[idx] >= 65) {
        s[idx] ^= 32;
        dfs(idx + 1, s);
        s[idx] ^= 32;
      }
    }
  }

 public:
  vector<string> letterCasePermutation(string s) {
    dfs(0, s);
    return res;
  }
};
// @lc code=end
