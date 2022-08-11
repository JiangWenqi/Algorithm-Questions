/*
 * @lc app=leetcode id=8 lang=java
 *
 * [8] String to Integer (atoi)
 */

// @lc code=start
class Solution {
    public int myAtoi(String s) {
        int i = 0;
        int result = 0;
        int sign = 1;
        // base
        if (s.length() == 0)
            return 0;

        // discard white space
        while (i < s.length() && s.charAt(i) == ' ')
            i++;

        // check the sign
        if (i < s.length() && (s.charAt(i) == '+' || s.charAt(i) == '-'))
            sign = (s.charAt(i++) == '-') ? -1 : 1;

        // proceed only if the char is digits
        while (i < s.length() && s.charAt(i) >= '0' && s.charAt(i) <= '9') {
            // Since we are doing r = r * 10 + digit formula
            // when r > max / 10 if u do * 10 it will overflow
            // if r == max / 10 then any number + 7 will overflow
            // same case for under flow also
            // both case we should handle
            if (result > Integer.MAX_VALUE / 10
                    || (result == Integer.MAX_VALUE / 10 && s.charAt(i) - '0' > Integer.MAX_VALUE % 10))
                return (sign == 1) ? Integer.MAX_VALUE : Integer.MIN_VALUE;

            result = result * 10 + (s.charAt(i++) - '0');
        }

        return result * sign;
    }
}
// @lc code=end
