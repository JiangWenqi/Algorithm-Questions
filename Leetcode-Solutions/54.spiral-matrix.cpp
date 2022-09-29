// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem54.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=54 lang=cpp
 *
 * [54] Spiral Matrix
 *
 * https://leetcode.com/problems/spiral-matrix/description/
 *
 * algorithms
 * Medium (43.34%)
 * Likes:    9015
 * Dislikes: 923
 * Total Accepted:    862.2K
 * Total Submissions: 2M
 * Testcase Example:  '[[1,2,3],[4,5,6],[7,8,9]]'
 *
 * Given an m x n matrix, return all elements of the matrix in spiral order.
 *
 *
 * Example 1:
 *
 *
 * Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
 * Output: [1,2,3,6,9,8,7,4,5]
 *
 *
 * Example 2:
 *
 *
 * Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
 * Output: [1,2,3,4,8,12,11,10,9,5,6,7]
 *
 *
 *
 * Constraints:
 *
 *
 * m == matrix.length
 * n == matrix[i].length
 * 1 <= m, n <= 10
 * -100 <= matrix[i][j] <= 100
 *
 *
 */

 // @lc code=start
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int sz = m * n;
        vector<int> res(sz);
        int idx = 0, up = 0, down = m - 1, left = 0, right = n - 1;
        while (idx < sz) {
            for (int i = left; i <= right && idx < sz; i++) {
                res[idx++] = matrix[up][i];
            }
            up++;
            for (int i = up; i <= down && idx < sz; i++) {
                res[idx++] = matrix[i][right];
            }
            right--;
            for (int i = right; i >= left && idx < sz; i--) {
                res[idx++] = matrix[down][i];
            }
            down--;
            for (int i = down; i >= up && idx < sz; i--) {
                res[idx++] = matrix[i][left];
            }
            left++;
        }
        return res;
    }
};
// @lc code=end

