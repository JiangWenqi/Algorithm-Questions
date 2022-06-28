#include <string>
#include <vector>

using namespace std;
/*
 * @lc app=leetcode id=1647 lang=cpp
 *
 * [1647] Minimum Deletions to Make Character Frequencies Unique
 *
 * https://leetcode.com/problems/minimum-deletions-to-make-character-frequencies-unique/description/
 *
 * algorithms
 * Medium (56.44%)
 * Likes:    2081
 * Dislikes: 39
 * Total Accepted:    116.4K
 * Total Submissions: 200.1K
 * Testcase Example:  '"aab"'
 *
 * A string s is called good if there are no two different characters in s that
 * have the same frequency.
 *
 * Given a string s, return the minimum number of characters you need to delete
 * to make s good.
 *
 * The frequency of a character in a string is the number of times it appears
 * in the string. For example, in the string "aab", the frequency of 'a' is 2,
 * while the frequency of 'b' is 1.
 *
 *
 * Example 1:
 *
 *
 * Input: s = "aab"
 * Output: 0
 * Explanation: s is already good.
 *
 *
 * Example 2:
 *
 *
 * Input: s = "aaabbbcc"
 * Output: 2
 * Explanation: You can delete two 'b's resulting in the good string "aaabcc".
 * Another way it to delete one 'b' and one 'c' resulting in the good string
 * "aaabbc".
 *
 * Example 3:
 *
 *
 * Input: s = "ceabaacb"
 * Output: 2
 * Explanation: You can delete both 'c's resulting in the good string "eabaab".
 * Note that we only care about characters that are still in the string at the
 * end (i.e. frequency of 0 is ignored).
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 10^5
 * s contains only lowercase English letters.
 *
 *
 */

// @lc code=start
class Solution {
 public:
  int minDeletions(string s) {
    vector<int> cnt(26, 0);
    for (char &c : s) cnt[c - 'a']++;

    sort(cnt.begin(), cnt.end(), greater<int>());
    int res = 0, maxFrq = s.size();

    for (int i = 0; i < 26 && cnt[i] > 0; i++) {
      if (cnt[i] > maxFrq) res += cnt[i] - maxFrq;
      maxFrq = max(0, min(cnt[i], maxFrq) - 1);
    }

    return res;
  }
};
// @lc code=end
