/*
 * @lc app=leetcode id=409 lang=cpp
 *
 * [409] Longest Palindrome
 *
 * https://leetcode.com/problems/longest-palindrome/description/
 *
 * algorithms
 * Easy (54.05%)
 * Likes:    3031
 * Dislikes: 172
 * Total Accepted:    307.7K
 * Total Submissions: 569.3K
 * Testcase Example:  '"abccccdd"'
 *
 * Given a string s which consists of lowercase or uppercase letters, return
 * the length of the longest palindrome that can be built with those letters.
 *
 * Letters are case sensitive, for example, "Aa" is not considered a palindrome
 * here.
 *
 *
 * Example 1:
 *
 *
 * Input: s = "abccccdd"
 * Output: 7
 * Explanation: One longest palindrome that can be built is "dccaccd", whose
 * length is 7.
 *
 *
 * Example 2:
 *
 *
 * Input: s = "a"
 * Output: 1
 * Explanation: The longest palindrome that can be built is "a", whose length
 * is 1.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 2000
 * s consists of lowercase and/or uppercase English letters only.
 *
 *
 */

 // @lc code=start
class Solution {
public:
    int longestPalindrome(string s) {
        int cnt[256] = { 0 };
        for (char& c : s) cnt[c]++;
        int two = 0, one = 0;
        for (int& c : cnt) {
            one += c % 2;
            two += c / 2;
        }

        if (one > 0) return two * 2 + 1;
        else return two * 2;
    }
};
// @lc code=end

