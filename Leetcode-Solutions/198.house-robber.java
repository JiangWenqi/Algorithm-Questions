/*
 * @lc app=leetcode id=198 lang=java
 *
 * [198] House Robber
 */

// @lc code=start
class Solution {
    public int rob(int[] nums) {
        int n = nums.length;
        if (n == 0)
            return -1;
        else if (n == 1)
            return nums[0];
        else if (n == 2)
            return Math.max(nums[0], nums[1]);

        int a = nums[0];
        int b = Math.max(nums[0], nums[1]);
        for (int i = 2; i < n; i++) {
            int c = Math.max(a + nums[i], b);
            a = b;
            b = c;
        }
        return b;

    }
}
// @lc code=end
