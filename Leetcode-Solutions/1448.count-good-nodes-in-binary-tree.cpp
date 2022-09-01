/*
 * @lc app=leetcode id=1448 lang=cpp
 *
 * [1448] Count Good Nodes in Binary Tree
 *
 * https://leetcode.com/problems/count-good-nodes-in-binary-tree/description/
 *
 * algorithms
 * Medium (73.80%)
 * Likes:    3383
 * Dislikes: 99
 * Total Accepted:    226.2K
 * Total Submissions: 306.6K
 * Testcase Example:  '[3,1,4,3,null,1,5]'
 *
 * Given a binary tree root, a node X in the tree is named good if in the path
 * from root to X there are no nodes with a value greater than X.
 *
 * Return the number of good nodes in the binary tree.
 *
 *
 * Example 1:
 *
 *
 *
 *
 * Input: root = [3,1,4,3,null,1,5]
 * Output: 4
 * Explanation: Nodes in blue are good.
 * Root Node (3) is always a good node.
 * Node 4 -> (3,4) is the maximum value in the path starting from the root.
 * Node 5 -> (3,4,5) is the maximum value in the path
 * Node 3 -> (3,1,3) is the maximum value in the path.
 *
 * Example 2:
 *
 *
 *
 *
 * Input: root = [3,3,null,4,2]
 * Output: 3
 * Explanation: Node 2 -> (3, 3, 2) is not good, because "3" is higher than
 * it.
 *
 * Example 3:
 *
 *
 * Input: root = [1]
 * Output: 1
 * Explanation: Root is considered as good.
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the binary tree is in the range [1, 10^5].
 * Each node's value is between [-10^4, 10^4].
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
    int res = 0;
    void dfs(TreeNode* node, int mx) {
        if (node == NULL) return;
        if (node->val >= mx) {
            res++;
            mx = node->val;
        }
        dfs(node->left, mx);
        dfs(node->right, mx);
    }
public:
    int goodNodes(TreeNode* root) {
        dfs(root, root->val);
        return res;
    }
};
// @lc code=end

