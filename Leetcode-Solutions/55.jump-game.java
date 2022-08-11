/*
 * @lc app=leetcode id=55 lang=java
 *
 * [55] Jump Game
 */

// @lc code=start
class Solution {
    public boolean canJump(int[] nums) {
        int n = nums.length;
        int last = n - 1;

        for (int i = n - 2; i >= 0; i--) {
            int steps = nums[i];
            if (steps + i >= last)
                last = i;
        }
        return last == 0;
    }
}
// @lc code=end
