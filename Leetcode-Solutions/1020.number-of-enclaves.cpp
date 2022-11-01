// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem1020.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=1020 lang=cpp
 *
 * [1020] Number of Enclaves
 *
 * https://leetcode.com/problems/number-of-enclaves/description/
 *
 * algorithms
 * Medium (64.84%)
 * Likes:    1832
 * Dislikes: 37
 * Total Accepted:    79.8K
 * Total Submissions: 123.1K
 * Testcase Example:  '[[0,0,0,0],[1,0,1,0],[0,1,1,0],[0,0,0,0]]'
 *
 * You are given an m x n binary matrix grid, where 0 represents a sea cell and
 * 1 represents a land cell.
 *
 * A move consists of walking from one land cell to another adjacent
 * (4-directionally) land cell or walking off the boundary of the grid.
 *
 * Return the number of land cells in grid for which we cannot walk off the
 * boundary of the grid in any number of moves.
 *
 *
 * Example 1:
 *
 *
 * Input: grid = [[0,0,0,0],[1,0,1,0],[0,1,1,0],[0,0,0,0]]
 * Output: 3
 * Explanation: There are three 1s that are enclosed by 0s, and one 1 that is
 * not enclosed because its on the boundary.
 *
 *
 * Example 2:
 *
 *
 * Input: grid = [[0,1,1,0],[0,0,1,0],[0,0,1,0],[0,0,0,0]]
 * Output: 0
 * Explanation: All 1s are either on the boundary or can reach the
 * boundary.
 *
 *
 *
 * Constraints:
 *
 *
 * m == grid.length
 * n == grid[i].length
 * 1 <= m, n <= 500
 * grid[i][j] is either 0 or 1.
 *
 *
 */

// @lc code=start
class Solution
{
private:
    int dirs[5] = {0, 1, 0, -1, 0};
    int n, m, res = 0;
    queue<pair<int, int>> q;
    void bfs(int row, int col, vector<vector<int>> &grid)
    {
        grid[row][col] = 0;

        q.push({row, col});
        while (!q.empty())
        {
            int x = q.front().first, y = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++)
            {
                int nx = x + dirs[i], ny = y + dirs[i + 1];
                if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny])
                {
                    grid[nx][ny] = 0;
                    q.push({nx, ny});
                }
            }
        }
    }

    void bfs1(int row, int col, vector<vector<int>> &grid)
    {
        grid[row][col] = 0;
        res++;
        q.push({row, col});
        while (!q.empty())
        {
            int x = q.front().first, y = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++)
            {
                int nx = x + dirs[i], ny = y + dirs[i + 1];
                if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny])
                {
                    grid[nx][ny] = 0;
                    q.push({nx, ny});
                    res++;
                }
            }
        }
    }

public:
    int numEnclaves(vector<vector<int>> &grid)
    {
        n = grid.size(), m = grid[0].size();
        if (n <= 2 || m <= 2)
            return 0;
        // the first row and last row
        for (int i = 0; i < m; i++)
        {
            if (grid[0][i])
                bfs(0, i, grid);
            if (grid[n - 1][i])
                bfs(n - 1, i, grid);
        }

        // the first col and last col
        for (int i = 0; i < n; i++)
        {
            if (grid[i][0])
                bfs(i, 0, grid);
            if (grid[i][m - 1])
                bfs(i, m - 1, grid);
        }

        for (int i = 1; i < n - 1; i++)
        {
            for (int j = 1; j < m - 1; j++)
            {
                if (grid[i][j])
                    bfs1(i, j, grid);
            }
        }
        return res;
    }
};
// @lc code=end
