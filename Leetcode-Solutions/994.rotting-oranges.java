import java.util.ArrayList;

/*
 * @lc app=leetcode id=994 lang=java
 *
 * [994] Rotting Oranges
 *
 * https://leetcode.com/problems/rotting-oranges/description/
 *
 * algorithms
 * Medium (52.39%)
 * Likes:    8520
 * Dislikes: 311
 * Total Accepted:    495.6K
 * Total Submissions: 945.9K
 * Testcase Example:  '[[2,1,1],[1,1,0],[0,1,1]]'
 *
 * You are given an m x n grid where each cell can have one of three
 * values:
 * 
 * 
 * 0 representing an empty cell,
 * 1 representing a fresh orange, or
 * 2 representing a rotten orange.
 * 
 * 
 * Every minute, any fresh orange that is 4-directionally adjacent to a rotten
 * orange becomes rotten.
 * 
 * Return the minimum number of minutes that must elapse until no cell has a
 * fresh orange. If this is impossible, return -1.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
 * Output: 4
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: grid = [[2,1,1],[0,1,1],[1,0,1]]
 * Output: -1
 * Explanation: The orange in the bottom left corner (row 2, column 0) is never
 * rotten, because rotting only happens 4-directionally.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: grid = [[0,2]]
 * Output: 0
 * Explanation: Since there are already no fresh oranges at minute 0, the
 * answer is just 0.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * m == grid.length
 * n == grid[i].length
 * 1 <= m, n <= 10
 * grid[i][j] is 0, 1, or 2.
 * 
 * 
 */

// @lc code=start
class Solution {

    public int orangesRotting(int[][] grid) {
        int[] dirs = new int[] { 0, 1, 0, -1, 0 };
        int m = grid.length;
        int n = grid[0].length;
        int orange = 0;
        int rotten = 0;
        Queue<Integer> q = new LinkedList<>();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    orange++;
                } else if (grid[i][j] == 2) {
                    orange++;
                    rotten++;
                    q.offer(i * 1000 + j);
                }
            }
        }
        if (orange == 0)
            return 0;
        int res = -1;
        while (!q.isEmpty()) {
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                int point = q.poll();
                int x = point / 1000;
                int y = point % 1000;
                for (int j = 0; j < 4; j++) {
                    int nx = x + dirs[j];
                    int ny = y + dirs[j + 1];
                    if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == 1) {
                        grid[nx][ny] = 2;
                        rotten++;
                        q.offer(nx * 1000 + ny);
                    }
                }
            }
            res++;
        }
        return rotten == orange ? res : -1;
    }
}
// @lc code=end
