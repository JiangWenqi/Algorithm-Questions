// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem869.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=869 lang=cpp
 *
 * [869] Reordered Power of 2
 *
 * https://leetcode.com/problems/reordered-power-of-2/description/
 *
 * algorithms
 * Medium (60.97%)
 * Likes:    1596
 * Dislikes: 332
 * Total Accepted:    80.7K
 * Total Submissions: 126.8K
 * Testcase Example:  '1'
 *
 * You are given an integer n. We reorder the digits in any order (including
 * the original order) such that the leading digit is not zero.
 *
 * Return true if and only if we can do this so that the resulting number is a
 * power of two.
 *
 *
 * Example 1:
 *
 *
 * Input: n = 1
 * Output: true
 *
 *
 * Example 2:
 *
 *
 * Input: n = 10
 * Output: false
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= n <= 10^9
 *
 *
 */

 // @lc code=start
class Solution {
private:
    bool check(int a, int b) {
        int count[10] = { 0 };
        while (a) {
            count[a % 10]++;
            a /= 10;
        }
        while (b) {
            count[b % 10]--;
            b /= 10;
        }
        for (int i = 0; i < 10; i++) {
            if (count[i] != 0) return false;
        }
        return true;
    }
public:
    bool reorderedPowerOf2(int n) {
        for (int i = 1; i < 1e9; i *= 2) {
            if (check(n, i)) return true;
        }
        return false;
    }
};
// @lc code=end

