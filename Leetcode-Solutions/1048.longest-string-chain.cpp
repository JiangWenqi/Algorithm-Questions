// @before-stub-for-debug-begin
#include "commoncppproblem1048.h"
#include <string>
#include <vector>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=1048 lang=cpp
 *
 * [1048] Longest String Chain
 *
 * https://leetcode.com/problems/longest-string-chain/description/
 *
 * algorithms
 * Medium (57.92%)
 * Likes:    4159
 * Dislikes: 181
 * Total Accepted:    227.9K
 * Total Submissions: 389.2K
 * Testcase Example:  '["a","b","ba","bca","bda","bdca"]'
 *
 * You are given an array of words where each word consists of lowercase
 * English letters.
 *
 * wordA is a predecessor of wordB if and only if we can insert exactly one
 * letter anywhere in wordA without changing the order of the other characters
 * to make it equal to wordB.
 *
 *
 * For example, "abc" is a predecessor of "abac", while "cba" is not a
 * predecessor of "bcad".
 *
 *
 * A word chain is a sequence of words [word1, word2, ..., wordk] with k >= 1,
 * where word1 is a predecessor of word2, word2 is a predecessor of word3, and
 * so on. A single word is trivially a word chain with k == 1.
 *
 * Return the length of the longest possible word chain with words chosen from
 * the given list of words.
 *
 *
 * Example 1:
 *
 *
 * Input: words = ["a","b","ba","bca","bda","bdca"]
 * Output: 4
 * Explanation: One of the longest word chains is ["a","ba","bda","bdca"].
 *
 *
 * Example 2:
 *
 *
 * Input: words = ["xbc","pcxbcf","xb","cxbc","pcxbc"]
 * Output: 5
 * Explanation: All the words can be put in a word chain ["xb", "xbc", "cxbc",
 * "pcxbc", "pcxbcf"].
 *
 *
 * Example 3:
 *
 *
 * Input: words = ["abcd","dbqca"]
 * Output: 1
 * Explanation: The trivial word chain ["abcd"] is one of the longest word
 * chains.
 * ["abcd","dbqca"] is not a valid word chain because the ordering of the
 * letters is changed.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= words.length <= 1000
 * 1 <= words[i].length <= 16
 * words[i] only consists of lowercase English letters.
 *
 *
 */

// @lc code=start
class Solution {
private:
  bool check(string &a, string &b) {
    if (a.size() + 1 != b.size())
      return false;
    int idx = 0;
    for (int i = 0; i < b.size(); i++) {
      if (a[idx] == b[i])
        idx++;
    }
    return idx == a.size();
  }

public:
  int longestStrChain(vector<string> &words) {
    sort(words.begin(), words.end(),
         [&](string &a, string &b) { return a.size() < b.size(); });
    int res = 0, n = words.size();
    vector<int> dp(n, 1);
    for (int i = 0; i < n; i++) {

      for (int j = 0; j < i; j++) {
        if (check(words[j], words[i])) {
          dp[i] = max(dp[i], dp[j] + 1);
        }
      }
      res = max(res, dp[i]);
    }

    return res;
  }
};
// @lc code=end
