/*
 * @lc app=leetcode id=66 lang=java
 *
 * [66] Plus One
 */

// @lc code=start
class Solution {
    public int[] plusOne(int[] digits) {
        int carry = 1;
        int length = digits.length;

        for (int i = length - 1; i >= 0; i--) {
            digits[i] += carry;
            if (digits[i] <= 9) {
                return digits;
            }
            digits[i] = 0;
        }

        int[] ans = new int[length + 1];
        ans[0] = 1;
        return ans;
    }
}
// @lc code=end
