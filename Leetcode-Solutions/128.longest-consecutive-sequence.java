import java.util.HashMap;
import java.util.HashSet;

/*
 * @lc app=leetcode id=128 lang=java
 *
 * [128] Longest Consecutive Sequence
 *
 * https://leetcode.com/problems/longest-consecutive-sequence/description/
 *
 * algorithms
 * Medium (49.08%)
 * Likes:    11916
 * Dislikes: 508
 * Total Accepted:    810.5K
 * Total Submissions: 1.7M
 * Testcase Example:  '[100,4,200,1,3,2]'
 *
 * Given an unsorted array of integers nums, return the length of the longest
 * consecutive elements sequence.
 * 
 * You must write an algorithm that runs in O(n) time.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [100,4,200,1,3,2]
 * Output: 4
 * Explanation: The longest consecutive elements sequence is [1, 2, 3, 4].
 * Therefore its length is 4.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [0,3,7,2,5,8,4,6,0,1]
 * Output: 9
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 0 <= nums.length <= 10^5
 * -10^9 <= nums[i] <= 10^9
 * 
 * 
 */

// @lc code=start
class Solution {
    public int longestConsecutive(int[] nums) {
        HashSet<Integer> set = new HashSet<>();
        for (int num : nums)
            set.add(num);
        int res = 0, cnt = 0, temp = 0;
        for (int num : nums) {
            cnt = 1;
            // to right
            temp = num + 1;
            while (set.contains(temp)) {
                cnt++;
                set.remove(temp++);
            }
            // to left
            temp = num - 1;
            while (set.contains(temp)) {
                cnt++;
                set.remove(temp--);
            }
            res = Math.max(res, cnt);
        }
        return res;
    }
}
// @lc code=end
