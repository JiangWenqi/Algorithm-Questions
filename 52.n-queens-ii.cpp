/*
 * @lc app=leetcode id=52 lang=cpp
 *
 * [52] N-Queens II
 */

// @lc code=start
class Solution
{
private:
    int num;
    vector<bool> col, dg, udg;
    vector<string> path;
    vector<vector<string>> res;

    void dfs(int row)
    {
        if (row == num)
        {
            res.push_back(path);
            return;
        }
        for (int i = 0; i < num; i++)
        {
            if (!col[i] && !dg[i - row + num] && !udg[i + row])
            {
                path[row][i] = 'Q';
                col[i] = dg[i - row + num] = udg[i + row] = true;
                dfs(row + 1);
                path[row][i] = '.';
                col[i] = dg[i - row + num] = udg[i + row] = false;
            }
        }
    }

public:
    int totalNQueens(int n)
    {
        num = n;
        col.resize(n, false);
        dg.resize(2 * n, false);
        udg.resize(2 * n, false);

        dfs(0);
        return res;
    }
};
// @lc code=end
