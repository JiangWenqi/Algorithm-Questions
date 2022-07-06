/*
 * @lc app=leetcode id=205 lang=cpp
 *
 * [205] Isomorphic Strings
 *
 * https://leetcode.com/problems/isomorphic-strings/description/
 *
 * algorithms
 * Easy (42.26%)
 * Likes:    3966
 * Dislikes: 723
 * Total Accepted:    538.1K
 * Total Submissions: 1.3M
 * Testcase Example:  '"egg"\n"add"'
 *
 * Given two strings s and t, determine if they are isomorphic.
 *
 * Two strings s and t are isomorphic if the characters in s can be replaced to
 * get t.
 *
 * All occurrences of a character must be replaced with another character while
 * preserving the order of characters. No two characters may map to the same
 * character, but a character may map to itself.
 *
 *
 * Example 1:
 * Input: s = "egg", t = "add"
 * Output: true
 * Example 2:
 * Input: s = "foo", t = "bar"
 * Output: false
 * Example 3:
 * Input: s = "paper", t = "title"
 * Output: true
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 5 * 10^4
 * t.length == s.length
 * s and t consist of any valid ascii character.
 *
 *
 */

 // @lc code=start
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> st, ts;
        for (int i = 0; i < s.size(); i++) {
            if (!st.count(s[i]) && !ts.count(t[i])) {
                st[s[i]] = t[i];
                ts[t[i]] = s[i];
            } else if (st.count(s[i]) && ts.count(t[i]) && st[s[i]] == t[i] && ts[t[i]] == s[i]) {
                continue;
            } else {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

