/*
 * @lc app=leetcode id=387 lang=cpp
 *
 * [387] First Unique Character in a String
 *
 * https://leetcode.com/problems/first-unique-character-in-a-string/description/
 *
 * algorithms
 * Easy (57.72%)
 * Likes:    5947
 * Dislikes: 218
 * Total Accepted:    1.2M
 * Total Submissions: 2M
 * Testcase Example:  '"leetcode"'
 *
 * Given a string s, find the first non-repeating character in it and return
 * its index. If it does not exist, return -1.
 *
 *
 * Example 1:
 * Input: s = "leetcode"
 * Output: 0
 * Example 2:
 * Input: s = "loveleetcode"
 * Output: 2
 * Example 3:
 * Input: s = "aabb"
 * Output: -1
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 10^5
 * s consists of only lowercase English letters.
 *
 *
 */

 // @lc code=start
class Solution {
public:
    int firstUniqChar(string s) {
        int cnt[26] = { 0 };
        for (char& c : s) {
            cnt[c - 'a']++;
        }
        for (int i = 0; i < s.size(); i++) {
            if (cnt[s[i] - 'a'] == 1) return i;
        }
        return -1;
    }
};
// @lc code=end

