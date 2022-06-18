// @before-stub-for-debug-begin
#include <string>
#include <vector>

#include "commoncppproblem438.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=438 lang=cpp
 *
 * [438] Find All Anagrams in a String
 *
 * https://leetcode.com/problems/find-all-anagrams-in-a-string/description/
 *
 * algorithms
 * Medium (48.46%)
 * Likes:    7668
 * Dislikes: 257
 * Total Accepted:    544.3K
 * Total Submissions: 1.1M
 * Testcase Example:  '"cbaebabacd"\n"abc"'
 *
 * Given two strings s and p, return an array of all the start indices of p's
 * anagrams in s. You may return the answer in any order.
 *
 * An Anagram is a word or phrase formed by rearranging the letters of a
 * different word or phrase, typically using all the original letters exactly
 * once.
 *
 *
 * Example 1:
 *
 *
 * Input: s = "cbaebabacd", p = "abc"
 * Output: [0,6]
 * Explanation:
 * The substring with start index = 0 is "cba", which is an anagram of "abc".
 * The substring with start index = 6 is "bac", which is an anagram of "abc".
 *
 *
 * Example 2:
 *
 *
 * Input: s = "abab", p = "ab"
 * Output: [0,1,2]
 * Explanation:
 * The substring with start index = 0 is "ab", which is an anagram of "ab".
 * The substring with start index = 1 is "ba", which is an anagram of "ab".
 * The substring with start index = 2 is "ab", which is an anagram of "ab".
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length, p.length <= 3 * 10^4
 * s and p consist of lowercase English letters.
 *
 *
 */

// @lc code=start
class Solution {
 public:
  vector<int> findAnagrams(string s, string p) {
    vector<int> res;
    unordered_map<char, int> cnt;
    for (char &c : p) cnt[c]++;
    int satisfy = 0, tot = cnt.size();
    for (int i = 0, j = 0; i < s.size(); i++) {
      if (--cnt[s[i]] == 0) satisfy++;
      if (i - j + 1 > p.size()) {
        if (cnt[s[j]] == 0) satisfy--;
        cnt[s[j++]]++;
      }
      if (satisfy == tot) res.push_back(j);
    }
    return res;
  }
};
// @lc code=end
