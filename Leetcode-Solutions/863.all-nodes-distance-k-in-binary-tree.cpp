// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <unordered_map>
#include "commoncppproblem863.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=863 lang=cpp
 *
 * [863] All Nodes Distance K in Binary Tree
 *
 * https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/description/
 *
 * algorithms
 * Medium (61.73%)
 * Likes:    6924
 * Dislikes: 134
 * Total Accepted:    256.2K
 * Total Submissions: 415.1K
 * Testcase Example:  '[3,5,1,6,2,0,8,null,null,7,4]\n5\n2'
 *
 * Given the root of a binary tree, the value of a target node target, and an
 * integer k, return an array of the values of all nodes that have a distance k
 * from the target node.
 *
 * You can return the answer in any order.
 *
 *
 * Example 1:
 *
 *
 * Input: root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, k = 2
 * Output: [7,4,1]
 * Explanation: The nodes that are a distance 2 from the target node (with
 * value 5) have values 7, 4, and 1.
 *
 *
 * Example 2:
 *
 *
 * Input: root = [1], target = 1, k = 3
 * Output: []
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the tree is in the range [1, 500].
 * 0 <= Node.val <= 500
 * All the values Node.val are unique.
 * target is the value of one of the nodes in the tree.
 * 0 <= k <= 1000
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
  *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  * };
  */
class Solution {
private:
    unordered_map<TreeNode*, vector<TreeNode*>> g;
    vector<int> res;
    // build graph by dfs
    void dfs(TreeNode* node) {
        if (node->left) {
            g[node].push_back(node->left);
            g[node->left].push_back(node);
            dfs(node->left);
        }
        if (node->right) {
            g[node].push_back(node->right);
            g[node->right].push_back(node);
            dfs(node->right);
        }
    }
    // deep search k 
    void dfs(TreeNode* prev, TreeNode* curr, int k) {
        if (k == 0) {
            res.push_back(curr->val);
        } else {
            for (auto& node : g[curr]) {
                if (node != prev) {
                    dfs(curr, node, k - 1);
                }
            }
        }

    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        dfs(root);
        dfs(NULL, target, k);
        return res;
    }
};
// @lc code=end

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

string getShortestUniqueSubstring(const vector<char>& arr, const string& str) {
    unordered_map<char, int> hs, ht;
    for (auto& c : arr) ht[c]++;
    int cnt = 0;
    string res;
    for (int i = 0, j = 0; i < str.size(); i++) {
        hs[str[i]] ++;
        if (hs[str[i]] <= ht[str[i]]) cnt++;
        while (hs[str[j]] > ht[str[j]]) hs[str[j++]]--;
        if (cnt == arr.size()) {
            if (res.empty() || i - j + 1 < res.size())
                res = str.substr(j, i - j + 1);
        }
    }
    return res;
}

int main() {
    return 0;
}