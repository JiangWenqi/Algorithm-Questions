/*
 * @lc app=leetcode.cn id=67 lang=java
 *
 * [67] 二进制求和
 *
 * https://leetcode-cn.com/problems/add-binary/description/
 *
 * algorithms
 * Easy (47.30%)
 * Total Accepted:    20.3K
 * Total Submissions: 43K
 * Testcase Example:  '"11"\n"1"'
 *
 * 给定两个二进制字符串，返回他们的和（用二进制表示）。
 *
 * 输入为非空字符串且只包含数字 1 和 0。
 *
 * 示例 1:
 *
 * 输入: a = "11", b = "1"
 * 输出: "100"
 *
 * 示例 2:
 *
 * 输入: a = "1010", b = "1011"
 * 输出: "10101"
 *
 */
class Solution {
    public String addBinary(String a, String b) {

        int carry = 0;
        StringBuilder sb = new StringBuilder();
        for (int i = a.length() - 1, j = b.length() - 1; i >= 0 || j >= 0; i--, j--) {
            if (i >= 0) {
                carry += a.charAt(i) - '0';
            }
            if (j >= 0) {
                carry += b.charAt(j) - '0';
            }
            sb.append(carry % 2);
            carry = carry / 2;
        }
        if (carry != 0) {
            sb.append(carry);
        }
        return sb.reverse().toString();

    }

}
