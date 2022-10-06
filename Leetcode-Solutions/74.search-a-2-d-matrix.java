/*
 * @lc app=leetcode id=74 lang=java
 *
 * [74] Search a 2D Matrix
 *
 * https://leetcode.com/problems/search-a-2d-matrix/description/
 *
 * algorithms
 * Medium (46.63%)
 * Likes:    9893
 * Dislikes: 308
 * Total Accepted:    1M
 * Total Submissions: 2.1M
 * Testcase Example:  '[[1,3,5,7],[10,11,16,20],[23,30,34,60]]\n3'
 *
 * Write an efficient algorithm that searches for a value target in an m x n
 * integer matrix matrix. This matrix has the following properties:
 * 
 * 
 * Integers in each row are sorted from left to right.
 * The first integer of each row is greater than the last integer of the
 * previous row.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
 * Output: false
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * m == matrix.length
 * n == matrix[i].length
 * 1 <= m, n <= 100
 * -10^4 <= matrix[i][j], target <= 10^4
 * 
 * 
 */

// @lc code=start
class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        int m = matrix.length, n = matrix[0].length;
        // find the row
        int u = 0, d = m - 1;
        while (u < d) {
            int mid = u + d >> 1;
            if (matrix[mid][n - 1] >= target)
                d = mid;
            else
                u = mid + 1;
        }
        // find the column
        int l = 0, r = n - 1;
        while (l <= r) {
            int mid = l + r >> 1;
            if (matrix[u][mid] > target)
                r = mid - 1;
            else if (matrix[u][mid] < target)
                l = mid + 1;
            else
                return true;
        }
        return false;

    }
}
// @lc code=end
