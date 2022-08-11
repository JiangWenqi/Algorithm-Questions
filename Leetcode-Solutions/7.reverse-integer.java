/*
 * @lc app=leetcode id=7 lang=java
 *
 * [7] Reverse Integer
 */

// @lc code=start
class Solution {
    public int reverse(int x) {
        long r = 0;

        while (x != 0) {
            r = r * 10 + x % 10;
            x /= 10;
        }

        if (r >= Integer.MIN_VALUE && r <= Integer.MAX_VALUE) {
            return (int) r;
        } else {
            return 0;
        }

    }
}
// @lc code=end
