// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem52.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=52 lang=cpp
 *
 * [52] N-Queens II
 */

// @lc code=start
class Solution
{
private:
    int nums, res = 0;
    vector<bool> cols, dgs, udgs;
    void dfs(int row)
    {
        if (row == nums)
        {
            res++;
            return;
        }
        // y = x + k => k = y - x
        // y = -x + k => k = y + x
        for (int col = 0; col < nums; col++)
        {
            if (!cols[col] && !dgs[row - col + nums] && !udgs[row + col])
            {
                cols[col] = dgs[row - col + nums] = udgs[row + col] = true;
                dfs(row + 1);
                cols[col] = dgs[row - col + nums] = udgs[row + col] = false;
            }
        }
    }

public:
    int totalNQueens(int n)
    {
        nums = n;
        cols.resize(n, false);
        dgs.resize(2 * n, false);
        udgs.resize(2 * n, false);
        dfs(0);
        return res;
    }
};
// @lc code=end
