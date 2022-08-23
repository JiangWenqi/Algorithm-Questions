// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem234.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=234 lang=cpp
 *
 * [234] Palindrome Linked List
 *
 * https://leetcode.com/problems/palindrome-linked-list/description/
 *
 * algorithms
 * Easy (47.97%)
 * Likes:    10858
 * Dislikes: 630
 * Total Accepted:    1.1M
 * Total Submissions: 2.3M
 * Testcase Example:  '[1,2,2,1]'
 *
 * Given the head of a singly linked list, return true if it is a
 * palindrome.
 *
 *
 * Example 1:
 *
 *
 * Input: head = [1,2,2,1]
 * Output: true
 *
 *
 * Example 2:
 *
 *
 * Input: head = [1,2]
 * Output: false
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the list is in the range [1, 10^5].
 * 0 <= Node.val <= 9
 *
 *
 *
 * Follow up: Could you do it in O(n) time and O(1) space?
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
    ListNode* reverse(ListNode* head) {
        ListNode* prev = NULL, * curr = head, * nex = NULL;
        while (curr) {
            nex = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nex;
        }
        return prev;
    }
public:
    bool isPalindrome(ListNode* head) {
        ListNode* dummy = new ListNode(-1, head);
        ListNode* slow = dummy, * fast = dummy;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* tail = reverse(slow->next);
        while (tail) {
            if (head->val != tail->val) return false;
            head = head->next, tail = tail->next;
        }
        return true;
    }
};
// @lc code=end

