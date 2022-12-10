/*
 * @lc app=leetcode id=1339 lang=cpp
 *
 * [1339] Maximum Product of Splitted Binary Tree
 *
 * https://leetcode.com/problems/maximum-product-of-splitted-binary-tree/description/
 *
 * algorithms
 * Medium (47.65%)
 * Likes:    2545
 * Dislikes: 94
 * Total Accepted:    101.8K
 * Total Submissions: 213.8K
 * Testcase Example:  '[1,2,3,4,5,6]'
 *
 * Given the root of a binary tree, split the binary tree into two subtrees by
 * removing one edge such that the product of the sums of the subtrees is
 * maximized.
 *
 * Return the maximum product of the sums of the two subtrees. Since the answer
 * may be too large, return it modulo 10^9 + 7.
 *
 * Note that you need to maximize the answer before taking the mod and not
 * after taking it.
 *
 *
 * Example 1:
 *
 *
 * Input: root = [1,2,3,4,5,6]
 * Output: 110
 * Explanation: Remove the red edge and get 2 binary trees with sum 11 and 10.
 * Their product is 110 (11*10)
 *
 *
 * Example 2:
 *
 *
 * Input: root = [1,null,2,3,4,null,null,5,6]
 * Output: 90
 * Explanation: Remove the red edge and get 2 binary trees with sum 15 and
 * 6.Their product is 90 (15*6)
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the tree is in the range [2, 5 * 10^4].
 * 1 <= Node.val <= 10^4
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
class Solution
{
private:
    long long res = INT_MIN, total = 0, MOD = 1e9 + 7;
    void getTotal(TreeNode *node)
    {
        if (!node)
            return;
        total += node->val;
        getTotal(node->left);
        getTotal(node->right);
    }
    long long getSumOf(TreeNode *node)
    {
        if (!node)
            return 0;
        long long left = getSumOf(node->left), right = getSumOf(node->right);
        res = max({res, (total - left) * left, (total - right) * right});
        return left + right + node->val;
    }

public:
    int maxProduct(TreeNode *root)
    {
        getTotal(root);
        getSumOf(root);
        return res % MOD;
    }
};
// @lc code=end
