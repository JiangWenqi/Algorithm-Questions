/*
 * @lc app=leetcode id=967 lang=cpp
 *
 * [967] Numbers With Same Consecutive Differences
 *
 * https://leetcode.com/problems/numbers-with-same-consecutive-differences/description/
 *
 * algorithms
 * Medium (47.95%)
 * Likes:    1816
 * Dislikes: 158
 * Total Accepted:    79K
 * Total Submissions: 148.7K
 * Testcase Example:  '3\n7'
 *
 * Return all non-negative integers of length n such that the absolute
 * difference between every two consecutive digits is k.
 *
 * Note that every number in the answer must not have leading zeros. For
 * example, 01 has one leading zero and is invalid.
 *
 * You may return the answer in any order.
 *
 *
 * Example 1:
 *
 *
 * Input: n = 3, k = 7
 * Output: [181,292,707,818,929]
 * Explanation: Note that 070 is not a valid number, because it has leading
 * zeroes.
 *
 *
 * Example 2:
 *
 *
 * Input: n = 2, k = 1
 * Output: [10,12,21,23,32,34,43,45,54,56,65,67,76,78,87,89,98]
 *
 *
 *
 * Constraints:
 *
 *
 * 2 <= n <= 9
 * 0 <= k <= 9
 *
 *
 */

 // @lc code=start
class Solution {
private:
    vector<int> res;

    void dfs(int idx, int num, int n, int k) {
        if (idx == n) {
            res.push_back(num);
            return;
        }
        if (num % 10 - k >= 0) dfs(idx + 1, num * 10 + num % 10 - k, n, k);
        if (k && num % 10 + k < 10) dfs(idx + 1, num * 10 + num % 10 + k, n, k);

    }

public:
    vector<int> numsSameConsecDiff(int n, int k) {
        for (int i = 1; i < 10; i++)
            dfs(1, i, n, k);

        return res;
    }
};
// @lc code=end

