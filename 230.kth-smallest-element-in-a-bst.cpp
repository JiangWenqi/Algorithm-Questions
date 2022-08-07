// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem230.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=230 lang=cpp
 *
 * [230] Kth Smallest Element in a BST
 *
 * https://leetcode.com/problems/kth-smallest-element-in-a-bst/description/
 *
 * algorithms
 * Medium (68.58%)
 * Likes:    7847
 * Dislikes: 137
 * Total Accepted:    883.4K
 * Total Submissions: 1.3M
 * Testcase Example:  '[3,1,4,null,2]\n1'
 *
 * Given the root of a binary search tree, and an integer k, return the k^th
 * smallest value (1-indexed) of all the values of the nodes in the tree.
 *
 *
 * Example 1:
 *
 *
 * Input: root = [3,1,4,null,2], k = 1
 * Output: 1
 *
 *
 * Example 2:
 *
 *
 * Input: root = [5,3,6,2,4,null,null,1], k = 3
 * Output: 3
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the tree is n.
 * 1 <= k <= n <= 10^4
 * 0 <= Node.val <= 10^4
 *
 *
 *
 * Follow up: If the BST is modified often (i.e., we can do insert and delete
 * operations) and you need to find the kth smallest frequently, how would you
 * optimize?
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
    // return the node number whose val smaller than target?
    int get(TreeNode* root, int target) {
        int num = 0;
        if (root) {
            if (root->val <= target) {
                num += 1;
                num += get(root->left, target);
                num += get(root->right, target);
            } else {
                num += get(root->left, target);
            }
        }
        return num;
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        int l = 0, r = 1e4;
        while (l < r) {
            int mid = l + r >> 1;
            if (get(root, mid) >= k) r = mid;
            else l = mid + 1;
        }
        return l;
    }
};
// @lc code=end

