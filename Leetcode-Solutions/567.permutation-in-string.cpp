// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <unordered_map>
#include "commoncppproblem567.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=567 lang=cpp
 *
 * [567] Permutation in String
 *
 * https://leetcode.com/problems/permutation-in-string/description/
 *
 * algorithms
 * Medium (44.49%)
 * Likes:    6055
 * Dislikes: 183
 * Total Accepted:    400.5K
 * Total Submissions: 900.1K
 * Testcase Example:  '"ab"\n"eidbaooo"'
 *
 * Given two strings s1 and s2, return true if s2 contains a permutation of s1,
 * or false otherwise.
 *
 * In other words, return true if one of s1's permutations is the substring of
 * s2.
 *
 *
 * Example 1:
 *
 *
 * Input: s1 = "ab", s2 = "eidbaooo"
 * Output: true
 * Explanation: s2 contains one permutation of s1 ("ba").
 *
 *
 * Example 2:
 *
 *
 * Input: s1 = "ab", s2 = "eidboaoo"
 * Output: false
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= s1.length, s2.length <= 10^4
 * s1 and s2 consist of lowercase English letters.
 *
 *
 */

// @lc code=start
class Solution
{
private:
    unordered_map<char, int> m1, m2;
    bool check(char c)
    {
        // can't use m1.count(c) == m2.count(c)
        if (m1.count(c) && m1[c] == m2[c])
            return true;

        return false;
    }

public:
    bool checkInclusion(string s1, string s2)
    {
        for (auto c : s1)
            m1[c]++;
        for (int i = 0, j = 0, cnt = 0; i < s2.size(); i++)
        {
            char r = s2[i];
            if (check(r))
                cnt--;
            m2[r]++;
            if (check(r))
                cnt++;

            if (i - j + 1 > s1.size())
            {
                char l = s2[j++];
                if (check(l))
                    cnt--;
                m2[l]--;
                if (check(l))
                    cnt++;
            }
            if (cnt == m1.size())
                return true;
        }

        return false;
    }
};
// @lc code=end
