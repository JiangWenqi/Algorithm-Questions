import java.util.Arrays;

/*
 * @lc app=leetcode id=462 lang=java
 *
 * [462] Minimum Moves to Equal Array Elements II
 *
 * https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/description/
 *
 * algorithms
 * Medium (59.21%)
 * Likes:    2274
 * Dislikes: 92
 * Total Accepted:    126.4K
 * Total Submissions: 213.5K
 * Testcase Example:  '[1,2,3]'
 *
 * Given an integer array nums of size n, return the minimum number of moves
 * required to make all array elements equal.
 * 
 * In one move, you can increment or decrement an element of the array by 1.
 * 
 * Test cases are designed so that the answer will fit in a 32-bit integer.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [1,2,3]
 * Output: 2
 * Explanation:
 * Only two moves are needed (remember each move increments or decrements one
 * element):
 * [1,2,3]  =>  [2,2,3]  =>  [2,2,2]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [1,10,2,9]
 * Output: 16
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * n == nums.length
 * 1 <= nums.length <= 10^5
 * -10^9 <= nums[i] <= 10^9
 * 
 * 
 */

// @lc code=start
class Solution {
    public int minMoves2(int[] nums) {
        Arrays.sort(nums);
        int res = 0, mid = nums[nums.length / 2];
        for (int num : nums) {
            res += Math.abs(num - mid);
        }
        return res;
    }
}
// @lc code=end
