// @before-stub-for-debug-begin
#include <queue>
#include <string>
#include <vector>

#include "commoncppproblem968.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=968 lang=cpp
 *
 * [968] Binary Tree Cameras
 *
 * https://leetcode.com/problems/binary-tree-cameras/description/
 *
 * algorithms
 * Hard (42.13%)
 * Likes:    3372
 * Dislikes: 38
 * Total Accepted:    80.1K
 * Total Submissions: 182.5K
 * Testcase Example:  '[0,0,null,0,0]'
 *
 * You are given the root of a binary tree. We install cameras on the tree
 * nodes where each camera at a node can monitor its parent, itself, and its
 * immediate children.
 *
 * Return the minimum number of cameras needed to monitor all nodes of the
 * tree.
 *
 *
 * Example 1:
 *
 *
 * Input: root = [0,0,null,0,0]
 * Output: 1
 * Explanation: One camera is enough to monitor all nodes if placed as shown.
 *
 *
 * Example 2:
 *
 *
 * Input: root = [0,0,null,0,null,0,null,null,0]
 * Output: 2
 * Explanation: At least two cameras are needed to monitor all nodes of the
 * tree. The above image shows one of the valid configurations of camera
 * placement.
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the tree is in the range [1, 1000].
 * Node.val == 0
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
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
 private:
  const int INF = 1e8;

  // https://www.acwing.com/activity/content/problem/content/4272/
  vector<int> dfs(TreeNode* root) {
    if (!root) return {0, 0, INF};
    auto l = dfs(root->left), r = dfs(root->right);
    return {
        min(l[1], l[2]) + min(r[1], r[2]),
        min(l[2] + min(r[1], r[2]), r[2] + min(l[1], l[2])),
        min(l[0], min(l[1], l[2])) + min(r[0], min(r[1], r[2])) + 1,
    };
  }

 public:
  int minCameraCover(TreeNode* root) {
    auto f = dfs(root);
    return min(f[1], f[2]);
  }
};
// @lc code=end
