// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem990.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=990 lang=cpp
 *
 * [990] Satisfiability of Equality Equations
 *
 * https://leetcode.com/problems/satisfiability-of-equality-equations/description/
 *
 * algorithms
 * Medium (50.71%)
 * Likes:    2325
 * Dislikes: 33
 * Total Accepted:    73K
 * Total Submissions: 144.7K
 * Testcase Example:  '["a==b","b!=a"]'
 *
 * You are given an array of strings equations that represent relationships
 * between variables where each string equations[i] is of length 4 and takes
 * one of two different forms: "xi==yi" or "xi!=yi".Here, xi and yi are
 * lowercase letters (not necessarily different) that represent one-letter
 * variable names.
 *
 * Return true if it is possible to assign integers to variable names so as to
 * satisfy all the given equations, or false otherwise.
 *
 *
 * Example 1:
 *
 *
 * Input: equations = ["a==b","b!=a"]
 * Output: false
 * Explanation: If we assign say, a = 1 and b = 1, then the first equation is
 * satisfied, but not the second.
 * There is no way to assign the variables to satisfy both equations.
 *
 *
 * Example 2:
 *
 *
 * Input: equations = ["b==a","a==b"]
 * Output: true
 * Explanation: We could assign a = 1 and b = 1 to satisfy both equations.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= equations.length <= 500
 * equations[i].length == 4
 * equations[i][0] is a lowercase letter.
 * equations[i][1] is either '=' or '!'.
 * equations[i][2] is '='.
 * equations[i][3] is a lowercase letter.
 *
 *
 */

 // @lc code=start
class Solution {
private:
    int p[26];

    int find(int x) {
        if (p[x] != x) p[x] = find(p[x]);
        return p[x];
    }
public:
    bool equationsPossible(vector<string>& equations) {
        for (int i = 0; i < 26; i++) {
            p[i] = i;
        }
        for (string& equation : equations) {
            int a = equation[0] - 'a', b = equation[3] - 'a';
            if (equation[1] == '=') {
                p[find(a)] = find(b);
            }
        }

        for (string& equation : equations) {
            int a = equation[0] - 'a', b = equation[3] - 'a';
            if (equation[1] == '!' && find(a) == find(b)) {
                return false;
            }
        }
        return true;

    }
};
// @lc code=end

