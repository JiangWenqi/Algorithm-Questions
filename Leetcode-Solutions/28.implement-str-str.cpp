// @before-stub-for-debug-begin
#include <string>
#include <vector>

#include "commoncppproblem28.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=28 lang=cpp
 *
 * [28] Implement strStr()
 *
 * https://leetcode.com/problems/implement-strstr/description/
 *
 * algorithms
 * Easy (36.34%)
 * Likes:    4295
 * Dislikes: 3733
 * Total Accepted:    1.3M
 * Total Submissions: 3.6M
 * Testcase Example:  '"hello"\n"ll"'
 *
 * Implement strStr().
 *
 * Given two strings needle and haystack, return the index of the first
 * occurrence of needle in haystack, or -1 if needle is not part of haystack.
 *
 * Clarification:
 *
 * What should we return when needle is an empty string? This is a great
 * question to ask during an interview.
 *
 * For the purpose of this problem, we will return 0 when needle is an empty
 * string. This is consistent to C's strstr() and Java's indexOf().
 *
 *
 * Example 1:
 *
 *
 * Input: haystack = "hello", needle = "ll"
 * Output: 2
 *
 *
 * Example 2:
 *
 *
 * Input: haystack = "aaaaa", needle = "bba"
 * Output: -1
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= haystack.length, needle.length <= 10^4
 * haystack and needle consist of only lowercase English characters.
 *
 *
 */

// @lc code=start
class Solution {
 public:
  int strStr(string text, string pattern) {
    int m = text.size(), n = pattern.size();
    text = ' ' + text, pattern = ' ' + pattern;
    vector<int> next(n + 1);
    for (int i = 2, j = 0; i <= n; i++) {
      while (j && pattern[j + 1] != pattern[i]) j = next[j];
      if (pattern[i] == pattern[j + 1]) j++;
      next[i] = j;
    }
    for (int i = 1, j = 0; i <= m; i++) {
      while (j && text[i] != pattern[j + 1]) j = next[j];
      if (text[i] == pattern[j + 1]) j++;
      if (j == n) return i - n;
    }
    return -1;
  }
};
// @lc code=end
