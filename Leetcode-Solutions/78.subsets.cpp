// @before-stub-for-debug-begin
#include <string>
#include <vector>

#include "commoncppproblem78.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=78 lang=cpp
 *
 * [78] Subsets
 *
 * https://leetcode.com/problems/subsets/description/
 *
 * algorithms
 * Medium (71.92%)
 * Likes:    10285
 * Dislikes: 157
 * Total Accepted:    1.1M
 * Total Submissions: 1.6M
 * Testcase Example:  '[1,2,3]'
 *
 * Given an integer array nums of unique elements, return all possible subsets
 * (the power set).
 *
 * The solution set must not contain duplicate subsets. Return the solution in
 * any order.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [1,2,3]
 * Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [0]
 * Output: [[],[0]]
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 10
 * -10 <= nums[i] <= 10
 * All the numbers of nums are unique.
 *
 *
 */

 // @lc code=start
class Solution {
private:
  vector<int> path;
  vector<vector<int>> res;

  void backtracking(int start, int length, vector<int>& nums) {
    if (start == length) {
      res.push_back(path);
      return;
    }
    for (int i = start; i < nums.size(); i++) {
      path.push_back(nums[i]);
      backtracking(i + 1, length, nums);
      path.pop_back();
    }
  }

public:
  vector<vector<int>> subsets(vector<int>& nums) {
    for (int length = 0; length <= nums.size(); length++)
      backtracking(0, length, nums);
    return res;
  }
};
// @lc code=end
