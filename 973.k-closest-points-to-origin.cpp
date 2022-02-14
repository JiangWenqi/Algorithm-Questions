/*
 * @lc app=leetcode id=973 lang=cpp
 *
 * [973] K Closest Points to Origin
 */

// @lc code=start

class Solution
{
public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
    {
        nth_element(points.begin(), points.begin() + k - 1, points.end(), [](vector<int> &a, vector<int> &b)
                    { return a[0] * a[0] + a[1] * a[1] < b[0] * b[0] + b[1] * b[1]; });
        return vector<vector<int>>(points.begin(), points.begin() + k);
    }
};
// @lc code=end
