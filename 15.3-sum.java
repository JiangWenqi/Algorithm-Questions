import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/*
 * @lc app=leetcode id=15 lang=java
 *
 * [15] 3Sum
 *
 * https://leetcode.com/problems/3sum/description/
 *
 * algorithms
 * Medium (31.36%)
 * Likes:    18550
 * Dislikes: 1779
 * Total Accepted:    2M
 * Total Submissions: 6.4M
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
    public List<List<Integer>> threeSum(int[] nums) {
        Arrays.sort(nums);
        int n = nums.length;
        List<List<Integer>> res = new ArrayList<>();
        for (int i = 0; i < n - 2; i++) {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            for (int l = i + 1, r = n - 1; l < r; l++) {
                if (l > i + 1 && nums[l] == nums[l - 1])
                    continue;
                while (l < r - 1 && nums[i] + nums[l] + nums[r - 1] >= 0)
                    r--;
                if (nums[i] + nums[l] + nums[r] == 0) {
                    List<Integer> three = new ArrayList<>();
                    three.add(nums[i]);
                    three.add(nums[l]);
                    three.add(nums[r]);
                    res.add(three);
                }

            }
        }
        return res;
    }
}
// @lc code=end
