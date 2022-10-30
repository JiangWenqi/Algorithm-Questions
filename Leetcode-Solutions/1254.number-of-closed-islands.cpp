/*
 * @lc app=leetcode id=1254 lang=cpp
 *
 * [1254] Number of Closed Islands
 *
 * https://leetcode.com/problems/number-of-closed-islands/description/
 *
 * algorithms
 * Medium (64.19%)
 * Likes:    2513
 * Dislikes: 57
 * Total Accepted:    115K
 * Total Submissions: 179.2K
 * Testcase Example:  '[[1,1,1,1,1,1,1,0],[1,0,0,0,0,1,1,0],[1,0,1,0,1,1,1,0],[1,0,0,0,0,1,0,1],[1,1,1,1,1,1,1,0]]'
 *
 * Given a 2D grid consists of 0s (land) and 1s (water).  An island is a
 * maximal 4-directionally connected group of 0s and a closed island is an
 * island totally (all left, top, right, bottom) surrounded by 1s.
 *
 * Return the number of closed islands.
 *
 *
 * Example 1:
 *
 *
 *
 *
 * Input: grid =
 * [[1,1,1,1,1,1,1,0],[1,0,0,0,0,1,1,0],[1,0,1,0,1,1,1,0],[1,0,0,0,0,1,0,1],[1,1,1,1,1,1,1,0]]
 * Output: 2
 * Explanation:
 * Islands in gray are closed because they are completely surrounded by water
 * (group of 1s).
 *
 * Example 2:
 *
 *
 *
 *
 * Input: grid = [[0,0,1,0,0],[0,1,0,1,0],[0,1,1,1,0]]
 * Output: 1
 *
 *
 * Example 3:
 *
 *
 * Input: grid = [[1,1,1,1,1,1,1],
 * [1,0,0,0,0,0,1],
 * [1,0,1,1,1,0,1],
 * [1,0,1,0,1,0,1],
 * [1,0,1,1,1,0,1],
 * [1,0,0,0,0,0,1],
 * ⁠              [1,1,1,1,1,1,1]]
 * Output: 2
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= grid.length, grid[0].length <= 100
 * 0 <= grid[i][j] <=1
 *
 *
 */

// @lc code=start
class Solution
{
private:
    int res = 0, n, m;
    int dirs[5] = {0, 1, 0, -1, 0};
    void bfs(int row, int col, vector<vector<int>> &grid)
    {
        queue<pair<int, int>> q;
        q.push({row, col});
        grid[row][col] = 1;
        while (!q.empty())
        {
            auto x = q.front().first, y = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++)
            {
                int nx = x + dirs[i], ny = y + dirs[i + 1];
                if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] == 0)
                {
                    q.push({nx, ny});
                    grid[nx][ny] = 1;
                }
            }
        }
    }

public:
    int closedIsland(vector<vector<int>> &grid)
    {
        n = grid.size(), m = grid[0].size();
        // the first row and last row
        for (int i = 0; i < m; i++)
        {
            if (grid[0][i] == 0)
                bfs(0, i, grid);
            if (grid[n - 1][i] == 0)
                bfs(n - 1, i, grid);
        }
        // the first col and last col
        for (int i = 0; i < n; i++)
        {
            if (grid[i][0] == 0)
                bfs(i, 0, grid);
            if (grid[i][m - 1] == 0)
                bfs(i, m - 1, grid);
        }

        // visiting inside
        for (int i = 1; i < n - 1; i++)
        {
            for (int j = 1; j < m - 1; j++)
            {
                if (grid[i][j] == 0)
                {
                    res++;
                    bfs(i, j, grid);
                }
            }
        }
        return res;
    }
};
// @lc code=end
