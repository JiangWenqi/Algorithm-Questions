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
        vector<vector<int>> res(k);
        priority_queue<vector<int>> q;
        for (auto &point : points)
        {
            int x = point[0], y = point[1];
            q.push({x * x + y * y, x, y});
            if (q.size() > k)
                q.pop();
        }
        for (int i = 0; i < k; i++)
        {
            res[i] = {q.top()[1], q.top()[2]};
            q.pop();
        }
        return res;
    }
};
// @lc code=end
