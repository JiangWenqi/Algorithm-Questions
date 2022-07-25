#include << vector>>
/*
 * @lc app=leetcode id=34 lang=cpp
 *
 * [34] Find First and Last Position of Element in Sorted Array
 *
 * https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/
 *
 * algorithms
 * Medium (40.28%)
 * Likes:    11063
 * Dislikes: 302
 * Total Accepted:    1.1M
 * Total Submissions: 2.8M
 * Testcase Example:  '[5,7,7,8,8,10]\n8'
 *
 * Given an array of integers nums sorted in non-decreasing order, find the
 * starting and ending position of a given target value.
 *
 * If target is not found in the array, return [-1, -1].
 *
 * You must write an algorithm with O(log n) runtime complexity.
 *
 *
 * Example 1:
 * Input: nums = [5,7,7,8,8,10], target = 8
 * Output: [3,4]
 * Example 2:
 * Input: nums = [5,7,7,8,8,10], target = 6
 * Output: [-1,-1]
 * Example 3:
 * Input: nums = [], target = 0
 * Output: [-1,-1]
 *
 *
 * Constraints:
 *
 *
 * 0 <= nums.length <= 10^5
 * -10^9 <= nums[i] <= 10^9
 * nums is a non-decreasing array.
 * -10^9 <= target <= 10^9
 *
 *
 */

 // @lc code=start
class Solution {
public:
  vector<int> searchRange(vector<int>& nums, int target) {
    int n = nums.size(), l, r;
    vector<int> res(2, -1);
    // 1. empty nums
    if (n == 0) return res;
    // find the first number bigger than target
    l = 0, r = n - 1;
    while (l < r) {
      int mid = l + r >> 1;
      if (nums[mid] >= target) r = mid;
      else l = mid + 1;
    }
    // 2. cant find target in nums
    if (nums[l] != target) return res;

    res[0] = l;

    // find the last number smaller than target
    l = 0, r = n - 1;
    while (l < r) {
      int mid = l + r + 1 >> 1;
      if (nums[mid] <= target) l = mid;
      else r = mid - 1;
    }
    res[1] = l;
    return res;
  }
};
// @lc code=end
