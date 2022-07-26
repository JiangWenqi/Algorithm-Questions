// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem179.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=179 lang=cpp
 *
 * [179] Largest Number
 *
 * https://leetcode.com/problems/largest-number/description/
 *
 * algorithms
 * Medium (33.42%)
 * Likes:    5315
 * Dislikes: 442
 * Total Accepted:    334.4K
 * Total Submissions: 1M
 * Testcase Example:  '[10,2]'
 *
 * Given a list of non-negative integers nums, arrange them such that they form
 * the largest number and return it.
 *
 * Since the result may be very large, so you need to return a string instead
 * of an integer.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [10,2]
 * Output: "210"
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [3,30,34,5,9]
 * Output: "9534330"
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 100
 * 0 <= nums[i] <= 10^9
 *
 *
 */

 // @lc code=start
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [&](int& a, int& b) {
            string as = to_string(a), bs = to_string(b);
            return as + bs > bs + as;
            });
        if (nums[0] == 0) return "0";
        string res = "";
        for (int& num : nums) {
            res += to_string(num);
        }
        return res;
    }
};
// @lc code=end

