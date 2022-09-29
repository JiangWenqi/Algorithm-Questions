/*
 * @lc app=leetcode id=14 lang=cpp
 *
 * [14] Longest Common Prefix
 *
 * https://leetcode.com/problems/longest-common-prefix/description/
 *
 * algorithms
 * Easy (40.58%)
 * Likes:    10475
 * Dislikes: 3401
 * Total Accepted:    1.9M
 * Total Submissions: 4.7M
 * Testcase Example:  '["flower","flow","flight"]'
 *
 * Write a function to find the longest common prefix string amongst an array
 * of strings.
 *
 * If there is no common prefix, return an empty string "".
 *
 *
 * Example 1:
 *
 *
 * Input: strs = ["flower","flow","flight"]
 * Output: "fl"
 *
 *
 * Example 2:
 *
 *
 * Input: strs = ["dog","racecar","car"]
 * Output: ""
 * Explanation: There is no common prefix among the input strings.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= strs.length <= 200
 * 0 <= strs[i].length <= 200
 * strs[i] consists of only lowercase English letters.
 *
 *
 */

 // @lc code=start
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res = "";
        for (int i = 0; i < strs[0].size(); i++) {
            char c = strs[0][i];
            for (string& word : strs) {
                if (i >= word.size() || c != word[i]) return res;
            }
            res += c;
        }
        return res;
    }
};
// @lc code=end

