// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem51.h"

using namespace std;
// @before-stub-for-debug-end

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
    vector<vector<string>> res;
    vector<string> path;
    vector<bool> cols, dgs, udgs;

    void dfs(int row, int n)
    {
        if (row == n)
        {
            res.push_back(path);
            return;
        }

        for (int col = 0; col < n; col++)
        {
            if (!cols[col] && !dgs[row - col + n] && !udgs[row + col])
            {
                cols[col] = dgs[row - col + n] = udgs[row + col] = true;
                path[row][col] = 'Q';
                dfs(row + 1, n);
                path[row][col] = '.';
                cols[col] = dgs[row - col + n] = udgs[row + col] = false;
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n)
    {
        cols = vector<bool>(n);
        dgs = udgs = vector<bool>(n * 2);
        path = vector<string>(n, string(n, '.'));
        dfs(0, n);

        return res;
    }
};
// @lc code=end
