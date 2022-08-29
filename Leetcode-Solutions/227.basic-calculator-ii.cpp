// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <stack>
#include "commoncppproblem227.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=227 lang=cpp
 *
 * [227] Basic Calculator II
 *
 * https://leetcode.com/problems/basic-calculator-ii/description/
 *
 * algorithms
 * Medium (42.00%)
 * Likes:    4785
 * Dislikes: 611
 * Total Accepted:    464.1K
 * Total Submissions: 1.1M
 * Testcase Example:  '"3+2*2"'
 *
 * Given a string s which represents an expression, evaluate this expression
 * and return its value. 
 *
 * The integer division should truncate toward zero.
 *
 * You may assume that the given expression is always valid. All intermediate
 * results will be in the range of [-2^31, 2^31 - 1].
 *
 * Note: You are not allowed to use any built-in function which evaluates
 * strings as mathematical expressions, such as eval().
 *
 *
 * Example 1:
 * Input: s = "3+2*2"
 * Output: 7
 * Example 2:
 * Input: s = " 3/2 "
 * Output: 1
 * Example 3:
 * Input: s = " 3+5 / 2 "
 * Output: 5
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 3 * 10^5
 * s consists of integers and operators ('+', '-', '*', '/') separated by some
 * number of spaces.
 * s represents a valid expression.
 * All the integers in the expression are non-negative integers in the range
 * [0, 2^31 - 1].
 * The answer is guaranteed to fit in a 32-bit integer.
 *
 *
 */

 // @lc code=start
class Solution {
public:
    int calculate(string s) {
        stack<long> stk;
        int n = s.size(), lastNum = 0, curr = 0;
        char lastOp = '+';
        for (int i = 0; i < n; i++) {
            char c = s[i];
            if (isdigit(c))
                curr = curr * 10 + (c - '0');
            // if the char is not digit or space or it is the last char of s
            if ((!isdigit(c) && !isspace(c)) || i == n - 1) {
                if (lastOp == '+') {
                    stk.push(curr);
                } else if (lastOp == '-') {
                    stk.push(-curr);
                } else if (lastOp == '*') {
                    lastNum = stk.top();
                    stk.pop();
                    stk.push(lastNum * curr);
                } else if (lastOp == '/') {
                    lastNum = stk.top();
                    stk.pop();
                    stk.push(lastNum / curr);
                }
                lastOp = c;
                curr = 0;
            }
        }
        int res = 0;
        while (!stk.empty()) {
            res += stk.top();
            stk.pop();
        }
        return res;
    }
};
// @lc code=end

