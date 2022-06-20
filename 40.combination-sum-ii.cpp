// @before-stub-for-debug-begin
#include <string>
#include <vector>

#include "commoncppproblem40.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=40 lang=cpp
 *
 * [40] Combination Sum II
 *
 * https://leetcode.com/problems/combination-sum-ii/description/
 *
 * algorithms
 * Medium (52.63%)
 * Likes:    5688
 * Dislikes: 147
 * Total Accepted:    577.9K
 * Total Submissions: 1.1M
 * Testcase Example:  '[10,1,2,7,6,1,5]\n8'
 *
 * Given a collection of candidate numbers (candidates) and a target number
 * (target), find all unique combinations in candidates where the candidate
 * numbers sum to target.
 *
 * Each number in candidates may only be used once in the combination.
 *
 * Note: The solution set must not contain duplicate combinations.
 *
 *
 * Example 1:
 *
 *
 * Input: candidates = [10,1,2,7,6,1,5], target = 8
 * Output:
 * [
 * [1,1,6],
 * [1,2,5],
 * [1,7],
 * [2,6]
 * ]
 *
 *
 * Example 2:
 *
 *
 * Input: candidates = [2,5,2,1,2], target = 5
 * Output:
 * [
 * [1,2,2],
 * [5]
 * ]
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= candidates.length <= 100
 * 1 <= candidates[i] <= 50
 * 1 <= target <= 30
 *
 *
 */

// @lc code=start
class Solution {
 private:
  vector<vector<int>> res;
  vector<int> path;
  void dfs(int start, vector<int>& candidates, int target) {
    if (target == 0) {
      res.push_back(path);

    } else if (target > 0) {
      for (int i = start; i < candidates.size(); i++) {
        if (i > start && candidates[i] == candidates[i - 1]) continue;
        path.push_back(candidates[i]);
        dfs(i + 1, candidates, target - candidates[i]);
        path.pop_back();
      }
    }
  }

 public:
  vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    sort(candidates.begin(), candidates.end());
    dfs(0, candidates, target);
    return res;
  }
};
// @lc code=end
