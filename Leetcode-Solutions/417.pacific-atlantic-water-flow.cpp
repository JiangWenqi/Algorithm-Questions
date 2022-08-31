// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem417.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=417 lang=cpp
 *
 * [417] Pacific Atlantic Water Flow
 *
 * https://leetcode.com/problems/pacific-atlantic-water-flow/description/
 *
 * algorithms
 * Medium (50.93%)
 * Likes:    4300
 * Dislikes: 933
 * Total Accepted:    236K
 * Total Submissions: 463.4K
 * Testcase Example:  '[[1,2,2,3,5],[3,2,3,4,4],[2,4,5,3,1],[6,7,1,4,5],[5,1,1,2,4]]'
 *
 * There is an m x n rectangular island that borders both the Pacific Ocean and
 * Atlantic Ocean. The Pacific Ocean touches the island's left and top edges,
 * and the Atlantic Ocean touches the island's right and bottom edges.
 *
 * The island is partitioned into a grid of square cells. You are given an m x
 * n integer matrix heights where heights[r][c] represents the height above sea
 * level of the cell at coordinate (r, c).
 *
 * The island receives a lot of rain, and the rain water can flow to
 * neighboring cells directly north, south, east, and west if the neighboring
 * cell's height is less than or equal to the current cell's height. Water can
 * flow from any cell adjacent to an ocean into the ocean.
 *
 * Return a 2D list of grid coordinates result where result[i] = [ri, ci]
 * denotes that rain water can flow from cell (ri, ci) to both the Pacific and
 * Atlantic oceans.
 *
 *
 * Example 1:
 *
 *
 * Input: heights =
 * [[1,2,2,3,5],[3,2,3,4,4],[2,4,5,3,1],[6,7,1,4,5],[5,1,1,2,4]]
 * Output: [[0,4],[1,3],[1,4],[2,2],[3,0],[3,1],[4,0]]
 *
 *
 * Example 2:
 *
 *
 * Input: heights = [[2,1],[1,2]]
 * Output: [[0,0],[0,1],[1,0],[1,1]]
 *
 *
 *
 * Constraints:
 *
 *
 * m == heights.length
 * n == heights[r].length
 * 1 <= m, n <= 200
 * 0 <= heights[r][c] <= 10^5
 *
 *
 */

 // @lc code=start
class Solution {
private:
    int n, m;
    int dirs[5] = { 0, 1, 0, -1, 0 };
    vector<vector<int>> state;
    void dfs(int x, int y, int val, vector<vector<int>>& heights) {
        if (state[x][y] & val) return;
        state[x][y] |= val;
        for (int i = 0; i < 4; i++) {
            int nx = x + dirs[i], ny = y + dirs[i + 1];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && heights[nx][ny] >= heights[x][y]) {
                dfs(nx, ny, val, heights);
            }
        }
    }

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        n = heights.size(), m = heights[0].size();
        state.resize(n, vector<int>(m, 0));
        vector<vector<int>> res;
        // north
        for (int i = 0; i < m; i++) dfs(0, i, 1, heights);
        // west
        for (int i = 0; i < n; i++) dfs(i, 0, 1, heights);
        // east
        for (int i = 0; i < n; i++) dfs(i, m - 1, 2, heights);
        // south
        for (int i = 0; i < m; i++) dfs(n - 1, i, 2, heights);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (state[i][j] == 3) res.push_back({ i, j });
            }
        }
        return res;

    }
};
// @lc code=end

