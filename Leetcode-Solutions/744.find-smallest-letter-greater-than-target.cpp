/*
 * @lc app=leetcode id=744 lang=cpp
 *
 * [744] Find Smallest Letter Greater Than Target
 *
 * https://leetcode.com/problems/find-smallest-letter-greater-than-target/description/
 *
 * algorithms
 * Easy (44.65%)
 * Likes:    2307
 * Dislikes: 1908
 * Total Accepted:    251.1K
 * Total Submissions: 562.4K
 * Testcase Example:  '["c","f","j"]\n"a"'
 *
 * You are given an array of characters letters that is sorted in
 * non-decreasing order, and a character target. There are at least two
 * different characters in letters.
 *
 * Return the smallest character in letters that is lexicographically greater
 * than target. If such a character does not exist, return the first character
 * in letters.
 *
 *
 * Example 1:
 *
 *
 * Input: letters = ["c","f","j"], target = "a"
 * Output: "c"
 * Explanation: The smallest character that is lexicographically greater than
 * 'a' in letters is 'c'.
 *
 *
 * Example 2:
 *
 *
 * Input: letters = ["c","f","j"], target = "c"
 * Output: "f"
 * Explanation: The smallest character that is lexicographically greater than
 * 'c' in letters is 'f'.
 *
 *
 * Example 3:
 *
 *
 * Input: letters = ["x","x","y","y"], target = "z"
 * Output: "x"
 * Explanation: There are no characters in letters that is lexicographically
 * greater than 'z' so we return letters[0].
 *
 *
 *
 * Constraints:
 *
 *
 * 2 <= letters.length <= 10^4
 * letters[i] is a lowercase English letter.
 * letters is sorted in non-decreasing order.
 * letters contains at least two different characters.
 * target is a lowercase English letter.
 *
 *
 */

// @lc code=start
class Solution
{
public:
    char nextGreatestLetter(vector<char> &letters, char target)
    {
        int l = 0, r = letters.size() - 1;
        while (l < r)
        {
            int mid = l + r >> 1;
            if (letters[mid] > target)
                r = mid;
            else
                l = mid + 1;
        }
        return letters[l] <= target ? letters[0] : letters[l];
    }
};
// @lc code=end
