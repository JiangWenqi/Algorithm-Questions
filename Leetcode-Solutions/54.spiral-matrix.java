import java.util.LinkedList;
import java.util.List;

/*
 * @lc app=leetcode id=54 lang=java
 *
 * [54] Spiral Matrix
 */

// @lc code=start
class Solution {


    public List<Integer> spiralOrder(int[][] matrix) {
        List<Integer> ans = new LinkedList<>();

        // your code goes here
        int rows = matrix.length, columns = matrix[0].length;
        int n = rows * columns;
        int startRow = 0, endRow = rows - 1;
        int startColumn = 0, endColumn = columns - 1;
        int index = 0;
        while (index < n) {
            for (int i = startColumn; i <= endColumn && index < n; i++) {
                ans.add(matrix[startRow][i]);
                index++;
            }
            startRow++;
            for (int i = startRow; i <= endRow && index < n; i++) {
                ans.add(matrix[i][endColumn]);
                index++;
            }
            endColumn--;
            for (int i = endColumn; i >= startColumn && index < n; i--) {
                ans.add(matrix[endRow][i]);
                index++;
            }
            endRow--;
            for (int i = endRow; i >= startRow && index < n; i--) {
                ans.add(matrix[i][startColumn]);
                index++;
            }
            startColumn++;
        }

        return ans;
    }

}
// @lc code=end
