// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem1074.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=1074 lang=cpp
 *
 * [1074] Number of Submatrices That Sum to Target
 *
 * https://leetcode.com/problems/number-of-submatrices-that-sum-to-target/description/
 *
 * algorithms
 * Hard (66.39%)
 * Likes:    1963
 * Dislikes: 49
 * Total Accepted:    58.5K
 * Total Submissions: 86.3K
 * Testcase Example:  '[[0,1,0],[1,1,1],[0,1,0]]\n0'
 *
 * Given a matrix and a target, return the number of non-empty submatrices that
 * sum to target.
 *
 * A submatrix x1, y1, x2, y2 is the set of all cells matrix[x][y] with x1 <= x
 * <= x2 and y1 <= y <= y2.
 *
 * Two submatrices (x1, y1, x2, y2) and (x1', y1', x2', y2') are different if
 * they have some coordinate that is different: for example, if x1 != x1'.
 *
 *
 * Example 1:
 *
 *
 * Input: matrix = [[0,1,0],[1,1,1],[0,1,0]], target = 0
 * Output: 4
 * Explanation: The four 1x1 submatrices that only contain 0.
 *
 *
 * Example 2:
 *
 *
 * Input: matrix = [[1,-1],[-1,1]], target = 0
 * Output: 5
 * Explanation: The two 1x2 submatrices, plus the two 2x1 submatrices, plus the
 * 2x2 submatrix.
 *
 *
 * Example 3:
 *
 *
 * Input: matrix = [[904]], target = 0
 * Output: 0
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= matrix.length <= 100
 * 1 <= matrix[0].length <= 100
 * -1000 <= matrix[i] <= 1000
 * -10^8 <= target <= 10^8
 *
 *
 */

 // @lc code=start
class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> colSum(m + 1, vector<int>(n + 1, 0));
        // 1. get the prefix sum of each column
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n;j++) {
                colSum[i][j] = colSum[i - 1][j] + matrix[i - 1][j - 1];
            }
        }
        int res = 0;
        // 2. from ith row to jth row, calculate the sum of area, and store it in hash map, which is same to prefix sum
        for (int i = 1; i <= m; i++) {
            for (int j = i;j <= m; j++) {
                unordered_map<int, int> cnt;
                cnt[0] ++;
                // get the sum of rows i to j, one column by one column
                int prefixSum = 0;
                for (int col = 1; col <= n; col++) {
                    prefixSum += colSum[j][col] - colSum[i - 1][col];
                    res += cnt[prefixSum - target];
                    cnt[prefixSum]++;
                }
            }
        }

        return res;
    }
};
// @lc code=end

