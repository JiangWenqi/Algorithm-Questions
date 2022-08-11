// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem17.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=17 lang=cpp
 *
 * [17] Letter Combinations of a Phone Number
 *
 * https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/
 *
 * algorithms
 * Medium (54.58%)
 * Likes:    11096
 * Dislikes: 713
 * Total Accepted:    1.3M
 * Total Submissions: 2.3M
 * Testcase Example:  '"23"'
 *
 * Given a string containing digits from 2-9 inclusive, return all possible
 * letter combinations that the number could represent. Return the answer in
 * any order.
 *
 * A mapping of digits to letters (just like on the telephone buttons) is given
 * below. Note that 1 does not map to any letters.
 *
 *
 * Example 1:
 *
 *
 * Input: digits = "23"
 * Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
 *
 *
 * Example 2:
 *
 *
 * Input: digits = ""
 * Output: []
 *
 *
 * Example 3:
 *
 *
 * Input: digits = "2"
 * Output: ["a","b","c"]
 *
 *
 *
 * Constraints:
 *
 *
 * 0 <= digits.length <= 4
 * digits[i] is a digit in the range ['2', '9'].
 *
 *
 */

 // @lc code=start
class Solution {
private:
  vector<string> ans;
  string strs[10] = {
      "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz",
  };
  void dfs(string& digits, int u, string path) {
    if (u == digits.size())
      ans.push_back(path);
    else {
      for (auto c : strs[digits[u] - '0']) dfs(digits, u + 1, path + c);
    }
  }

public:
  vector<string> letterCombinations(string digits) {
    if (digits.empty()) return ans;
    dfs(digits, 0, "");
    return ans;
  }
};
// @lc code=end
