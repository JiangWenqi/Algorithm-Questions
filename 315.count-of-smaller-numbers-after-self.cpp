// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem315.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=315 lang=cpp
 *
 * [315] Count of Smaller Numbers After Self
 *
 * https://leetcode.com/problems/count-of-smaller-numbers-after-self/description/
 *
 * algorithms
 * Hard (42.03%)
 * Likes:    6384
 * Dislikes: 178
 * Total Accepted:    244.6K
 * Total Submissions: 578.7K
 * Testcase Example:  '[5,2,6,1]'
 *
 * You are given an integer array nums and you have to return a new counts
 * array. The counts array has the property where counts[i] is the number of
 * smaller elements to the right of nums[i].
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [5,2,6,1]
 * Output: [2,1,1,0]
 * Explanation:
 * To the right of 5 there are 2 smaller elements (2 and 1).
 * To the right of 2 there is only 1 smaller element (1).
 * To the right of 6 there is 1 smaller element (1).
 * To the right of 1 there is 0 smaller element.
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [-1]
 * Output: [0]
 *
 *
 * Example 3:
 *
 *
 * Input: nums = [-1,-1]
 * Output: [0,0]
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 10^5
 * -10^4 <= nums[i] <= 10^4
 *
 *
 */

 // @lc code=start
const int N = 20001;
class Solution {

private:
    int tr[N + 1] = { 0 };
    int lowbit(int x) {
        return x & -x;
    }

    int query(int x) {
        int res = 0;
        for (int i = x; i; i -= lowbit(i)) res += tr[i];
        return res;
    }

    void add(int x, int v) {
        for (int i = x; i <= N; i += lowbit(i)) tr[i] += v;
    }

public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> res(nums.size());
        for (int i = nums.size() - 1; i >= 0; i--) {
            int x = nums[i] + 10001;
            res[i] = query(x - 1);
            add(x, 1);
        }
        return res;
    }
};
// @lc code=end

