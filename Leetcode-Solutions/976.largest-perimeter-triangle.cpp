/*
 * @lc app=leetcode id=976 lang=cpp
 *
 * [976] Largest Perimeter Triangle
 *
 * https://leetcode.com/problems/largest-perimeter-triangle/description/
 *
 * algorithms
 * Easy (52.19%)
 * Likes:    1889
 * Dislikes: 259
 * Total Accepted:    139K
 * Total Submissions: 257.7K
 * Testcase Example:  '[2,1,2]'
 *
 * Given an integer array nums, return the largest perimeter of a triangle with
 * a non-zero area, formed from three of these lengths. If it is impossible to
 * form any triangle of a non-zero area, return 0.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [2,1,2]
 * Output: 5
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [1,2,1]
 * Output: 0
 *
 *
 *
 * Constraints:
 *
 *
 * 3 <= nums.length <= 10^4
 * 1 <= nums[i] <= 10^6
 *
 *
 */

 // @lc code=start
class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i = nums.size() - 1; i >= 2; i--) {
            int a = nums[i - 2], b = nums[i - 1], c = nums[i];
            if (a + b > c)
                return a + b + c;
        }
        return 0;
    }
};
// @lc code=end

