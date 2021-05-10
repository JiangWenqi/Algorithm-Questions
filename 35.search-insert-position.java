/*
 * @lc app=leetcode id=35 lang=java
 *
 * [35] Search Insert Position
 */

// @lc code=start
class Solution {
    public int searchInsert(int[] nums, int target) {
        int header = 0, tailer = nums.length - 1;

        while (header <= tailer) {
            int mid = (tailer - header) / 2 + header;
            if (nums[mid] > target) {
                tailer = mid - 1;
            } else if (nums[mid] < target) {
                header = mid + 1;
            } else {
                return mid;
            }
        }
        return header;
    }
}
// @lc code=end
