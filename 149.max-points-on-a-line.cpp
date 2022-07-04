// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem149.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=149 lang=cpp
 *
 * [149] Max Points on a Line
 *
 * https://leetcode.com/problems/max-points-on-a-line/description/
 *
 * algorithms
 * Hard (20.96%)
 * Likes:    1250
 * Dislikes: 203
 * Total Accepted:    239.1K
 * Total Submissions: 1.1M
 * Testcase Example:  '[[1,1],[2,2],[3,3]]'
 *
 * Given an array of points where points[i] = [xi, yi] represents a point on
 * the X-Y plane, return the maximum number of points that lie on the same
 * straight line.
 *
 *
 * Example 1:
 *
 *
 * Input: points = [[1,1],[2,2],[3,3]]
 * Output: 3
 *
 *
 * Example 2:
 *
 *
 * Input: points = [[1,1],[3,2],[5,3],[4,1],[2,3],[1,4]]
 * Output: 4
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= points.length <= 300
 * points[i].length == 2
 * -10^4 <= xi, yi <= 10^4
 * All the points are unique.
 *
 *
 */

 // @lc code=start
class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int res = 1, dup = 0, vtc = 0;
        // <slope, count>
        unordered_map<long double, int> cnt;
        for (auto& p : points) {
            dup = 0, vtc = 0;
            cnt.clear();
            for (auto& q : points) {
                if (p == q) dup++;
                else if (p[0] == q[0]) vtc++;
                else {
                    long double k = (long double)(q[1] - p[1]) / (q[0] - p[0]);
                    cnt[k]++;
                }
            }
            for (auto [k, t] : cnt) vtc = max(vtc, t);
            res = max(res, vtc + dup);
        }
        return res;
    }
};
// @lc code=end

