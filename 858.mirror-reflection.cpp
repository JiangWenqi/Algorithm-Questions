/*
 * @lc app=leetcode id=858 lang=cpp
 *
 * [858] Mirror Reflection
 *
 * https://leetcode.com/problems/mirror-reflection/description/
 *
 * algorithms
 * Medium (59.54%)
 * Likes:    616
 * Dislikes: 1351
 * Total Accepted:    39.8K
 * Total Submissions: 65.5K
 * Testcase Example:  '2\n1'
 *
 * There is a special square room with mirrors on each of the four walls.
 * Except for the southwest corner, there are receptors on each of the
 * remaining corners, numbered 0, 1, and 2.
 *
 * The square room has walls of length p and a laser ray from the southwest
 * corner first meets the east wall at a distance q from the 0^th receptor.
 *
 * Given the two integers p and q, return the number of the receptor that the
 * ray meets first.
 *
 * The test cases are guaranteed so that the ray will meet a receptor
 * eventually.
 *
 *
 * Example 1:
 *
 *
 * Input: p = 2, q = 1
 * Output: 2
 * Explanation: The ray meets receptor 2 the first time it gets reflected back
 * to the left wall.
 *
 *
 * Example 2:
 *
 *
 * Input: p = 3, q = 1
 * Output: 1
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= q <= p <= 1000
 *
 *
 */

 // @lc code=start
class Solution {
private:
    int gcd(int a, int b) {
        return b ? gcd(b, a % b) : a;
    }
public:
    int mirrorReflection(int p, int q) {
        int lcm = p * q / gcd(p, q);
        int x = lcm / p, y = lcm / q;
        while (y % 2) {
            if (x % 2) return 1;
            else return 0;
        }
        return 2;
    }
};
// @lc code=end

