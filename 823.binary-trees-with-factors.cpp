// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem823.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=823 lang=cpp
 *
 * [823] Binary Trees With Factors
 *
 * https://leetcode.com/problems/binary-trees-with-factors/description/
 *
 * algorithms
 * Medium (43.71%)
 * Likes:    1459
 * Dislikes: 140
 * Total Accepted:    53.3K
 * Total Submissions: 113.7K
 * Testcase Example:  '[2,4]'
 *
 * Given an array of unique integers, arr, where each integer arr[i] is
 * strictly greater than 1.
 *
 * We make a binary tree using these integers, and each number may be used for
 * any number of times. Each non-leaf node's value should be equal to the
 * product of the values of its children.
 *
 * Return the number of binary trees we can make. The answer may be too large
 * so return the answer modulo 10^9 + 7.
 *
 *
 * Example 1:
 *
 *
 * Input: arr = [2,4]
 * Output: 3
 * Explanation: We can make these trees: [2], [4], [4, 2, 2]
 *
 * Example 2:
 *
 *
 * Input: arr = [2,4,5,10]
 * Output: 7
 * Explanation: We can make these trees: [2], [4], [5], [10], [4, 2, 2], [10,
 * 2, 5], [10, 5, 2].
 *
 *
 * Constraints:
 *
 *
 * 1 <= arr.length <= 1000
 * 2 <= arr[i] <= 10^9
 * All the values of arr are unique.
 *
 *
 */

 // @lc code=start
class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int n = arr.size(), res = 0, MOD = 1e9 + 7;
        vector<int> f(n, 1);
        unordered_map<int, int> idx;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (arr[i] % arr[j] == 0 && idx.count(arr[i] / arr[j])) {
                    int k = idx[arr[i] / arr[j]];
                    f[i] = (f[i] + (long long)f[j] * f[k]) % MOD;
                }
            }
            idx[arr[i]] = i;
            res = (res + f[i]) % MOD;
        }
        return res;
    }
};
// @lc code=end

