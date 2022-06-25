// @before-stub-for-debug-begin
#include <string>
#include <vector>

#include "commoncppproblem213.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=213 lang=cpp
 *
 * [213] House Robber II
 *
 * https://leetcode.com/problems/house-robber-ii/description/
 *
 * algorithms
 * Medium (40.13%)
 * Likes:    5881
 * Dislikes: 96
 * Total Accepted:    420.8K
 * Total Submissions: 1M
 * Testcase Example:  '[2,3,2]'
 *
 * You are a professional robber planning to rob houses along a street. Each
 * house has a certain amount of money stashed. All houses at this place are
 * arranged in a circle. That means the first house is the neighbor of the last
 * one. Meanwhile, adjacent houses have a security system connected, and it
 * will automatically contact the police if two adjacent houses were broken
 * into on the same night.
 *
 * Given an integer array nums representing the amount of money of each house,
 * return the maximum amount of money you can rob tonight without alerting the
 * police.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [2,3,2]
 * Output: 3
 * Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money
 * = 2), because they are adjacent houses.
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [1,2,3,1]
 * Output: 4
 * Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
 * Total amount you can rob = 1 + 3 = 4.
 *
 *
 * Example 3:
 *
 *
 * Input: nums = [1,2,3]
 * Output: 3
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 100
 * 0 <= nums[i] <= 1000
 *
 *
 */

// @lc code=start
class Solution {
 private:
  int rob(int start, int end, vector<int>& nums) {
    int first = nums[start], second = max(nums[start], nums[start + 1]);
    for (int i = start + 2; i <= end; i++) {
      int third = max(first + nums[i], second);
      first = second;
      second = third;
    }
    return second;
  }

 public:
  int rob(vector<int>& nums) {
    if (nums.size() == 1)
      return nums[0];
    else if (nums.size() == 2)
      return max(nums[0], nums[1]);
    else
      return max(rob(1, nums.size() - 1, nums), rob(0, nums.size() - 2, nums));
  }
};
// @lc code=end
