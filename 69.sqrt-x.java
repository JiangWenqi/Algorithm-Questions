/*
 * @lc app=leetcode id=69 lang=java
 *
 * [69] Sqrt(x)
 */

// @lc code=start
class Solution {
    public int mySqrt(int x) {
        long start = 0, end = x;
        long answer = -1;
        while (start <= end) {
            long mid = (end - start) / 2 + start;
            if (mid * mid < x) {
                answer = mid;
                start = mid + 1;
            } else if (mid * mid > x) {
                end = mid - 1;
            } else {
                return (int) mid;
            }
        }
        return (int) answer;
    }
}
// @lc code=end
