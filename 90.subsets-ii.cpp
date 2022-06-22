// @before-stub-for-debug-begin
#include <string>
#include <vector>

#include "commoncppproblem90.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=90 lang=cpp
 *
 * [90] Subsets II
 *
 * https://leetcode.com/problems/subsets-ii/description/
 *
 * algorithms
 * Medium (53.86%)
 * Likes:    5470
 * Dislikes: 163
 * Total Accepted:    528.5K
 * Total Submissions: 981.3K
 * Testcase Example:  '[1,2,2]'
 *
 * Given an integer array nums that may contain duplicates, return all possible
 * subsets (the power set).
 *
 * The solution set must not contain duplicate subsets. Return the solution in
 * any order.
 *
 *
 * Example 1:
 * Input: nums = [1,2,2]
 * Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]
 * Example 2:
 * Input: nums = [0]
 * Output: [[],[0]]
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 10
 * -10 <= nums[i] <= 10
 *
 *
 */

// @lc code=start
class Solution {
 private:
  vector<vector<int>> res;
  vector<int> path;

  void dfs(int idx, int len, vector<int>& nums) {
    if (idx == len) {
      res.push_back(path);
      return;
    }
    for (int i = idx; i < nums.size(); i++) {
      if (i > idx && nums[i] == nums[i - 1]) continue;
      path.push_back(nums[i]);
      dfs(i + 1, len, nums);
      path.pop_back();
    }
  }

 public:
  vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    for (int i = 0; i <= nums.size(); i++) {
      dfs(0, i, nums);
    }
    return res;
  }
};
// @lc code=end
