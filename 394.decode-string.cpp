// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem394.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=394 lang=cpp
 *
 * [394] Decode String
 *
 * https://leetcode.com/problems/decode-string/description/
 *
 * algorithms
 * Medium (56.80%)
 * Likes:    8706
 * Dislikes: 376
 * Total Accepted:    522.6K
 * Total Submissions: 920.1K
 * Testcase Example:  '"3[a]2[bc]"'
 *
 * Given an encoded string, return its decoded string.
 *
 * The encoding rule is: k[encoded_string], where the encoded_string inside the
 * square brackets is being repeated exactly k times. Note that k is guaranteed
 * to be a positive integer.
 *
 * You may assume that the input string is always valid; there are no extra
 * white spaces, square brackets are well-formed, etc. Furthermore, you may
 * assume that the original data does not contain any digits and that digits
 * are only for those repeat numbers, k. For example, there will not be input
 * like 3a or 2[4].
 *
 * The test cases are generated so that the length of the output will never
 * exceed 10^5.
 *
 *
 * Example 1:
 *
 *
 * Input: s = "3[a]2[bc]"
 * Output: "aaabcbc"
 *
 *
 * Example 2:
 *
 *
 * Input: s = "3[a2[c]]"
 * Output: "accaccacc"
 *
 *
 * Example 3:
 *
 *
 * Input: s = "2[abc]3[cd]ef"
 * Output: "abcabccdcdcdef"
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 30
 * s consists of lowercase English letters, digits, and square brackets
 * '[]'.
 * s is guaranteed to be a valid input.
 * All the integers in s are in the range [1, 300].
 *
 *
 */

 // @lc code=start
class Solution {
public:
    string decodeString(string s) {
        stack<char> stk;
        string res;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ']') {
                string str;
                // get string in []
                while (stk.top() != '[') {
                    str = stk.top() + str;
                    stk.pop();
                }
                // pop [
                stk.pop();
                string number;
                while (!stk.empty() && isdigit(stk.top())) {
                    number = stk.top() + number;
                    stk.pop();
                }
                int k = stoi(number);
                while (k--) {
                    for (char& c : str) stk.push(c);
                }
            } else {
                stk.push(s[i]);
            }

        }
        while (!stk.empty()) {
            res = stk.top() + res;
            stk.pop();
        }
        return res;

    }
};
// @lc code=end

