/*
 * @lc app=leetcode id=33 lang=java
 *
 * [33] Search in Rotated Sorted Array
 */

// @lc code=start
class Solution {
    public int search(int[] nums, int target) {
        int n = nums.length;
        int l = 0, r = n - 1;
        // 4, 5, 6, 7, 0, 1, 2 => find the idx of 7
        while (l < r) {
            int mid = l + r + 1 >> 1;
            if (nums[mid] >= nums[0])
                l = mid;
            else
                r = mid - 1;
        }

        // check target in left or right
        if (target >= nums[0]) {
            r = l;
            l = 0;
        } else {
            l += 1;
            r = n - 1;
        }

        // normal binary search
        while (l <= r) {
            int mid = l + r >> 1;
            if (nums[mid] > target)
                r = mid - 1;
            else if (nums[mid] < target)
                l = mid + 1;
            else
                return mid;
        }
        return -1;

    }
}
// @lc code=end
