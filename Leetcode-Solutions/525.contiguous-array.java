import java.util.HashMap;

/*
 * @lc app=leetcode id=525 lang=java
 *
 * [525] Contiguous Array
 *
 * https://leetcode.com/problems/contiguous-array/description/
 *
 * algorithms
 * Medium (46.58%)
 * Likes:    5545
 * Dislikes: 236
 * Total Accepted:    269.8K
 * Total Submissions: 579.1K
 * Testcase Example:  '[0,1]'
 *
 * Given a binary array nums, return the maximum length of a contiguous
 * subarray with an equal number of 0 and 1.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [0,1]
 * Output: 2
 * Explanation: [0, 1] is the longest contiguous subarray with an equal number
 * of 0 and 1.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [0,1,0]
 * Output: 2
 * Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal
 * number of 0 and 1.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 10^5
 * nums[i] is either 0 or 1.
 * 
 * 
 */

// @lc code=start
class Solution {
    public int findMaxLength(int[] nums) {
        int res = 0;
        int n = nums.length, sum = 0;
        HashMap<Integer, Integer> psid = new HashMap<>();
        psid.put(0, -1);
        for (int i = 0; i < n; i++) {
            sum += nums[i] == 1 ? 1 : -1;
            if (psid.containsKey(sum)) {
                res = Math.max(res, i - psid.get(sum));
            } else {
                psid.put(sum, i);
            }
        }
        return res;
    }
}
// @lc code=end
