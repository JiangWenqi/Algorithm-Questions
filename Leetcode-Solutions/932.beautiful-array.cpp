// @before-stub-for-debug-begin
#include <iostream>
#include <string>
#include <vector>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=932 lang=cpp
 *
 * [932] Beautiful Array
 *
 * https://leetcode.com/problems/beautiful-array/description/
 *
 * algorithms
 * Medium (64.85%)
 * Likes:    826
 * Dislikes: 1228
 * Total Accepted:    36.3K
 * Total Submissions: 56K
 * Testcase Example:  '4'
 *
 * An array nums of length n is beautiful if:
 *
 *
 * nums is a permutation of the integers in the range [1, n].
 * For every 0 <= i < j < n, there is no index k with i < k < j where 2 *
 * nums[k] == nums[i] + nums[j].
 *
 *
 * Given the integer n, return any beautiful array nums of length n. There will
 * be at least one valid answer for the given n.
 *
 *
 * Example 1:
 * Input: n = 4
 * Output: [2,1,4,3]
 * Example 2:
 * Input: n = 5
 * Output: [3,1,2,5,4]
 *
 *
 * Constraints:
 *
 *
 * 1 <= n <= 1000
 *
 *
 */

// @lc code=start
class Solution {
 public:
  vector<int> beautifulArray(int n) {
    if (n == 1) return {1};
    vector<int> left = beautifulArray((n + 1) / 2),
                right = beautifulArray(n / 2);
    vector<int> res;
    for (int &x : left) res.push_back(2 * x - 1);
    for (int &y : right) res.push_back(2 * y);
    return res;
  }

  
};
// @lc code=end
