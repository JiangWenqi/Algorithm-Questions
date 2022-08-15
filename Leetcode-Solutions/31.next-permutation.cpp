// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem31.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=31 lang=cpp
 *
 * [31] Next Permutation
 *
 * https://leetcode.com/problems/next-permutation/description/
 *
 * algorithms
 * Medium (36.81%)
 * Likes:    12310
 * Dislikes: 3681
 * Total Accepted:    885.4K
 * Total Submissions: 2.4M
 * Testcase Example:  '[1,2,3]'
 *
 * A permutation of an array of integers is an arrangement of its members into
 * a sequence or linear order.
 *
 *
 * For example, for arr = [1,2,3], the following are considered permutations of
 * arr: [1,2,3], [1,3,2], [3,1,2], [2,3,1].
 *
 *
 * The next permutation of an array of integers is the next lexicographically
 * greater permutation of its integer. More formally, if all the permutations
 * of the array are sorted in one container according to their lexicographical
 * order, then the next permutation of that array is the permutation that
 * follows it in the sorted container. If such arrangement is not possible, the
 * array must be rearranged as the lowest possible order (i.e., sorted in
 * ascending order).
 *
 *
 * For example, the next permutation of arr = [1,2,3] is [1,3,2].
 * Similarly, the next permutation of arr = [2,3,1] is [3,1,2].
 * While the next permutation of arr = [3,2,1] is [1,2,3] because [3,2,1] does
 * not have a lexicographical larger rearrangement.
 *
 *
 * Given an array of integers nums, find the next permutation of nums.
 *
 * The replacement must be in place and use only constant extra memory.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [1,2,3]
 * Output: [1,3,2]
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [3,2,1]
 * Output: [1,2,3]
 *
 *
 * Example 3:
 *
 *
 * Input: nums = [1,1,5]
 * Output: [1,5,1]
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 100
 * 0 <= nums[i] <= 100
 *
 *
 */

 // @lc code=start
class Solution {
public:
    // 2 3 5 4 1 -> 2 4 1 3 5
    void nextPermutation(vector<int>& nums) {
        int i = nums.size() - 1;
        // from right to left, find the first number smaller than its next, like 3 which is < 5
        while (i > 0 && nums[i - 1] >= nums[i]) i--;
        if (i == 0) {
            // if it is already the biggest one, like 5 4 3 2 1, just need reverse it to 1 2 3 4 5
            reverse(nums.begin(), nums.end());
        } else {
            int j = i;
            // from left(i) to right, find the smallest number witch is bigger than previous one, like 4
            while (j < nums.size() && nums[i - 1] < nums[j]) j++;
            // 2 3 5 4 1 -> 2 4 5 3 1
            swap(nums[i - 1], nums[j - 1]);
            // reverse the rest, 2 4 5 3 1 -> 2 4 1 3 5
            reverse(nums.begin() + i, nums.end());
        }
    }
};
// @lc code=end

