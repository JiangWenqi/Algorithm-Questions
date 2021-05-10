/*
 * @lc app=leetcode id=26 lang=java
 *
 * [26] Remove Duplicates from Sorted Array
 */

// @lc code=start
class Solution {
    public int removeDuplicates(int[] nums) {
        int count = 1;
        int lastIndex = 0;
        for (int i = 1; i < nums.length; i++) {
            if (nums[lastIndex] != nums[i]) {
                nums[++lastIndex] = nums[i];
                count++;
            }
        }
        return count;
    }
}
// @lc code=end

