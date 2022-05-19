/*
 * @lc app=leetcode id=456 lang=cpp
 *
 * [456] 132 Pattern
 */

// @lc code=start
class Solution
{
public:
    bool find132pattern(vector<int> &nums)
    {
        int n = nums.size(), right = INT_MIN;
        stack<int> stk;
        for (int i = n - 1; i >= 0; i--)
        {
            if (nums[i] < right)
                return true;
            while (stk.size() && nums[i] > stk.top())
            {
                right = max(right, stk.top());
                stk.pop();
            }
            stk.push(nums[i]);
        }
        return false;
    }
};
// @lc code=end
