/*
 * @lc app=leetcode id=201 lang=cpp
 *
 * [201] Bitwise AND of Numbers Range
 *
 * https://leetcode.com/problems/bitwise-and-of-numbers-range/description/
 *
 * algorithms
 * Medium (41.96%)
 * Likes:    2342
 * Dislikes: 182
 * Total Accepted:    219.3K
 * Total Submissions: 522.6K
 * Testcase Example:  '5\n7'
 *
 * Given two integers left and right that represent the range [left, right],
 * return the bitwise AND of all numbers in this range, inclusive.
 *
 *
 * Example 1:
 *
 *
 * Input: left = 5, right = 7
 * Output: 4
 *
 *
 * Example 2:
 *
 *
 * Input: left = 0, right = 0
 * Output: 0
 *
 *
 * Example 3:
 *
 *
 * Input: left = 1, right = 2147483647
 * Output: 0
 *
 *
 *
 * Constraints:
 *
 *
 * 0 <= left <= right <= 2^31 - 1
 *
 *
 */

 // @lc code=start
class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int res = 0;
        for (int i = 30;i >= 0;i--) {
            if ((left >> i & 1) != (right >> i & 1)) break;
            if ((left >> i & 1) == 1) res += 1 << i;
        }
        return res;
    }
};
// @lc code=end

