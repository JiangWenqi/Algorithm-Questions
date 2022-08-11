// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem662.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=662 lang=cpp
 *
 * [662] Maximum Width of Binary Tree
 *
 * https://leetcode.com/problems/maximum-width-of-binary-tree/description/
 *
 * algorithms
 * Medium (40.38%)
 * Likes:    5205
 * Dislikes: 766
 * Total Accepted:    205.6K
 * Total Submissions: 509K
 * Testcase Example:  '[1,3,2,5,3,null,9]'
 *
 * Given the root of a binary tree, return the maximum width of the given
 * tree.
 *
 * The maximum width of a tree is the maximum width among all levels.
 *
 * The width of one level is defined as the length between the end-nodes (the
 * leftmost and rightmost non-null nodes), where the null nodes between the
 * end-nodes that would be present in a complete binary tree extending down to
 * that level are also counted into the length calculation.
 *
 * It is guaranteed that the answer will in the range of a 32-bit signed
 * integer.
 *
 *
 * Example 1:
 *
 *
 * Input: root = [1,3,2,5,3,null,9]
 * Output: 4
 * Explanation: The maximum width exists in the third level with length 4
 * (5,3,null,9).
 *
 *
 * Example 2:
 *
 *
 * Input: root = [1,3,2,5,null,null,9,6,null,7]
 * Output: 7
 * Explanation: The maximum width exists in the fourth level with length 7
 * (6,null,null,null,null,null,7).
 *
 *
 * Example 3:
 *
 *
 * Input: root = [1,3,2,5]
 * Output: 2
 * Explanation: The maximum width exists in the second level with length 2
 * (3,2).
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the tree is in the range [1, 3000].
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
    int widthOfBinaryTree(TreeNode* root) {
        if (root == NULL) return 0;
        queue<pair<TreeNode*, int>> q;
        q.push({ root, 1 });
        int res = 0, l, r;
        while (!q.empty()) {
            int sz = q.size();
            l = q.front().second;
            for (int i = 0; i < sz; i++) {
                auto node = q.front().first;
                r = q.front().second;
                q.pop();
                int idx = r - l + 1;
                if (node->left) q.push({ node->left, 2ll * idx });
                if (node->right) q.push({ node->right, 2ll * idx + 1 });
            }
            res = max(res, r - l + 1);
        }
        return res;
    }
};
// @lc code=end

