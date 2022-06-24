/*
 * @lc app=leetcode id=215 lang=java
 *
 * [215] Kth Largest Element in an Array
 *
 * https://leetcode.com/problems/kth-largest-element-in-an-array/description/
 *
 * algorithms
 * Medium (64.71%)
 * Likes:    10443
 * Dislikes: 551
 * Total Accepted:    1.4M
 * Total Submissions: 2.2M
 * Testcase Example:  '[3,2,1,5,6,4]\n2'
 *
 * Given an integer array nums and an integer k, return the k^th largest
 * element in the array.
 * 
 * Note that it is the k^th largest element in the sorted order, not the k^th
 * distinct element.
 * 
 * 
 * Example 1:
 * Input: nums = [3,2,1,5,6,4], k = 2
 * Output: 5
 * Example 2:
 * Input: nums = [3,2,3,1,2,4,5,5,6], k = 4
 * Output: 4
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= k <= nums.length <= 10^4
 * -10^4 <= nums[i] <= 10^4
 * 
 * 
 */

// @lc code=start
class Solution {
    private int quickSort(int l, int r, int[] nums, int k) {
        if (l == r)
            return nums[k];
        int i = l - 1, j = r + 1, x = nums[l + r >> 1];
        while (i < j) {
            do {
                i++;
            } while (nums[i] > x);

            do {
                j--;
            } while (nums[j] < x);

            if (i < j) {
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
            }
        }
        if (k <= j) {
            return quickSort(l, j, nums, k);
        } else {
            return quickSort(j + 1, r, nums, k);
        }
    }

    public int findKthLargest(int[] nums, int k) {
        return quickSort(0, nums.length - 1, nums, k - 1);
    }
}
// @lc code=end
