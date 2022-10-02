/*
 * @lc app=leetcode id=1155 lang=cpp
 *
 * [1155] Number of Dice Rolls With Target Sum
 *
 * https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/description/
 *
 * algorithms
 * Medium (48.12%)
 * Likes:    2792
 * Dislikes: 97
 * Total Accepted:    132.9K
 * Total Submissions: 264.7K
 * Testcase Example:  '1\n6\n3'
 *
 * You have n dice and each die has k faces numbered from 1 to k.
 *
 * Given three integers n, k, and target, return the number of possible ways
 * (out of the k^n total ways) to roll the dice so the sum of the face-up
 * numbers equals target. Since the answer may be too large, return it modulo
 * 10^9 + 7.
 *
 *
 * Example 1:
 *
 *
 * Input: n = 1, k = 6, target = 3
 * Output: 1
 * Explanation: You throw one die with 6 faces.
 * There is only one way to get a sum of 3.
 *
 *
 * Example 2:
 *
 *
 * Input: n = 2, k = 6, target = 7
 * Output: 6
 * Explanation: You throw two dice, each with 6 faces.
 * There are 6 ways to get a sum of 7: 1+6, 2+5, 3+4, 4+3, 5+2, 6+1.
 *
 *
 * Example 3:
 *
 *
 * Input: n = 30, k = 30, target = 500
 * Output: 222616187
 * Explanation: The answer must be returned modulo 10^9 + 7.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= n, k <= 30
 * 1 <= target <= 1000
 *
 *
 */

 // @lc code=start
class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        const int MOD = 1e9 + 7;
        vector<int> f(target + 1, 0);
        f[0] = 1;
        for (int i = 1; i <= n; i++) {// 枚举所有物品
            for (int j = target; j >= 0; j--) { // 枚举体积, 从大到小 
                f[j] = 0;
                for (int u = 1; u <= k & u <= j; u++) {
                    f[j] = (f[j] + f[j - u]) % MOD;
                }
            }
        }
        return f[target];
    }
};
// @lc code=end

