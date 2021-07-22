import java.util.HashSet;

/*
 * @lc app=leetcode id=217 lang=java
 *
 * [217] Contains Duplicate
 */

// @lc code=start
class Solution {
    public boolean containsDuplicate(int[] nums) {
        HashSet<Integer> set = new HashSet<>(nums.length);
        for (int num : nums) {
            if (set.contains(num))
                return true;
            else
                set.add(num);
        }
        return false;
    }
}
// @lc code=end
