/*
 * @lc app=leetcode id=198 lang=java
 *
 * [198] House Robber
 */

// @lc code=start
class Solution {
    public int rob(int[] nums) {

        if (nums.length <= 1) {
            return nums[0];
        } 

        int[] dp = new int[nums.length];

        dp[0] = nums[0];

        dp[1] = Math.max(dp[0], nums[1]);


        for (int i = 2; i < dp.length; i++) {
            dp[i] = Math.max(nums[i] + dp[i - 2], dp[i - 1]);

        }

        return dp[nums.length - 1];

    }
}
// @lc code=end
