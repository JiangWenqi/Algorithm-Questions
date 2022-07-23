// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem86.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=86 lang=cpp
 *
 * [86] Partition List
 *
 * https://leetcode.com/problems/partition-list/description/
 *
 * algorithms
 * Medium (48.57%)
 * Likes:    4086
 * Dislikes: 535
 * Total Accepted:    372K
 * Total Submissions: 752.9K
 * Testcase Example:  '[1,4,3,2,5,2]\n3'
 *
 * Given the head of a linked list and a value x, partition it such that all
 * nodes less than x come before nodes greater than or equal to x.
 *
 * You should preserve the original relative order of the nodes in each of the
 * two partitions.
 *
 *
 * Example 1:
 *
 *
 * Input: head = [1,4,3,2,5,2], x = 3
 * Output: [1,2,2,4,3,5]
 *
 *
 * Example 2:
 *
 *
 * Input: head = [2,1], x = 2
 * Output: [1,2]
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the list is in the range [0, 200].
 * -100 <= Node.val <= 100
 * -200 <= x <= 200
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
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* lessDummy = new ListNode(-1), * lessPrev = lessDummy;
        ListNode* greatDummy = new ListNode(-1), * greatPrev = greatDummy;

        while (head) {
            if (head->val < x)
                lessPrev = lessPrev->next = head;
            else
                greatPrev = greatPrev->next = head;
            head = head->next;
        }
        lessPrev->next = greatDummy->next;
        greatPrev->next = NULL;

        return lessDummy->next;
    }
};
// @lc code=end

