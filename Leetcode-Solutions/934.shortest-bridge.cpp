// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem934.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=934 lang=cpp
 *
 * [934] Shortest Bridge
 *
 * https://leetcode.com/problems/shortest-bridge/description/
 *
 * algorithms
 * Medium (53.98%)
 * Likes:    3273
 * Dislikes: 146
 * Total Accepted:    114.9K
 * Total Submissions: 212.9K
 * Testcase Example:  '[[0,1],[1,0]]'
 *
 * You are given an n x n binary matrix grid where 1 represents land and 0
 * represents water.
 *
 * An island is a 4-directionally connected group of 1's not connected to any
 * other 1's. There are exactly two islands in grid.
 *
 * You may change 0's to 1's to connect the two islands to form one island.
 *
 * Return the smallest number of 0's you must flip to connect the two
 * islands.
 *
 *
 * Example 1:
 *
 *
 * Input: grid = [[0,1],[1,0]]
 * Output: 1
 *
 *
 * Example 2:
 *
 *
 * Input: grid = [[0,1,0],[0,0,0],[0,0,1]]
 * Output: 2
 *
 *
 * Example 3:
 *
 *
 * Input: grid = [[1,1,1,1,1],[1,0,0,0,1],[1,0,1,0,1],[1,0,0,0,1],[1,1,1,1,1]]
 * Output: 1
 *
 *
 *
 * Constraints:
 *
 *
 * n == grid.length == grid[i].length
 * 2 <= n <= 100
 * grid[i][j] is either 0 or 1.
 * There are exactly two islands in grid.
 *
 * 多源 BFS
 */

// @lc code=start
class Solution
{
private:
    int dirs[5] = {0, 1, 0, -1, 0};
    int n, m;
    vector<vector<int>> dist;
    queue<pair<int, int>> q;

    /**
     * put the nodes of the first island to queue
     * and init the distance to 0
     * mark it as visited
     */
    void dfs(int row, int col, vector<vector<int>> &grid)
    {
        grid[row][col] = 0;
        dist[row][col] = 0;
        q.push({row, col});
        for (int i = 0; i < 4; i++)
        {
            int x = row + dirs[i], y = col + dirs[i + 1];
            if (x >= 0 && x < n && y >= 0 && y < m && grid[x][y])
                dfs(x, y, grid);
        }
    }
    /**
     * try to find the closet node of the second island
     */
    int bfs(vector<vector<int>> &grid)
    {
        while (!q.empty())
        {
            int x = q.front().first, y = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++)
            {
                int nx = x + dirs[i], ny = y + dirs[i + 1];
                if (nx >= 0 && nx < n && ny >= 0 && ny < m && dist[nx][ny] > dist[x][y] + 1)
                {
                    if (grid[nx][ny])
                        return dist[x][y];
                    dist[nx][ny] = dist[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }
        return -1;
    }

public:
    /**
     * There are exactly two islands in grid.
     */
    int shortestBridge(vector<vector<int>> &grid)
    {
        n = grid.size(), m = grid[0].size();
        dist = vector(n, vector<int>(m, 1e8));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j])
                {
                    dfs(i, j, grid);
                    return bfs(grid);
                }
            }
        }
        return -1;
    }
};
// @lc code=end
