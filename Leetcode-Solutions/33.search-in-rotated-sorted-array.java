/*
 * @lc app=leetcode id=33 lang=java
 *
 * [33] Search in Rotated Sorted Array
 */

// @lc code=start
class Solution {
    public int search(int[] nums, int target) {

        int n = nums.length, l = 0, r = n - 1;

        // 4,5,6,7,0,1,2 target = 0
        while (l <= r) {
            int mid = l + r >> 1;
            if (nums[mid] == target) {
                return mid;
            }
            // 7 > 4
            if (nums[mid] >= nums[l]) {
                if (nums[mid] > target && nums[l] <= target) {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }

            } else if (nums[mid] <= nums[r]) {
                if (nums[mid] < target && nums[r] >= target) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
        }

        return -1;

    }
}
// @lc code=end
