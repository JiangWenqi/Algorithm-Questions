/*
 * @lc app=leetcode id=645 lang=cpp
 *
 * [645] Set Mismatch
 *
 * https://leetcode.com/problems/set-mismatch/description/
 *
 * algorithms
 * Easy (41.35%)
 * Likes:    2798
 * Dislikes: 678
 * Total Accepted:    215K
 * Total Submissions: 508K
 * Testcase Example:  '[1,2,2,4]'
 *
 * You have a set of integers s, which originally contains all the numbers from
 * 1 to n. Unfortunately, due to some error, one of the numbers in s got
 * duplicated to another number in the set, which results in repetition of one
 * number and loss of another number.
 *
 * You are given an integer array nums representing the data status of this set
 * after the error.
 *
 * Find the number that occurs twice and the number that is missing and return
 * them in the form of an array.
 *
 *
 * Example 1:
 * Input: nums = [1,2,2,4]
 * Output: [2,3]
 * Example 2:
 * Input: nums = [1,1]
 * Output: [1,2]
 *
 *
 * Constraints:
 *
 *
 * 2 <= nums.length <= 10^4
 * 1 <= nums[i] <= 10^4
 *
 *
 */

// @lc code=start
class Solution
{
public:
    vector<int> findErrorNums(vector<int> &nums)
    {
        vector<int> res(2);
        for (auto x : nums)
        {
            int k = abs(x);
            if (nums[k - 1] < 0)
                res[0] = k;
            nums[k - 1] *= -1;
        }

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > 0 && i + 1 != res[0])
            {
                res[1] = i + 1;
            }
        }

        return res;
    }
};
// @lc code=end
