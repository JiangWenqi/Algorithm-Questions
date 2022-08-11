// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem629.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=629 lang=cpp
 *
 * [629] K Inverse Pairs Array
 *
 * https://leetcode.com/problems/k-inverse-pairs-array/description/
 *
 * algorithms
 * Hard (37.28%)
 * Likes:    1335
 * Dislikes: 153
 * Total Accepted:    37.4K
 * Total Submissions: 92.4K
 * Testcase Example:  '3\n0'
 *
 * For an integer array nums, an inverse pair is a pair of integers [i, j]
 * where 0 <= i < j < nums.length and nums[i] > nums[j].
 *
 * Given two integers n and k, return the number of different arrays consist of
 * numbers from 1 to n such that there are exactly k inverse pairs. Since the
 * answer can be huge, return it modulo 10^9 + 7.
 *
 *
 * Example 1:
 *
 *
 * Input: n = 3, k = 0
 * Output: 1
 * Explanation: Only the array [1,2,3] which consists of numbers from 1 to 3
 * has exactly 0 inverse pairs.
 *
 *
 * Example 2:
 *
 *
 * Input: n = 3, k = 1
 * Output: 2
 * Explanation: The array [1,3,2] and [2,1,3] have exactly 1 inverse pair.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= n <= 1000
 * 0 <= k <= 1000
 *
 *
 */

 // @lc code=start
class Solution {
public:
    int kInversePairs(int n, int k) {
        int mod = 1e9 + 7;
        vector<vector<int>> dp(n + 1, vector<int>(k + 1));
        dp[1][0] = 1;
        for (int i = 2; i <= n; i++) {
            long long s = 0;
            for (int j = 0; j <= k; j++) {
                s += dp[i - 1][j];
                if (j - i >= 0) s -= dp[i - 1][j - i];
                dp[i][j] = s % mod;
            }
        }
        return dp[n][k];
    }
};
// @lc code=end

