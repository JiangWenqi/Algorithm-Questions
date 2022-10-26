// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem523.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=523 lang=cpp
 *
 * [523] Continuous Subarray Sum
 *
 * https://leetcode.com/problems/continuous-subarray-sum/description/
 *
 * algorithms
 * Medium (27.68%)
 * Likes:    3291
 * Dislikes: 347
 * Total Accepted:    339.6K
 * Total Submissions: 1.2M
 * Testcase Example:  '[23,2,4,6,7]\n6'
 *
 * Given an integer array nums and an integer k, return true if nums has a
 * continuous subarray of size at least two whose elements sum up to a multiple
 * of k, or false otherwise.
 *
 * An integer x is a multiple of k if there exists an integer n such that x = n
 * * k. 0 is always a multiple of k.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [23,2,4,6,7], k = 6
 * Output: true
 * Explanation: [2, 4] is a continuous subarray of size 2 whose elements sum up
 * to 6.
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [23,2,6,4,7], k = 6
 * Output: true
 * Explanation: [23, 2, 6, 4, 7] is an continuous subarray of size 5 whose
 * elements sum up to 42.
 * 42 is a multiple of 6 because 42 = 7 * 6 and 7 is an integer.
 *
 *
 * Example 3:
 *
 *
 * Input: nums = [23,2,6,4,7], k = 13
 * Output: false
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 10^5
 * 0 <= nums[i] <= 10^9
 * 0 <= sum(nums[i]) <= 2^31 - 1
 * 1 <= k <= 2^31 - 1
 *
 *
 */

// @lc code=start
class Solution
{
public:
    bool checkSubarraySum(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<int> ps(n + 1, 0);
        unordered_set<int> st;
        for (int i = 1; i <= n; i++)
        {
            ps[i] = ps[i - 1] + nums[i - 1];
            if (i >= 2)
            {
                // same remainder
                st.insert(ps[i - 2] % k);
                if (st.count(ps[i] % k))
                    return true;
            }
        }
        return false;
    }
};
// @lc code=end
