// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem148.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=148 lang=cpp
 *
 * [148] Sort List
 *
 * https://leetcode.com/problems/sort-list/description/
 *
 * algorithms
 * Medium (53.39%)
 * Likes:    7989
 * Dislikes: 250
 * Total Accepted:    536.7K
 * Total Submissions: 1M
 * Testcase Example:  '[4,2,1,3]'
 *
 * Given the head of a linked list, return the list after sorting it in
 * ascending order.
 *
 *
 * Example 1:
 *
 *
 * Input: head = [4,2,1,3]
 * Output: [1,2,3,4]
 *
 *
 * Example 2:
 *
 *
 * Input: head = [-1,5,3,4,0]
 * Output: [-1,0,3,4,5]
 *
 *
 * Example 3:
 *
 *
 * Input: head = []
 * Output: []
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the list is in the range [0, 5 * 10^4].
 * -10^5 <= Node.val <= 10^5
 *
 *
 *
 * Follow up: Can you sort the linked list in O(n logn) time and O(1) memory
 * (i.e. constant space)?
 *
 */

 // @lc code=start
 /**
  * Definition for singly-linked list.
  * struct ListNode {
  *     int val;
  *     ListNode *next;
  *     ListNode() : val(0), next(nullptr) {}
  *     ListNode(int x) : val(x), next(nullptr) {}
  *     ListNode(int x, ListNode *next) : val(x), next(next) {}
  * };
  */
class Solution {
private:
    ListNode* merge(ListNode* node1, ListNode* node2) {
        ListNode* dummy = new ListNode(-1), * prev = dummy;
        while (node1 && node2) {
            if (node1->val < node2->val) {
                prev->next = node1;
                node1 = node1->next;
            } else {
                prev->next = node2;
                node2 = node2->next;
            }
            prev = prev->next;
        }
        if (node1) prev->next = node1;
        if (node2) prev->next = node2;
        return dummy->next;
    }
public:
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* prev = NULL, * slow = head, * fast = head;
        while (fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        prev->next = NULL;
        ListNode* l = sortList(head), * r = sortList(slow);
        return merge(l, r);
    }
};
// @lc code=end

