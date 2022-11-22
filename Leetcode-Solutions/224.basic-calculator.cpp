/*
 * @lc app=leetcode id=224 lang=cpp
 *
 * [224] Basic Calculator
 *
 * https://leetcode.com/problems/basic-calculator/description/
 *
 * algorithms
 * Hard (41.19%)
 * Likes:    4636
 * Dislikes: 354
 * Total Accepted:    342.1K
 * Total Submissions: 821K
 * Testcase Example:  '"1 + 1"'
 *
 * Given a string s representing a valid expression, implement a basic
 * calculator to evaluate it, and return the result of the evaluation.
 *
 * Note: You are not allowed to use any built-in function which evaluates
 * strings as mathematical expressions, such as eval().
 *
 *
 * Example 1:
 *
 *
 * Input: s = "1 + 1"
 * Output: 2
 *
 *
 * Example 2:
 *
 *
 * Input: s = " 2-1 + 2 "
 * Output: 3
 *
 *
 * Example 3:
 *
 *
 * Input: s = "(1+(4+5+2)-3)+(6+8)"
 * Output: 23
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 3 * 10^5
 * s consists of digits, '+', '-', '(', ')', and ' '.
 * s represents a valid expression.
 * '+' is not used as a unary operation (i.e., "+1" and "+(2 + 3)" is
 * invalid).
 * '-' could be used as a unary operation (i.e., "-1" and "-(2 + 3)" is
 * valid).
 * There will be no two consecutive operators in the input.
 * Every number and running calculation will fit in a signed 32-bit integer.
 *
 *
 */

// @lc code=start
class Solution
{
public:
    void eval(stack<int> &num, stack<char> &op)
    {
        auto b = num.top();
        num.pop();
        auto a = num.top();
        num.pop();
        auto c = op.top();
        op.pop();
        int r;
        if (c == '+')
            r = a + b;
        else
            r = a - b;
        num.push(r);
    }

    int calculate(string rs)
    {
        string s;
        for (auto c : rs)
            if (c != ' ')
                s += c;
        stack<int> num;
        stack<char> op;
        for (int i = 0; i < s.size(); i++)
        {
            auto c = s[i];
            if (c == ' ')
                continue;
            if (isdigit(c))
            {
                int x = 0, j = i;
                while (j < s.size() && isdigit(s[j]))
                    x = x * 10 + (s[j++] - '0');
                i = j - 1;
                num.push(x);
            }
            else if (c == '(')
                op.push(c);
            else if (c == ')')
            {
                while (op.top() != '(')
                    eval(num, op);
                op.pop();
            }
            else
            {
                if (!i || s[i - 1] == '(' || s[i - 1] == '+' || s[i - 1] == '-') // 特殊处理符号和正号
                    num.push(0);
                while (op.size() && op.top() != '(')
                    eval(num, op);
                op.push(c);
            }
        }
        while (op.size())
            eval(num, op);
        return num.top();
    }
};
// @lc code=end
