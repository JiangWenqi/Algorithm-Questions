/*
 * @lc app=leetcode id=51 lang=cpp
 *
 * [51] N-Queens
 *
 * https://leetcode.com/problems/n-queens/description/
 *
 * algorithms
 * Hard (57.69%)
 * Likes:    5845
 * Dislikes: 152
 * Total Accepted:    367.8K
 * Total Submissions: 637.5K
 * Testcase Example:  '4'
 *
 * The n-queens puzzle is the problem of placing n queens on an n x n
 * chessboard such that no two queens attack each other.
 *
 * Given an integer n, return all distinct solutions to the n-queens puzzle.
 * You may return the answer in any order.
 *
 * Each solution contains a distinct board configuration of the n-queens'
 * placement, where 'Q' and '.' both indicate a queen and an empty space,
 * respectively.
 *
 *
 * Example 1:
 *
 *
 * Input: n = 4
 * Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
 * Explanation: There exist two distinct solutions to the 4-queens puzzle as
 * shown above
 *
 *
 * Example 2:
 *
 *
 * Input: n = 1
 * Output: [["Q"]]
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= n <= 9
 *
 *
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
    vector<vector<string>> solveNQueens(int n)
    {
        num = n;
        col.resize(n, false);
        dg.resize(2 * n, false);
        udg.resize(2 * n, false);
        path = vector<string>(n, string(n, '.'));

        dfs(0);
        return res;
    }
};
// @lc code=end
