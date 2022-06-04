// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem557.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=557 lang=cpp
 *
 * [557] Reverse Words in a String III
 *
 * https://leetcode.com/problems/reverse-words-in-a-string-iii/description/
 *
 * algorithms
 * Easy (79.08%)
 * Likes:    2832
 * Dislikes: 171
 * Total Accepted:    458.9K
 * Total Submissions: 580.3K
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
class Solution
{
public:
    string reverseWords(string s)
    {
        for (int i = 0, j = 0; i < s.size(); i++)
        {
            if (s[i] == ' ')
            {
                reverse(s.begin() + j, s.begin() + i);
                j = i + 1;
            }
            else if (i == s.size() - 1)
            {
                reverse(s.begin() + j, s.end());
            }
        }
        return s;
    }
};
// @lc code=end
