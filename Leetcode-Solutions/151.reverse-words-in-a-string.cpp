/*
 * @lc app=leetcode id=151 lang=cpp
 *
 * [151] Reverse Words in a String
 *
 * https://leetcode.com/problems/reverse-words-in-a-string/description/
 *
 * algorithms
 * Medium (30.37%)
 * Likes:    4727
 * Dislikes: 4349
 * Total Accepted:    825.2K
 * Total Submissions: 2.7M
 * Testcase Example:  '"the sky is blue"'
 *
 * Given an input string s, reverse the order of the words.
 *
 * A word is defined as a sequence of non-space characters. The words in s will
 * be separated by at least one space.
 *
 * Return a string of the words in reverse order concatenated by a single
 * space.
 *
 * Note that s may contain leading or trailing spaces or multiple spaces
 * between two words. The returned string should only have a single space
 * separating the words. Do not include any extra spaces.
 *
 *
 * Example 1:
 *
 *
 * Input: s = "the sky is blue"
 * Output: "blue is sky the"
 *
 *
 * Example 2:
 *
 *
 * Input: s = "  hello world  "
 * Output: "world hello"
 * Explanation: Your reversed string should not contain leading or trailing
 * spaces.
 *
 *
 * Example 3:
 *
 *
 * Input: s = "a good   example"
 * Output: "example good a"
 * Explanation: You need to reduce multiple spaces between two words to a
 * single space in the reversed string.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 10^4
 * s contains English letters (upper-case and lower-case), digits, and spaces '
 * '.
 * There is at least one word in s.
 *
 *
 *
 * Follow-up: If the string data type is mutable in your language, can you
 * solve it in-place with O(1) extra space?
 *
 */

// @lc code=start
// time:O(n) space:O(1)
class Solution
{
public:
    string reverseWords(string s)
    {
        int idx = 0;
        // __ab_cde___fgh___ => ba_edc_hgf
        for (int i = 0; i < s.size();)
        {
            int j = i;
            while (j < s.size() && s[j] == ' ')
                j++;
            if (j == s.size())
                break;
            i = j;
            while (j < s.size() && s[j] != ' ')
                j++;
            reverse(s.begin() + i, s.begin() + j);

            // Reassign the s string
            if (idx)
                s[idx++] = ' ';
            while (i < j)
                s[idx++] = s[i++];
        }
        s.erase(s.begin() + idx, s.end()); // Get rid of the excess length
        // ba_edc_hgf => fgh_cde_ab
        reverse(s.begin(), s.end());

        return s;
    }
};

// @lc code=end
