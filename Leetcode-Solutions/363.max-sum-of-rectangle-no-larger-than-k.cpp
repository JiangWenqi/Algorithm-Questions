// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem363.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=363 lang=cpp
 *
 * [363] Max Sum of Rectangle No Larger Than K
 *
 * https://leetcode.com/problems/max-sum-of-rectangle-no-larger-than-k/description/
 *
 * algorithms
 * Hard (40.25%)
 * Likes:    2918
 * Dislikes: 147
 * Total Accepted:    108.1K
 * Total Submissions: 246.9K
 * Testcase Example:  '[[1,0,1],[0,-2,3]]\n2'
 *
 * Given an m x n matrix matrix and an integer k, return the max sum of a
 * rectangle in the matrix such that its sum is no larger than k.
 * 
 * It is guaranteed that there will be a rectangle with a sum no larger than
 * k.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: matrix = [[1,0,1],[0,-2,3]], k = 2
 * Output: 2
 * Explanation: Because the sum of the blue rectangle [[0, 1], [-2, 3]] is 2,
 * and 2 is the max number no larger than k (k = 2).
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: matrix = [[2,2,-1]], k = 3
 * Output: 3
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * m == matrix.length
 * n == matrix[i].length
 * 1 <= m, n <= 100
 * -100 <= matrix[i][j] <= 100
 * -10^5 <= k <= 10^5
 * 
 * 
 * 
 * Follow up: What if the number of rows is much larger than the number of
 * columns?
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> s;

    int get(int x1, int y1, int x2, int y2) {
        return s[x2][y2] - s[x1 - 1][y2] - s[x2][y1 - 1] + s[x1 - 1][y1 - 1];
    }

    int maxSumSubmatrix(vector<vector<int>>& w, int K) {
        int n = w.size(), m = w[0].size();
        s = vector<vector<int>>(n + 1, vector<int>(m + 1));
        for (int i = 1; i <= n; i ++ )
            for (int j = 1; j <= m; j ++ )
                s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + w[i - 1][j - 1];

        int res = INT_MIN;
        for (int i = 1; i <= m; i ++ )
            for (int j = i; j <= m; j ++ ) {
                set<int> S;
                S.insert(0);
                for (int k = 1; k <= n; k ++ ) {
                    int si = get(1, i, k, j);
                    auto it = S.lower_bound(si - K);
                    if (it != S.end()) res = max(res, si - *it);
                    S.insert(si);
                }
            }

        return res;
    }
};

// @lc code=end

