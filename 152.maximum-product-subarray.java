/*
 * @lc app=leetcode id=152 lang=java
 *
 * [152] Maximum Product Subarray
 */

// @lc code=start
class Solution {
    public int maxProduct(int[] nums) {
        int n = nums.length;
        int ans = nums[0], min = nums[0], max = nums[0];
        for (int i = 1; i < n; i++) {
            int number = nums[i];

            if (number < 0) {
                int temp = max;
                max = min;
                min = temp;
            }
            max = Math.max(number, number * max);
            min = Math.min(number, number * min);

            ans = Math.max(ans, max);
        }
        return ans;
    }
}
// @lc code=end
