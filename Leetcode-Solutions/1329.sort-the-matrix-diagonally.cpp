#include <string>
#include <vector>

using namespace std;
/*
 * @lc app=leetcode id=1329 lang=cpp
 *
 * [1329] Sort the Matrix Diagonally
 *
 * https://leetcode.com/problems/sort-the-matrix-diagonally/description/
 *
 * algorithms
 * Medium (81.44%)
 * Likes:    2289
 * Dislikes: 193
 * Total Accepted:    108.6K
 * Total Submissions: 131.2K
 * Testcase Example:  '[[3,3,1,1],[2,2,1,2],[1,1,1,2]]'
 *
 * A matrix diagonal is a diagonal line of cells starting from some cell in
 * either the topmost row or leftmost column and going in the bottom-right
 * direction until reaching the matrix's end. For example, the matrix diagonal
 * starting from mat[2][0], where mat is a 6 x 3 matrix, includes cells
 * mat[2][0], mat[3][1], and mat[4][2].
 *
 * Given an m x n matrix mat of integers, sort each matrix diagonal in
 * ascending order and return the resulting matrix.
 *
 *
 * Example 1:
 *
 *
 * Input: mat = [[3,3,1,1],[2,2,1,2],[1,1,1,2]]
 * Output: [[1,1,1,1],[1,2,2,2],[1,2,3,3]]
 *
 *
 * Example 2:
 *
 *
 * Input: mat =
 * [[11,25,66,1,69,7],[23,55,17,45,15,52],[75,31,36,44,58,8],[22,27,33,25,68,4],[84,28,14,11,5,50]]
 * Output:
 * [[5,17,4,1,52,7],[11,11,25,45,8,69],[14,23,25,44,58,15],[22,27,31,36,50,66],[84,28,75,33,55,68]]
 *
 *
 *
 * Constraints:
 *
 *
 * m == mat.length
 * n == mat[i].length
 * 1 <= m, n <= 100
 * 1 <= mat[i][j] <= 100
 *
 *
 */

 // @lc code=start
class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size(), x, y, idx;
        vector<int> nums;
        // the first row
        for (int i = 0; i < m; i++) {
            nums.clear();
            // 1. add to nums
            x = 0, y = i;
            while (x < n && y < m) {
                nums.push_back(mat[x][y]);
                x++, y++;
            }
            // 2. sort
            sort(nums.begin(), nums.end());
            // 3. change the original number
            x = 0, y = i, idx = 0;
            while (x < n && y < m) {
                mat[x][y] = nums[idx];
                x++, y++, idx++;
            }
        }

        // the first col
        for (int i = 0; i < n; i++) {
            nums.clear();
            x = i, y = 0;
            while (x < n && y < m) {
                nums.push_back(mat[x][y]);
                x++, y++;
            }
            // 2. sort
            sort(nums.begin(), nums.end());
            // 3. change the original number
            x = i, y = 0, idx = 0;
            while (x < n && y < m) {
                mat[x][y] = nums[idx];
                x++, y++, idx++;
            }
        }
        return mat;
    }
};
// @lc code=end

