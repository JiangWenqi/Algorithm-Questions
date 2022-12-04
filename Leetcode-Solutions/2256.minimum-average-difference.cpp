/*
 * @lc app=leetcode id=2256 lang=cpp
 *
 * [2256] Minimum Average Difference
 *
 * https://leetcode.com/problems/minimum-average-difference/description/
 *
 * algorithms
 * Medium (35.92%)
 * Likes:    1145
 * Dislikes: 139
 * Total Accepted:    62.3K
 * Total Submissions: 143.6K
 * Testcase Example:  '[2,5,3,9,5,3]'
 *
 * You are given a 0-indexed integer array nums of length n.
 * 
 * The average difference of the index i is the absolute difference between the
 * average of the first i + 1 elements of nums and the average of the last n -
 * i - 1 elements. Both averages should be rounded down to the nearest
 * integer.
 * 
 * Return the index with the minimum average difference. If there are multiple
 * such indices, return the smallest one.
 * 
 * Note:
 * 
 * 
 * The absolute difference of two numbers is the absolute value of their
 * difference.
 * The average of n elements is the sum of the n elements divided (integer
 * division) by n.
 * The average of 0 elements is considered to be 0.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [2,5,3,9,5,3]
 * Output: 3
 * Explanation:
 * - The average difference of index 0 is: |2 / 1 - (5 + 3 + 9 + 5 + 3) / 5| =
 * |2 / 1 - 25 / 5| = |2 - 5| = 3.
 * - The average difference of index 1 is: |(2 + 5) / 2 - (3 + 9 + 5 + 3) / 4|
 * = |7 / 2 - 20 / 4| = |3 - 5| = 2.
 * - The average difference of index 2 is: |(2 + 5 + 3) / 3 - (9 + 5 + 3) / 3|
 * = |10 / 3 - 17 / 3| = |3 - 5| = 2.
 * - The average difference of index 3 is: |(2 + 5 + 3 + 9) / 4 - (5 + 3) / 2|
 * = |19 / 4 - 8 / 2| = |4 - 4| = 0.
 * - The average difference of index 4 is: |(2 + 5 + 3 + 9 + 5) / 5 - 3 / 1| =
 * |24 / 5 - 3 / 1| = |4 - 3| = 1.
 * - The average difference of index 5 is: |(2 + 5 + 3 + 9 + 5 + 3) / 6 - 0| =
 * |27 / 6 - 0| = |4 - 0| = 4.
 * The average difference of index 3 is the minimum average difference so
 * return 3.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [0]
 * Output: 0
 * Explanation:
 * The only index is 0 so return 0.
 * The average difference of index 0 is: |0 / 1 - 0| = |0 - 0| = 0.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 10^5
 * 0 <= nums[i] <= 10^5
 * 
 * 
 */

// @lc code=start
class Solution
{
    public:
        int minimumAverageDifference(vector<int> &nums)
        {
            int n = nums.size(), res = 0;
            long long sum = 0, curr = 0, minAvg = INT_MAX;

            for (int &num: nums) sum += num;
            for (int i = 0; i < n; i++)
            {
                curr += nums[i];
                long long la = curr / (i + 1);
                long long ra = sum - curr;
                if (i != n - 1) ra /= n - 1 - i;
                long long avg = (int) abs(la - ra);
                if (avg < minAvg)
                {
                    minAvg = avg;
                    res = i;
                }
            }
            return res;
        }
};
// @lc code=end

