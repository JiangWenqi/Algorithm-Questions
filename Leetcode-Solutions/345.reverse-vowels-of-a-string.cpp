/*
 * @lc app=leetcode id=345 lang=cpp
 *
 * [345] Reverse Vowels of a String
 *
 * https://leetcode.com/problems/reverse-vowels-of-a-string/description/
 *
 * algorithms
 * Easy (47.72%)
 * Likes:    2496
 * Dislikes: 2160
 * Total Accepted:    421.9K
 * Total Submissions: 865.7K
 * Testcase Example:  '"hello"'
 *
 * Given a string s, reverse only all the vowels in the string and return it.
 *
 * The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in both
 * lower and upper cases, more than once.
 *
 *
 * Example 1:
 * Input: s = "hello"
 * Output: "holle"
 * Example 2:
 * Input: s = "leetcode"
 * Output: "leotcede"
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 3 * 10^5
 * s consist of printable ASCII characters.
 *
 *
 */

// @lc code=start
class Solution
{
public:
    string reverseVowels(string s)
    {
        unordered_set<char> vowels;
        vowels.insert('a');
        vowels.insert('e');
        vowels.insert('i');
        vowels.insert('o');
        vowels.insert('u');
        vowels.insert('A');
        vowels.insert('E');
        vowels.insert('I');
        vowels.insert('O');
        vowels.insert('U');

        int l = 0, r = s.size() - 1;
        while (l < r)
        {
            while (l < r && !vowels.count(s[l]))
                l++;
            while (l < r && !vowels.count(s[r]))
                r--;
            swap(s[l], s[r]);
            l++, r--;
        }
        return s;
    }
};
// @lc code=end
