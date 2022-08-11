// @before-stub-for-debug-begin
#include <string>
#include <vector>

#include "commoncppproblem673.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=673 lang=cpp
 *
 * [673] Number of Longest Increasing Subsequence
 *
 * https://leetcode.com/problems/number-of-longest-increasing-subsequence/description/
 *
 * algorithms
 * Medium (41.33%)
 * Likes:    3721
 * Dislikes: 175
 * Total Accepted:    117K
 * Total Submissions: 283K
 * Testcase Example:  '[1,3,5,4,7]'
 *
 * Given an integer array nums, return the number of longest increasing
 * subsequences.
 *
 * Notice that the sequence has to be strictly increasing.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [1,3,5,4,7]
 * Output: 2
 * Explanation: The two longest increasing subsequences are [1, 3, 4, 7] and
 * [1, 3, 5, 7].
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [2,2,2,2,2]
 * Output: 5
 * Explanation: The length of the longest increasing subsequence is 1, and
 * there are 5 increasing subsequences of length 1, so output 5.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 2000
 * -10^6 <= nums[i] <= 10^6
 *
 *
 */

 // @lc code=start
class Solution {
public:
  int findNumberOfLIS(vector<int>& nums) {
    int n = nums.size();
    vector<int> f(n), g(n);

    int maxl = 0, cnt = 0;
    for (int i = 0; i < n; i++) {
      f[i] = g[i] = 1;
      for (int j = 0; j < i; j++)
        if (nums[j] < nums[i]) {
          if (f[i] < f[j] + 1)
            f[i] = f[j] + 1, g[i] = g[j];
          else if (f[i] == f[j] + 1)
            g[i] += g[j];
        }
      if (maxl < f[i])
        maxl = f[i], cnt = g[i];
      else if (maxl == f[i])
        cnt += g[i];
    }
    return cnt;
  }
};
// @lc code=end
