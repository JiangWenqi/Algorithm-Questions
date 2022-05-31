/*
 * @lc app=leetcode id=416 lang=cpp
 *
 * [416] Partition Equal Subset Sum
 *
 * https://leetcode.com/problems/partition-equal-subset-sum/description/
 *
 * algorithms
 * Medium (46.48%)
 * Likes:    7535
 * Dislikes: 119
 * Total Accepted:    448.6K
 * Total Submissions: 965.2K
 * Testcase Example:  '[1,5,11,5]'
 *
 * Given a non-empty array nums containing only positive integers, find if the
 * array can be partitioned into two subsets such that the sum of elements in
 * both subsets is equal.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [1,5,11,5]
 * Output: true
 * Explanation: The array can be partitioned as [1, 5, 5] and [11].
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [1,2,3,5]
 * Output: false
 * Explanation: The array cannot be partitioned into equal sum subsets.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 200
 * 1 <= nums[i] <= 100
 *
 *
 */

// @lc code=start
class Solution
{
public:
    bool canPartition(vector<int> &nums)
    {
        int n = nums.size(), sum = 0;
        for (auto &x : nums)
            sum += x;
        if (sum % 2 == 1)
            return false;
        int target = sum / 2;
        vector<int> dp(target + 1, 0);
        dp[0] = 1;
        for (auto &x : nums)
        {
            for (int i = target; i >= x; i--)
                dp[i] |= dp[i - x];
        }
        return dp[target];
    }
};
// @lc code=end
