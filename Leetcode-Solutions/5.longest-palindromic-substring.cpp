#include <string>

using namespace std;
/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 *
 * https://leetcode.com/problems/longest-palindromic-substring/description/
 *
 * algorithms
 * Medium (32.00%)
 * Likes:    18594
 * Dislikes: 1088
 * Total Accepted:    1.9M
 * Total Submissions: 5.9M
 * Testcase Example:  '"babad"'
 *
 * Given a string s, return the longest palindromic substring in s.
 *
 *
 * Example 1:
 *
 *
 * Input: s = "babad"
 * Output: "bab"
 * Explanation: "aba" is also a valid answer.
 *
 *
 * Example 2:
 *
 *
 * Input: s = "cbbd"
 * Output: "bb"
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 1000
 * s consist of only digits and English letters.
 *
 *
 */

 // @lc code=start
class Solution {
public:
  string longestPalindrome(string s) {
    string res;
    int  n = s.size(), l, r;
    for (int i = 0; i < n; i++) {
      l = i - 1, r = i + 1;
      while (l >= 0 && r < n && s[l] == s[r]) l--, r++;
      if (res.size() < r - l - 1) res = s.substr(l + 1, r - l - 1);
      l = i, r = i + 1;
      while (l >= 0 && r < n && s[l] == s[r]) l--, r++;
      if (res.size() < r - l - 1) res = s.substr(l + 1, r - l - 1);
    }
    return res;
  }
};
// @lc code=end
