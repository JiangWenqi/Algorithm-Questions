/*
 * @lc app=leetcode id=907 lang=cpp
 *
 * [907] Sum of Subarray Minimums
 *
 * https://leetcode.com/problems/sum-of-subarray-minimums/description/
 *
 * algorithms
 * Medium (34.31%)
 * Likes:    5471
 * Dislikes: 373
 * Total Accepted:    130.8K
 * Total Submissions: 364.1K
 * Testcase Example:  '[3,1,2,4]'
 *
 * Given an array of integers arr, find the sum of min(b), where b ranges over
 * every (contiguous) subarray of arr. Since the answer may be large, return
 * the answer modulo 10^9 + 7.
 *
 *
 * Example 1:
 *
 *
 * Input: arr = [3,1,2,4]
 * Output: 17
 * Explanation:
 * Subarrays are [3], [1], [2], [4], [3,1], [1,2], [2,4], [3,1,2], [1,2,4],
 * [3,1,2,4].
 * Minimums are 3, 1, 2, 4, 1, 1, 2, 1, 1, 1.
 * Sum is 17.
 *
 *
 * Example 2:
 *
 *
 * Input: arr = [11,81,94,43,3]
 * Output: 444
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= arr.length <= 3 * 10^4
 * 1 <= arr[i] <= 3 * 10^4
 *
 *
 */

// @lc code=start
class Solution
{
public:
    int sumSubarrayMins(vector<int> &w)
    {
        int n = w.size();
        vector<int> l(n), r(n);
        stack<int> stk;

        for (int i = 0; i < n; i++)
        {
            while (stk.size() && w[stk.top()] > w[i])
                stk.pop();
            if (stk.empty())
                l[i] = -1;
            else
                l[i] = stk.top();
            stk.push(i);
        }

        stk = stack<int>();
        for (int i = n - 1; i >= 0; i--)
        {
            while (stk.size() && w[stk.top()] >= w[i])
                stk.pop();
            if (stk.empty())
                r[i] = n;
            else
                r[i] = stk.top();
            stk.push(i);
        }

        const int MOD = 1e9 + 7;
        int res = 0;
        for (int i = 0; i < n; i++)
            res = (res + (long long)w[i] * (i - l[i]) * (r[i] - i)) % MOD;
        return res;
    }
};

// @lc code=end
