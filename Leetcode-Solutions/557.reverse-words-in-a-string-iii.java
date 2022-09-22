/*
 * @lc app=leetcode id=557 lang=java
 *
 * [557] Reverse Words in a String III
 *
 * https://leetcode.com/problems/reverse-words-in-a-string-iii/description/
 *
 * algorithms
 * Easy (80.88%)
 * Likes:    3787
 * Dislikes: 201
 * Total Accepted:    559.5K
 * Total Submissions: 691.8K
 * Testcase Example:  `"Let's take LeetCode contest"`
 *
 * Given a string s, reverse the order of characters in each word within a
 * sentence while still preserving whitespace and initial word order.
 * 
 * 
 * Example 1:
 * Input: s = "Let's take LeetCode contest"
 * Output: "s'teL ekat edoCteeL tsetnoc"
 * Example 2:
 * Input: s = "God Ding"
 * Output: "doG gniD"
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length <= 5 * 10^4
 * s contains printable ASCII characters.
 * s does not contain any leading or trailing spaces.
 * There is at least one word in s.
 * All the words in s are separated by a single space.
 * 
 * 
 */

// @lc code=start
class Solution {

    private void reverseWord(int start, int end, char[] cs) {
        while (start < end) {
            char t = cs[start];
            cs[start] = cs[end];
            cs[end] = t;
            start++;
            end--;
        }
    }

    public String reverseWords(String s) {
        int len = s.length();
        char[] cs = s.toCharArray();
        for (int i = 0, j = 0; i <= len; i++) {
            if (i == len || cs[i] == ' ') {
                reverseWord(j, i - 1, cs);
                j = i + 1;
            }
        }
        return new String(cs);
    }

}
// @lc code=end
