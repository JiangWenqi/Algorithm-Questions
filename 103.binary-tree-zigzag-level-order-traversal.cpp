// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem103.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=103 lang=cpp
 *
 * [103] Binary Tree Zigzag Level Order Traversal
 *
 * https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/description/
 *
 * algorithms
 * Medium (54.49%)
 * Likes:    6710
 * Dislikes: 190
 * Total Accepted:    771.5K
 * Total Submissions: 1.4M
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Given the root of a binary tree, return the zigzag level order traversal of
 * its nodes' values. (i.e., from left to right, then right to left for the
 * next level and alternate between).
 *
 *
 * Example 1:
 *
 *
 * Input: root = [3,9,20,null,null,15,7]
 * Output: [[3],[20,9],[15,7]]
 *
 *
 * Example 2:
 *
 *
 * Input: root = [1]
 * Output: [[1]]
 *
 *
 * Example 3:
 *
 *
 * Input: root = []
 * Output: []
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the tree is in the range [0, 2000].
 * -100 <= Node.val <= 100
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
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (root == NULL) return res;
        queue<TreeNode*> q;
        q.push(root);
        bool l2r = true;
        while (!q.empty()) {
            int sz = q.size();
            vector<int> lvl(sz, 0);
            if (l2r) {
                for (int i = 0; i < sz; i++) {
                    auto node = q.front();
                    q.pop();
                    lvl[i] = node->val;
                    if (node->left) q.push(node->left);
                    if (node->right) q.push(node->right);
                }
            } else {
                for (int i = 0; i < sz; i++) {
                    auto node = q.front();
                    q.pop();
                    lvl[sz - 1 - i] = node->val;
                    if (node->left) q.push(node->left);
                    if (node->right) q.push(node->right);
                }
            }
            l2r = !l2r;
            res.push_back(lvl);
        }
        return res;
    }
};
// @lc code=end

