#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

/*
 * @lc app=leetcode id=1695 lang=cpp
 *
 * [1695] Maximum Erasure Value
 *
 * https://leetcode.com/problems/maximum-erasure-value/description/
 *
 * algorithms
 * Medium (52.49%)
 * Likes:    1617
 * Dislikes: 26
 * Total Accepted:    70.3K
 * Total Submissions: 124.4K
 * Testcase Example:  '[4,2,4,5,6]'
 *
 * You are given an array of positive integers nums and want to erase a
 * subarray containing unique elements. The score you get by erasing the
 * subarray is equal to the sum of its elements.
 *
 * Return the maximum score you can get by erasing exactly one subarray.
 *
 * An array b is called to be a subarray of a if it forms a contiguous
 * subsequence of a, that is, if it is equal to a[l],a[l+1],...,a[r] for some
 * (l,r).
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [4,2,4,5,6]
 * Output: 17
 * Explanation: The optimal subarray here is [2,4,5,6].
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [5,2,1,2,5,2,1,2,5]
 * Output: 8
 * Explanation: The optimal subarray here is [5,2,1] or [1,2,5].
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 10^5
 * 1 <= nums[i] <= 10^4
 *
 *
 */

// @lc code=start
class Solution {
public:
  int maximumUniqueSubarray(vector<int> &nums) {
    int res = 0, n = nums.size(), sum = 0;
    unordered_set<int> s;
    for (int i = 0, j = 0; i < n; i++) {
      while (s.count(nums[i]) > 0) {
        s.erase(nums[j]);
        sum -= nums[j];
        j++;
      }
      sum += nums[i];
      s.insert(nums[i]);
      res = max(res, sum);
    }
    return res;
  }
};
// @lc code=end
