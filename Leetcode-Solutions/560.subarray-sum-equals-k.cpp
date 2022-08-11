// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem560.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=560 lang=cpp
 *
 * [560] Subarray Sum Equals K
 *
 * https://leetcode.com/problems/subarray-sum-equals-k/description/
 *
 * algorithms
 * Medium (44.23%)
 * Likes:    14328
 * Dislikes: 443
 * Total Accepted:    822.9K
 * Total Submissions: 1.9M
 * Testcase Example:  '[1,1,1]\n2'
 *
 * Given an array of integers nums and an integer k, return the total number of
 * subarrays whose sum equals to k.
 *
 * A subarray is a contiguous non-empty sequence of elements within an
 * array.
 *
 *
 * Example 1:
 * Input: nums = [1,1,1], k = 2
 * Output: 2
 * Example 2:
 * Input: nums = [1,2,3], k = 3
 * Output: 2
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 2 * 10^4
 * -1000 <= nums[i] <= 1000
 * -10^7 <= k <= 10^7
 *
 *
 */

 // @lc code=start
class Solution {
public:
    /**
        int subarraySum(vector<int>& nums, int k) {
            int n = nums.size();
            vector<int> ps(n + 1, 0);
            for (int i = 1; i <= n; i++) ps[i] = nums[i - 1] + ps[i - 1];
            unordered_map<int, int> cnt;
            cnt[0] = 1;
            int res = 0;
            for (int i = 1; i <= n; i++) {
                res += cnt[ps[i] - k];
                cnt[ps[i]]++;
            }
            return res;
        }
        */

    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size(), sum = 0, res = 0;
        unordered_map<int, int> cnt;
        cnt[0] = 1;

        for (int& num : nums) {
            sum += num;
            res += cnt[sum - k];
            cnt[sum] ++;
        }
        return res;
    }
};
// @lc code=end

