/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 *
 * https://leetcode.com/problems/3sum/description/
 *
 * algorithms
 * Medium (31.23%)
 * Likes:    18034
 * Dislikes: 1733
 * Total Accepted:    2M
 * Total Submissions: 6.3M
 * Testcase Example:  '[-1,0,1,2,-1,-4]'
 *
 * Given an integer array nums, return all the triplets [nums[i], nums[j],
 * nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] +
 * nums[k] == 0.
 *
 * Notice that the solution set must not contain duplicate triplets.
 *
 *
 * Example 1:
 * Input: nums = [-1,0,1,2,-1,-4]
 * Output: [[-1,-1,2],[-1,0,1]]
 * Example 2:
 * Input: nums = []
 * Output: []
 * Example 3:
 * Input: nums = [0]
 * Output: []
 *
 *
 * Constraints:
 *
 *
 * 0 <= nums.length <= 3000
 * -10^5 <= nums[i] <= 10^5
 *
 *
 */

 // @lc code=start
class Solution {
public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> res;
    sort(nums.begin(), nums.end());
    int n = nums.size();
    for (int i = 0; i < n; i++) {
      if (i && nums[i] == nums[i - 1]) continue;
      for (int j = i + 1, k = n - 1; j < k; j++) {
        if (j > i + 1 && nums[j] == nums[j - 1]) continue;
        while (j < k - 1 && nums[i] + nums[j] + nums[k - 1] >= 0) k--;
        if (nums[i] + nums[j] + nums[k] == 0)
          res.push_back({ nums[i], nums[j], nums[k] });
      }
    }
    return res;
  }
};
// @lc code=end
