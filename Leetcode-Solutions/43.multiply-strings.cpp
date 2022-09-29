/*
 * @lc app=leetcode id=43 lang=cpp
 *
 * [43] Multiply Strings
 *
 * https://leetcode.com/problems/multiply-strings/description/
 *
 * algorithms
 * Medium (38.62%)
 * Likes:    5191
 * Dislikes: 2181
 * Total Accepted:    578.7K
 * Total Submissions: 1.5M
 * Testcase Example:  '"2"\n"3"'
 *
 * Given two non-negative integers num1 and num2 represented as strings, return
 * the product of num1 and num2, also represented as a string.
 *
 * Note: You must not use any built-in BigInteger library or convert the inputs
 * to integer directly.
 *
 *
 * Example 1:
 * Input: num1 = "2", num2 = "3"
 * Output: "6"
 * Example 2:
 * Input: num1 = "123", num2 = "456"
 * Output: "56088"
 *
 *
 * Constraints:
 *
 *
 * 1 <= num1.length, num2.length <= 200
 * num1 and num2 consist of digits only.
 * Both num1 and num2 do not contain any leading zero, except the number 0
 * itself.
 *
 *
 */

 // @lc code=start
class Solution {
public:
    string multiply(string num1, string num2) {
        vector<int> A, B;
        int n = num1.size(), m = num2.size();
        for (int i = n - 1; i >= 0; i--)
            A.emplace_back(num1[i] - '0');
        for (int j = m - 1; j >= 0; j--)
            B.emplace_back(num2[j] - '0');

        vector<int> C(n + m, 0); // n+m-1就足够用
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                C[i + j] += A[i] * B[j];

        // 将C里数的进位算进去
        for (int i = 0, t = 0; i < C.size(); i++) {
            t += C[i]; // 进位加上这个数
            C[i] = t % 10; // t模10就是当前位置的数
            t /= 10; // 进位时除以10
        }

        // 从后往前去掉开头多余的0，即只要找到第一个非0位置就可以了
        int k = C.size() - 1;
        while (k > 0 && !C[k]) // 如果最后有一个0要保留
            k--;

        // 从高位到低位得到答案
        string res;
        while (k >= 0) {
            res += C[k] + '0';
            k--;
        }

        return res;

    }
};
// @lc code=end

