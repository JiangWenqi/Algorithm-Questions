// @before-stub-for-debug-begin
#include <string>
#include <vector>

#include "commoncppproblem47.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=47 lang=cpp
 *
 * [47] Permutations II
 *
 * https://leetcode.com/problems/permutations-ii/description/
 *
 * algorithms
 * Medium (55.69%)
 * Likes:    5849
 * Dislikes: 101
 * Total Accepted:    663.8K
 * Total Submissions: 1.2M
 * Testcase Example:  '[1,1,2]'
 *
 * Given a collection of numbers, nums, that might contain duplicates, return
 * all possible unique permutations in any order.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [1,1,2]
 * Output:
 * [[1,1,2],
 * ⁠[1,2,1],
 * ⁠[2,1,1]]
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [1,2,3]
 * Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 8
 * -10 <= nums[i] <= 10
 *
 *
 */

// @lc code=start
class Solution {
 private:
  vector<vector<int>> res;
  vector<int> path;
  vector<bool> visited;
  void dfs(int start, vector<int>& nums) {
    if (start == nums.size()) {
      res.push_back(path);
      return;
    }
    for (int i = 0; i < nums.size(); i++) {
      if (!visited[i]) {
        // same with the previous number and the previous one wasn't visited
        if (i && nums[i] == nums[i - 1] && !visited[i - 1]) continue;
        visited[i] = true;
        path[start] = nums[i];
        dfs(start + 1, nums);
        visited[i] = false;
      }
    }
  }

 public:
  vector<vector<int>> permuteUnique(vector<int>& nums) {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    path.resize(n);
    visited.resize(n, false);
    dfs(0, nums);
    return res;
  }
};
// @lc code=end
