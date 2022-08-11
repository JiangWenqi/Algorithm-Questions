// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem462.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=462 lang=cpp
 *
 * [462] Minimum Moves to Equal Array Elements II
 *
 * https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/description/
 *
 * algorithms
 * Medium (57.28%)
 * Likes:    2103
 * Dislikes: 90
 * Total Accepted:    119.3K
 * Total Submissions: 202.3K
 * Testcase Example:  '[1,2,3]'
 *
 * Given an integer array nums of size n, return the minimum number of moves
 * required to make all array elements equal.
 *
 * In one move, you can increment or decrement an element of the array by 1.
 *
 * Test cases are designed so that the answer will fit in a 32-bit integer.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [1,2,3]
 * Output: 2
 * Explanation:
 * Only two moves are needed (remember each move increments or decrements one
 * element):
 * [1,2,3]  =>  [2,2,3]  =>  [2,2,2]
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [1,10,2,9]
 * Output: 16
 *
 *
 *
 * Constraints:
 *
 *
 * n == nums.length
 * 1 <= nums.length <= 10^5
 * -10^9 <= nums[i] <= 10^9
 *
 *
 */

 // @lc code=start
class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size(), res = 0;
        sort(nums.begin(), nums.end());
        for (int& num : nums) {
            res += abs(num - nums[n / 2]);
        }
        return res;

    }
};
// @lc code=end

