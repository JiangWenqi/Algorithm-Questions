// @before-stub-for-debug-begin
#include <string>
#include <vector>

#include "commoncppproblem413.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=413 lang=cpp
 *
 * [413] Arithmetic Slices
 *
 * https://leetcode.com/problems/arithmetic-slices/description/
 *
 * algorithms
 * Medium (64.69%)
 * Likes:    4004
 * Dislikes: 253
 * Total Accepted:    235.8K
 * Total Submissions: 364.5K
 * Testcase Example:  '[1,2,3,4]'
 *
 * An integer array is called arithmetic if it consists of at least three
 * elements and if the difference between any two consecutive elements is the
 * same.
 *
 *
 * For example, [1,3,5,7,9], [7,7,7,7], and [3,-1,-5,-9] are arithmetic
 * sequences.
 *
 *
 * Given an integer array nums, return the number of arithmetic subarrays of
 * nums.
 *
 * A subarray is a contiguous subsequence of the array.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [1,2,3,4]
 * Output: 3
 * Explanation: We have 3 arithmetic slices in nums: [1, 2, 3], [2, 3, 4] and
 * [1,2,3,4] itself.
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [1]
 * Output: 0
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 5000
 * -1000 <= nums[i] <= 1000
 *
 *
 */

// @lc code=start
class Solution {
 public:
  int numberOfArithmeticSlices(vector<int>& nums) {
    int n = nums.size(), res = 0;
    vector<int> dp(n, 0);
    for (int i = 2; i < n; i++) {
      if (nums[i - 1] - nums[i - 2] == nums[i] - nums[i - 1]) {
        dp[i] = 1 + dp[i - 1];
        res += dp[i];
      }
    }
    return res;
  }
};
// @lc code=end
