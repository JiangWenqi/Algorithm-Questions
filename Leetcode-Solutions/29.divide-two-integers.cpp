/*
 * @lc app=leetcode id=29 lang=cpp
 *
 * [29] Divide Two Integers
 *
 * https://leetcode.com/problems/divide-two-integers/description/
 *
 * algorithms
 * Medium (16.99%)
 * Likes:    2910
 * Dislikes: 10101
 * Total Accepted:    486.1K
 * Total Submissions: 2.8M
 * Testcase Example:  '10\n3'
 *
 * Given two integers dividend and divisor, divide two integers without using
 * multiplication, division, and mod operator.
 *
 * The integer division should truncate toward zero, which means losing its
 * fractional part. For example, 8.345 would be truncated to 8, and -2.7335
 * would be truncated to -2.
 *
 * Return the quotient after dividing dividend by divisor.
 *
 * Note: Assume we are dealing with an environment that could only store
 * integers within the 32-bit signed integer range: [−2^31, 2^31 − 1]. For this
 * problem, if the quotient is strictly greater than 2^31 - 1, then return 2^31
 * - 1, and if the quotient is strictly less than -2^31, then return -2^31.
 *
 *
 * Example 1:
 *
 *
 * Input: dividend = 10, divisor = 3
 * Output: 3
 * Explanation: 10/3 = 3.33333.. which is truncated to 3.
 *
 *
 * Example 2:
 *
 *
 * Input: dividend = 7, divisor = -3
 * Output: -2
 * Explanation: 7/-3 = -2.33333.. which is truncated to -2.
 *
 *
 *
 * Constraints:
 *
 *
 * -2^31 <= dividend, divisor <= 2^31 - 1
 * divisor != 0
 *
 *
 */

// @lc code=start
class Solution
{
public:
    int divide(int x, int y)
    {
        if (x == INT_MIN && y == -1)
        {
            return INT_MAX; //如果除法溢出，返回2 ^ 31 - 1
        }
        long a = labs(x), b = labs(y), ans = 0;
        int sign = x > 0 ^ y > 0 ? -1 : 1;

        while (a >= b)
        { //当a比b大，说明a/b至少等于1
            long temp = b, m = 1;
            while (temp << 1 <= a)
            {               //找到最大的小于被除数的除数倍数
                temp <<= 1; //除数倍增
                m <<= 1;    //减法个数倍增
            }
            a -= temp; //除数变小
            ans += m;  //加上个数
        }
        ans *= sign;
        return ans;
    }
};

// @lc code=end
