/*
 * @lc app=leetcode id=52 lang=java
 *
 * [52] N-Queens II
 */

// @lc code=start
class Solution {
    private int res = 0;

    public int totalNQueens(int n) {
        boolean[] cols = new boolean[n]; // columns |
        boolean[] d1 = new boolean[2 * n]; // diagonals \
        boolean[] d2 = new boolean[2 * n];// diagonals /
        backtracking(0, cols, d1, d2, n);
        return res;
    }

    private void backtracking(int row, boolean[] cols, boolean[] d1, boolean[] d2, int n) {
        // 到最后一行了
        if (row == n) {
            res++;
            return;
        }
        // 一列一列的遍历
        for (int col = 0; col < n; col++) {
            int id1 = col - row + n;
            int id2 = col + row;
            // 如果同一列，左对角线，右对角线有棋子的话，就换一列
            if (cols[col] || d1[id1] || d2[id2])
                continue;
            // 落子
            cols[col] = true;
            d1[id1] = true;
            d2[id2] = true;
            // 下一行
            backtracking(row + 1, cols, d1, d2, n);
            cols[col] = false;
            d1[id1] = false;
            d2[id2] = false;
        }
    }

}
// @lc code=end
