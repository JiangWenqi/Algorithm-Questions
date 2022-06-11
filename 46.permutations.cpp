/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 *
 * https://leetcode.com/problems/permutations/description/
 *
 * algorithms
 * Medium (72.51%)
 * Likes:    10469
 * Dislikes: 189
 * Total Accepted:    1.2M
 * Total Submissions: 1.6M
 * Testcase Example:  '[1,2,3]'
 *
 * Given an array nums of distinct integers, return all the possible
 * permutations. You can return the answer in any order.
 *
 *
 * Example 1:
 * Input: nums = [1,2,3]
 * Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
 * Example 2:
 * Input: nums = [0,1]
 * Output: [[0,1],[1,0]]
 * Example 3:
 * Input: nums = [1]
 * Output: [[1]]
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 6
 * -10 <= nums[i] <= 10
 * All the integers of nums are unique.
 *
 *
 */

// @lc code=start
class Solution {
 private:
  vector<int> path;
  vector<bool> visited;
  vector<vector<int>> res;
  void dfs(int idx, vector<int> &nums) {
    if (idx == nums.size()) {
      res.push_back(path);
      return;
    }

    for (int i = 0; i < nums.size(); i++) {
      if (!visited[i]) {
        path[idx] = nums[i];
        visited[i] = true;
        dfs(idx + 1, nums);
        visited[i] = false;
      }
    }
  }

 public:
  vector<vector<int>> permute(vector<int> &nums) {
    int n = nums.size();
    path.resize(n);
    visited.resize(n);
    dfs(0, nums);
    return res;
  }
};
// @lc code=end
