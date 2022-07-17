// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem525.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=525 lang=cpp
 *
 * [525] Contiguous Array
 *
 * https://leetcode.com/problems/contiguous-array/description/
 *
 * algorithms
 * Medium (46.56%)
 * Likes:    5519
 * Dislikes: 234
 * Total Accepted:    268.8K
 * Total Submissions: 577.4K
 * Testcase Example:  '[0,1]'
 *
 * Given a binary array nums, return the maximum length of a contiguous
 * subarray with an equal number of 0 and 1.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [0,1]
 * Output: 2
 * Explanation: [0, 1] is the longest contiguous subarray with an equal number
 * of 0 and 1.
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [0,1,0]
 * Output: 2
 * Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal
 * number of 0 and 1.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 10^5
 * nums[i] is either 0 or 1.
 *
 *
 */

 // @lc code=start
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size(), sum = 0, res = 0;
        vector<int> prefixSums;
        unordered_map<int, int> prefixSumIdx;
        prefixSumIdx[0] = -1;
        for (int i = 0; i < n; i++) {
            sum += nums[i] == 1 ? 1 : -1;
            if (prefixSumIdx.find(sum) == prefixSumIdx.end()) {
                prefixSumIdx[sum] = i;
            } else {
                res = max(res, i - prefixSumIdx[sum]);
            }
        }
        return res;
    }
};
// @lc code=end

