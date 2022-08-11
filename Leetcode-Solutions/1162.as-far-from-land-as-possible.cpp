/*
 * @lc app=leetcode id=1162 lang=cpp
 *
 * [1162] As Far from Land as Possible
 *
 * https://leetcode.com/problems/as-far-from-land-as-possible/description/
 *
 * algorithms
 * Medium (48.06%)
 * Likes:    1757
 * Dislikes: 59
 * Total Accepted:    61.3K
 * Total Submissions: 127.5K
 * Testcase Example:  '[[1,0,1],[0,0,0],[1,0,1]]'
 *
 * Given an n x n grid containing only values 0 and 1, where 0 represents water
 * and 1 represents land, find a water cell such that its distance to the
 * nearest land cell is maximized, and return the distance. If no land or water
 * exists in the grid, return -1.
 * 
 * The distance used in this problem is the Manhattan distance: the distance
 * between two cells (x0, y0) and (x1, y1) is |x0 - x1| + |y0 - y1|.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: grid = [[1,0,1],[0,0,0],[1,0,1]]
 * Output: 2
 * Explanation: The cell (1, 1) is as far as possible from all the land with
 * distance 2.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: grid = [[1,0,0],[0,0,0],[0,0,0]]
 * Output: 4
 * Explanation: The cell (2, 2) is as far as possible from all the land with
 * distance 4.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * n == grid.length
 * n == grid[i].length
 * 1 <= n <= 100
 * grid[i][j] is 0 or 1
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int dirs[5] = {0, 1, 0, -1, 0};
        int res = -1;
        int m = grid.size(), n = grid[0].size();
        queue<pair<int, int>> q;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j]) {
                    q.push(make_pair(i, j));
                    // make it visited
                    grid[i][j] = -1;
                }
            }
        }
        // if all cell are sea or lands, return -1
        if (q.empty() || q.size() == m * n) return res;

        while (!q.empty()) {
            int num = q.size();
            for (int k = 0; k < num; k++) {
                int x = q.front().first, y = q.front().second;
                q.pop();
                for (int i = 0; i < 4; i++) {
                    int nx = x + dirs[i], ny = y + dirs[i + 1];
                    if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == 0) {
                        grid[nx][ny] = -1;
                        q.push(make_pair(nx, ny));
                    }
                }
            }
            res++;
        }
        return res;
    }
};
// @lc code=end

