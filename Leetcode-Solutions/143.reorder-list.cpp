// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem143.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=143 lang=cpp
 *
 * [143] Reorder List
 *
 * https://leetcode.com/problems/reorder-list/description/
 *
 * algorithms
 * Medium (49.99%)
 * Likes:    6931
 * Dislikes: 238
 * Total Accepted:    549.7K
 * Total Submissions: 1.1M
 * Testcase Example:  '[1,2,3,4]'
 *
 * You are given the head of a singly linked-list. The list can be represented
 * as:
 *
 *
 * L0 → L1 → … → Ln - 1 → Ln
 *
 *
 * Reorder the list to be on the following form:
 *
 *
 * L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
 *
 *
 * You may not modify the values in the list's nodes. Only nodes themselves may
 * be changed.
 *
 *
 * Example 1:
 *
 *
 * Input: head = [1,2,3,4]
 * Output: [1,4,2,3]
 *
 *
 * Example 2:
 *
 *
 * Input: head = [1,2,3,4,5]
 * Output: [1,5,2,4,3]
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the list is in the range [1, 5 * 10^4].
 * 1 <= Node.val <= 1000
 *
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
    ListNode* reverse(ListNode* node) {
        ListNode* prev = NULL, * curr = node, * nex;
        while (curr) {
            nex = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nex;
        }
        return prev;
    }
public:
    void reorderList(ListNode* head) {
        if (!head->next) return;
        // 1. split it to two list
        ListNode* prev = NULL, * slow = head, * fast = head;
        while (fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        prev->next = NULL;
        ListNode* headA = head;
        // reverse the second list;
        ListNode* headB = reverse(slow);
        // 2. combine two list
        ListNode* dummy = new ListNode(-1);
        prev = dummy;
        while (headA && headB) {
            prev->next = headA;
            prev = prev->next;
            prev->next = headB;
            prev = prev->next;
            headA = headA->next;
            headB = headB->next;
        }
        if (headA) prev->next = headA;
        if (headB) prev->next = headB;
        head = dummy->next;
    }
};
// @lc code=end

