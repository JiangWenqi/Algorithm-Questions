/*
 * @lc app=leetcode id=1905 lang=cpp
 *
 * [1905] Count Sub Islands
 *
 * https://leetcode.com/problems/count-sub-islands/description/
 *
 * algorithms
 * Medium (67.80%)
 * Likes:    1438
 * Dislikes: 45
 * Total Accepted:    53.4K
 * Total Submissions: 78.7K
 * Testcase Example:  '[[1,1,1,0,0],[0,1,1,1,1],[0,0,0,0,0],[1,0,0,0,0],[1,1,0,1,1]]\n' +
  '[[1,1,1,0,0],[0,0,1,1,1],[0,1,0,0,0],[1,0,1,1,0],[0,1,0,1,0]]'
 *
 * You are given two m x n binary matrices grid1 and grid2 containing only 0's
 * (representing water) and 1's (representing land). An island is a group of
 * 1's connected 4-directionally (horizontal or vertical). Any cells outside of
 * the grid are considered water cells.
 *
 * An island in grid2 is considered a sub-island if there is an island in grid1
 * that contains all the cells that make up this island in grid2.
 *
 * Return the number of islands in grid2 that are considered sub-islands.
 *
 *
 * Example 1:
 *
 *
 * Input: grid1 =
 * [[1,1,1,0,0],[0,1,1,1,1],[0,0,0,0,0],[1,0,0,0,0],[1,1,0,1,1]], grid2 =
 * [[1,1,1,0,0],[0,0,1,1,1],[0,1,0,0,0],[1,0,1,1,0],[0,1,0,1,0]]
 * Output: 3
 * Explanation: In the picture above, the grid on the left is grid1 and the
 * grid on the right is grid2.
 * The 1s colored red in grid2 are those considered to be part of a sub-island.
 * There are three sub-islands.
 *
 *
 * Example 2:
 *
 *
 * Input: grid1 =
 * [[1,0,1,0,1],[1,1,1,1,1],[0,0,0,0,0],[1,1,1,1,1],[1,0,1,0,1]], grid2 =
 * [[0,0,0,0,0],[1,1,1,1,1],[0,1,0,1,0],[0,1,0,1,0],[1,0,0,0,1]]
 * Output: 2
 * Explanation: In the picture above, the grid on the left is grid1 and the
 * grid on the right is grid2.
 * The 1s colored red in grid2 are those considered to be part of a sub-island.
 * There are two sub-islands.
 *
 *
 *
 * Constraints:
 *
 *
 * m == grid1.length == grid2.length
 * n == grid1[i].length == grid2[i].length
 * 1 <= m, n <= 500
 * grid1[i][j] and grid2[i][j] are either 0 or 1.
 *
 *
 */

// @lc code=start
class Solution
{
private:
    int dirs[5] = {0, 1, 0, -1, 0};
    queue<pair<int, int>> q;
    int n, m;
    bool bfs(int row, int col, vector<vector<int>> &grid1, vector<vector<int>> &grid2)
    {
        bool same = true;
        grid2[row][col] = 0;
        if (!grid1[row][col])
            same = false;
        q.push({row, col});
        while (!q.empty())
        {
            int x = q.front().first, y = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++)
            {
                int nx = x + dirs[i], ny = y + dirs[i + 1];
                if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid2[nx][ny])
                {
                    if (!grid1[nx][ny])
                        same = false;
                    grid2[nx][ny] = 0;
                    q.push({nx, ny});
                }
            }
        }
        return same;
    }

public:
    int countSubIslands(vector<vector<int>> &grid1, vector<vector<int>> &grid2)
    {
        n = grid1.size(), m = grid1[0].size();
        int res = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid2[i][j] && bfs(i, j, grid1, grid2))
                    res++;
            }
        }
        return res;
    }
};
// @lc code=end
