/*
 * @lc app=leetcode id=1328 lang=cpp
 *
 * [1328] Break a Palindrome
 *
 * https://leetcode.com/problems/break-a-palindrome/description/
 *
 * algorithms
 * Medium (52.94%)
 * Likes:    1394
 * Dislikes: 585
 * Total Accepted:    103.2K
 * Total Submissions: 195.1K
 * Testcase Example:  '"abccba"'
 *
 * Given a palindromic string of lowercase English letters palindrome, replace
 * exactly one character with any lowercase English letter so that the
 * resulting string is not a palindrome and that it is the lexicographically
 * smallest one possible.
 *
 * Return the resulting string. If there is no way to replace a character to
 * make it not a palindrome, return an empty string.
 *
 * A string a is lexicographically smaller than a string b (of the same length)
 * if in the first position where a and b differ, a has a character strictly
 * smaller than the corresponding character in b. For example, "abcc" is
 * lexicographically smaller than "abcd" because the first position they differ
 * is at the fourth character, and 'c' is smaller than 'd'.
 *
 *
 * Example 1:
 *
 *
 * Input: palindrome = "abccba"
 * Output: "aaccba"
 * Explanation: There are many ways to make "abccba" not a palindrome, such as
 * "zbccba", "aaccba", and "abacba".
 * Of all the ways, "aaccba" is the lexicographically smallest.
 *
 *
 * Example 2:
 *
 *
 * Input: palindrome = "a"
 * Output: ""
 * Explanation: There is no way to replace a single character to make "a" not a
 * palindrome, so return an empty string.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= palindrome.length <= 1000
 * palindrome consists of only lowercase English letters.
 *
 *
 */

 // @lc code=start
class Solution {
public:
    string breakPalindrome(string palindrome) {
        int n = palindrome.size();
        if (n == 1) return "";
        int len = n & 1 ? n / 2 - 1 : n / 2;
        for (int i = 0; i <= len; i++) {
            if (palindrome[i] != 'a') {
                palindrome[i] = 'a';
                return palindrome;
            }
        }

        palindrome.back() = 'b';
        return palindrome;
    }
};
// @lc code=end

