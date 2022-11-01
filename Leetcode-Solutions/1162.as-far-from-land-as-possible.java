import java.util.Queue;

/*
 * @lc app=leetcode id=1162 lang=java
 *
 * [1162] As Far from Land as Possible
 *
 * https://leetcode.com/problems/as-far-from-land-as-possible/description/
 *
 * algorithms
 * Medium (48.57%)
 * Likes:    2309
 * Dislikes: 69
 * Total Accepted:    77.8K
 * Total Submissions: 160.3K
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
    public int maxDistance(int[][] grid) {
        int[] dirs = new int[] { 0, 1, 0, -1, 0 };
        int res = -1;
        int n = grid.length;
        int m = grid[0].length;
        Queue<int[]> q = new LinkedList<>();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1)
                    q.add(new int[] { i, j });
            }
        }
        if (q.size() == 0 || q.size() == n * m)
            return res;

        while (!q.isEmpty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                int[] point = q.poll();
                int x = point[0];
                int y = point[1];
                for (int d = 0; d < 4; d++) {
                    int nx = x + dirs[d];
                    int ny = y + dirs[d + 1];
                    if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] == 0) {
                        grid[nx][ny] = 1;
                        q.add(new int[] { nx, ny });
                    }
                }
            }
            res++;
        }

        return res;
    }
}
// @lc code=end
