// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem61.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=61 lang=cpp
 *
 * [61] Rotate List
 *
 * https://leetcode.com/problems/rotate-list/description/
 *
 * algorithms
 * Medium (35.49%)
 * Likes:    6102
 * Dislikes: 1303
 * Total Accepted:    617.4K
 * Total Submissions: 1.7M
 * Testcase Example:  '[1,2,3,4,5]\n2'
 *
 * Given the head of a linked list, rotate the list to the right by k
 * places.
 *
 *
 * Example 1:
 *
 *
 * Input: head = [1,2,3,4,5], k = 2
 * Output: [4,5,1,2,3]
 *
 *
 * Example 2:
 *
 *
 * Input: head = [0,1,2], k = 4
 * Output: [2,0,1]
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the list is in the range [0, 500].
 * -100 <= Node.val <= 100
 * 0 <= k <= 2 * 10^9
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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* prev = new ListNode(-1, head), * curr = head;
        int n = 0;
        while (curr) {
            n++;
            prev = curr;
            curr = curr->next;
        }
        if (n == 0) return NULL;
        int count = n - k % n;
        prev->next = head;
        curr = head;
        while (count) {
            count--;
            prev = curr;
            curr = curr->next;
        }
        prev->next = NULL;
        return curr;

    }
};
// @lc code=end

