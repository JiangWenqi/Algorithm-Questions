// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem838.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=838 lang=cpp
 *
 * [838] Push Dominoes
 *
 * https://leetcode.com/problems/push-dominoes/description/
 *
 * algorithms
 * Medium (52.66%)
 * Likes:    2290
 * Dislikes: 149
 * Total Accepted:    77.7K
 * Total Submissions: 141.3K
 * Testcase Example:  '"RR.L"'
 *
 * There are n dominoes in a line, and we place each domino vertically upright.
 * In the beginning, we simultaneously push some of the dominoes either to the
 * left or to the right.
 *
 * After each second, each domino that is falling to the left pushes the
 * adjacent domino on the left. Similarly, the dominoes falling to the right
 * push their adjacent dominoes standing on the right.
 *
 * When a vertical domino has dominoes falling on it from both sides, it stays
 * still due to the balance of the forces.
 *
 * For the purposes of this question, we will consider that a falling domino
 * expends no additional force to a falling or already fallen domino.
 *
 * You are given a string dominoes representing the initial state where:
 *
 *
 * dominoes[i] = 'L', if the i^th domino has been pushed to the left,
 * dominoes[i] = 'R', if the i^th domino has been pushed to the right, and
 * dominoes[i] = '.', if the i^th domino has not been pushed.
 *
 *
 * Return a string representing the final state.
 *
 *
 * Example 1:
 *
 *
 * Input: dominoes = "RR.L"
 * Output: "RR.L"
 * Explanation: The first domino expends no additional force on the second
 * domino.
 *
 *
 * Example 2:
 *
 *
 * Input: dominoes = ".L.R...LR..L.."
 * Output: "LL.RR.LLRRLL.."
 *
 *
 *
 * Constraints:
 *
 *
 * n == dominoes.length
 * 1 <= n <= 10^5
 * dominoes[i] is either 'L', 'R', or '.'.
 *
 *
 */

 // @lc code=start
class Solution {
public:
    string pushDominoes(string dominoes) {
        dominoes = 'L' + dominoes + 'R';
        int n = dominoes.size();
        vector<int> ls(n, 0), rs(n, 0);
        for (int i = 0, j = 0; i < n; i++) {
            if (dominoes[i] != '.') j = i;
            ls[i] = j;
        }
        for (int i = n - 1, j = n - 1; i >= 0; i--) {
            if (dominoes[i] != '.') j = i;
            rs[i] = j;
        }
        for (int i = 0; i < n - 1; i++) {
            char l = dominoes[ls[i]], r = dominoes[rs[i]];
            if (l == 'L' && r == 'L') {
                dominoes[i] = 'L';
            } else if (l == 'R' && r == 'R') {
                dominoes[i] = 'R';
            } else if (l == 'L' && r == 'R') {
                dominoes[i] = '.';
            } else {
                if (i - ls[i] < rs[i] - i) {
                    dominoes[i] = l;
                } else if (i - ls[i] > rs[i] - i) {
                    dominoes[i] = r;
                } else {
                    dominoes[i] = '.';
                }
            }
        }
        return dominoes.substr(1, n - 2);
    }
};
// @lc code=end

