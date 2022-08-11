/*
 * @lc app=leetcode id=74 lang=cpp
 *
 * [74] Search a 2D Matrix
 *
 * https://leetcode.com/problems/search-a-2d-matrix/description/
 *
 * algorithms
 * Medium (45.02%)
 * Likes:    7949
 * Dislikes: 282
 * Total Accepted:    828.7K
 * Total Submissions: 1.8M
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
public:
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int m = matrix.size(), n = matrix[0].size();
    int top = 0, bottom = m - 1;
    while (top < bottom) {
      int mid = top + bottom >> 1;
      if (matrix[mid][n - 1] >= target) bottom = mid;
      else top = mid + 1;
    }

    int l = 0, r = n - 1;
    while (l < r) {
      int mid = l + r >> 1;
      if (matrix[top][mid] >= target) r = mid;
      else l = mid + 1;
    }

    return matrix[top][l] == target;
  }

};
// @lc code=end
