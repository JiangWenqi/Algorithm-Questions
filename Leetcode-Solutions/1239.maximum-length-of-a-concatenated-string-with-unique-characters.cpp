/*
 * @lc app=leetcode id=1239 lang=cpp
 *
 * [1239] Maximum Length of a Concatenated String with Unique Characters
 *
 * https://leetcode.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters/description/
 *
 * algorithms
 * Medium (50.60%)
 * Likes:    2559
 * Dislikes: 187
 * Total Accepted:    134.1K
 * Total Submissions: 260.9K
 * Testcase Example:  '["un","iq","ue"]'
 *
 * You are given an array of strings arr. A string s is formed by the
 * concatenation of a subsequence of arr that has unique characters.
 *
 * Return the maximum possible length of s.
 *
 * A subsequence is an array that can be derived from another array by deleting
 * some or no elements without changing the order of the remaining elements.
 *
 *
 * Example 1:
 *
 *
 * Input: arr = ["un","iq","ue"]
 * Output: 4
 * Explanation: All the valid concatenations are:
 * - ""
 * - "un"
 * - "iq"
 * - "ue"
 * - "uniq" ("un" + "iq")
 * - "ique" ("iq" + "ue")
 * Maximum length is 4.
 *
 *
 * Example 2:
 *
 *
 * Input: arr = ["cha","r","act","ers"]
 * Output: 6
 * Explanation: Possible longest valid concatenations are "chaers" ("cha" +
 * "ers") and "acters" ("act" + "ers").
 *
 *
 * Example 3:
 *
 *
 * Input: arr = ["abcdefghijklmnopqrstuvwxyz"]
 * Output: 26
 * Explanation: The only string in arr has all 26 characters.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= arr.length <= 16
 * 1 <= arr[i].length <= 26
 * arr[i] contains only lowercase English letters.
 *
 *
 */

// @lc code=start
class Solution
{
public:
    int maxLength(vector<string> &arr)
    {
        int n = arr.size();
        vector<int> states;
        for (string &str : arr)
        {
            int state = 0;
            for (char &c : str)
            {
                int num = c - 'a';
                if (state >> num & 1)
                {
                    state = -1;
                    break;
                }
                state |= 1 << num;
            }
            states.push_back(state);
        }
        int res;
        for (int i = 0; i < 1 << n; i++)
        {
            int state = 0, len = 0;
            for (int j = 0; j < n; j++)
            {
                if (i >> j & 1)
                {
                    if (states[j] == -1 || (state & states[j]))
                    {
                        len = -1;
                        break;
                    }
                    state |= states[j];
                    len += arr[j].size();
                }
                res = max(res, len);
            }
        }
        return res;
    }
};
// @lc code=end
