// @before-stub-for-debug-begin
#include <string>
#include <vector>

#include "commoncppproblem665.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=665 lang=cpp
 *
 * [665] Non-decreasing Array
 *
 * https://leetcode.com/problems/non-decreasing-array/description/
 *
 * algorithms
 * Medium (21.65%)
 * Likes:    4230
 * Dislikes: 685
 * Total Accepted:    193.9K
 * Total Submissions: 858.1K
 * Testcase Example:  '[4,2,3]'
 *
 * Given an array nums with n integers, your task is to check if it could
 * become non-decreasing by modifying at most one element.
 *
 * We define an array is non-decreasing if nums[i] <= nums[i + 1] holds for
 * every i (0-based) such that (0 <= i <= n - 2).
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [4,2,3]
 * Output: true
 * Explanation: You could modify the first 4 to 1 to get a non-decreasing
 * array.
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [4,2,1]
 * Output: false
 * Explanation: You can't get a non-decreasing array by modify at most one
 * element.
 *
 *
 *
 * Constraints:
 *
 *
 * n == nums.length
 * 1 <= n <= 10^4
 * -10^5 <= nums[i] <= 10^5
 *
 *
 */

// @lc code=start
class Solution {
 public:
  bool checkPossibility(vector<int>& nums) {
    int n = nums.size();
    bool changed = false;
    for (int i = 1; i < n; i++) {
      if (nums[i - 1] > nums[i]) {
        if (changed)
          return false;
        else if (i > 1 && i < n - 1 && nums[i - 2] > nums[i] &&
                 nums[i - 1] > nums[i + 1])
          return false;
        changed = true;
      }
    }
    return true;
  }
};
// @lc code=end
