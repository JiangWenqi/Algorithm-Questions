// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem437.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=437 lang=cpp
 *
 * [437] Path Sum III
 *
 * https://leetcode.com/problems/path-sum-iii/description/
 *
 * algorithms
 * Medium (49.55%)
 * Likes:    8152
 * Dislikes: 393
 * Total Accepted:    391.2K
 * Total Submissions: 789.5K
 * Testcase Example:  '[10,5,-3,3,2,null,11,3,-2,null,1]\n8'
 *
 * Given the root of a binary tree and an integer targetSum, return the number
 * of paths where the sum of the values along the path equals targetSum.
 *
 * The path does not need to start or end at the root or a leaf, but it must go
 * downwards (i.e., traveling only from parent nodes to child nodes).
 *
 *
 * Example 1:
 *
 *
 * Input: root = [10,5,-3,3,2,null,11,3,-2,null,1], targetSum = 8
 * Output: 3
 * Explanation: The paths that sum to 8 are shown.
 *
 *
 * Example 2:
 *
 *
 * Input: root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
 * Output: 3
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the tree is in the range [0, 1000].
 * -10^9 <= Node.val <= 10^9
 * -1000 <= targetSum <= 1000
 *
 *
 */

 // @lc code=start
 /**
  * Definition for a binary tree node.
  * struct TreeNode {
  *     int val;
  *     TreeNode *left;
  *     TreeNode *right;
  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  * };
  */
class Solution {
private:
    unordered_map<long, int> cnt;
    int res = 0;
    void dfs(TreeNode* node, int targetSum, long currentSum) {
        if (node == NULL) return;
        currentSum += node->val;
        if (cnt.count(currentSum - targetSum))
            res += cnt[currentSum - targetSum];
        cnt[currentSum]++;
        dfs(node->left, targetSum, currentSum);
        dfs(node->right, targetSum, currentSum);
        cnt[currentSum]--;
    }
public:
    int pathSum(TreeNode* root, int targetSum) {
        cnt[0] = 1;
        dfs(root, targetSum, 0);
        return res;
    }
};
// @lc code=end

