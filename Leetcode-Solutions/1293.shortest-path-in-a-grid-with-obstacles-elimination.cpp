/*
 * @lc app=leetcode id=1293 lang=cpp
 *
 * [1293] Shortest Path in a Grid with Obstacles Elimination
 *
 * https://leetcode.com/problems/shortest-path-in-a-grid-with-obstacles-elimination/description/
 *
 * algorithms
 * Hard (43.61%)
 * Likes:    3321
 * Dislikes: 59
 * Total Accepted:    144.8K
 * Total Submissions: 325.3K
 * Testcase Example:  '[[0,0,0],[1,1,0],[0,0,0],[0,1,1],[0,0,0]]\n1'
 *
 * You are given an m x n integer matrix grid where each cell is either 0
 * (empty) or 1 (obstacle). You can move up, down, left, or right from and to
 * an empty cell in one step.
 *
 * Return the minimum number of steps to walk from the upper left corner (0, 0)
 * to the lower right corner (m - 1, n - 1) given that you can eliminate at
 * most k obstacles. If it is not possible to find such walk return -1.
 *
 *
 * Example 1:
 *
 *
 * Input: grid = [[0,0,0],[1,1,0],[0,0,0],[0,1,1],[0,0,0]], k = 1
 * Output: 6
 * Explanation:
 * The shortest path without eliminating any obstacle is 10.
 * The shortest path with one obstacle elimination at position (3,2) is 6. Such
 * path is (0,0) -> (0,1) -> (0,2) -> (1,2) -> (2,2) -> (3,2) -> (4,2).
 *
 *
 * Example 2:
 *
 *
 * Input: grid = [[0,1,1],[1,1,1],[1,0,0]], k = 1
 * Output: -1
 * Explanation: We need to eliminate at least two obstacles to find such a
 * walk.
 *
 *
 *
 * Constraints:
 *
 *
 * m == grid.length
 * n == grid[i].length
 * 1 <= m, n <= 40
 * 1 <= k <= m * n
 * grid[i][j] is either 0 or 1.
 * grid[0][0] == grid[m - 1][n - 1] == 0
 *
 *
 */

// @lc code=start
class Solution
{
public:
    int shortestPath(vector<vector<int>> &grid, int k)
    {
        int dirs[5] = {0, 1, 0, -1, 0};
        int n = grid.size(), m = grid[0].size(), INF = 1e6;
        vector<vector<vector<int>>> dist(n, vector<vector<int>>(m, vector<int>(k + 1, INF)));
        dist[0][0][0] = 0;
        queue<array<int, 3>> q;
        q.push({0, 0, 0});
        while (!q.empty())
        {
            auto [x, y, count] = q.front();
            q.pop();
            int d = dist[x][y][count];
            if (x == n - 1 && y == m - 1)
                return dist[x][y][count];
            for (int i = 0; i < 4; i++)
            {
                int nx = x + dirs[i], ny = y + dirs[i + 1];
                if (nx >= 0 && nx < n && ny >= 0 && ny < m)
                {
                    int nextCount = count + grid[x][y];
                    if (nextCount <= k && dist[nx][ny][nextCount] > d + 1)
                    {
                        dist[nx][ny][nextCount] = d + 1;
                        q.push({nx, ny, nextCount});
                    }
                }
            }
        }
        return -1;
    }
};

// @lc code=end
