/*
 * @lc app=leetcode id=16 lang=cpp
 *
 * [16] 3Sum Closest
 *
 * https://leetcode.com/problems/3sum-closest/description/
 *
 * algorithms
 * Medium (46.53%)
 * Likes:    6411
 * Dislikes: 328
 * Total Accepted:    844.5K
 * Total Submissions: 1.8M
 * Testcase Example:  '[-1,2,1,-4]\n1'
 *
 * Given an integer array nums of length n and an integer target, find three
 * integers in nums such that the sum is closest to target.
 *
 * Return the sum of the three integers.
 *
 * You may assume that each input would have exactly one solution.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [-1,2,1,-4], target = 1
 * Output: 2
 * Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [0,0,0], target = 1
 * Output: 0
 *
 *
 *
 * Constraints:
 *
 *
 * 3 <= nums.length <= 1000
 * -1000 <= nums[i] <= 1000
 * -10^4 <= target <= 10^4
 *
 *
 */

 // @lc code=start
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), res;
        for (int i = 0; i < n - 2; i++) {
            int l = i + 1, r = n - 1;
            while (l < r) {
                int sum = nums[i] + nums[l] + nums[r];
                if (sum < target) {
                    l++;
                    res = abs(res - target) < abs(sum - target) ? res : sum;
                } else if (sum > target) {
                    r--;
                    res = abs(res - target) < abs(sum - target) ? res : sum;
                } else {
                    return target;
                }
            }
        }
        return res;
    }
};
// @lc code=end

