// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem435.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=435 lang=cpp
 *
 * [435] Non-overlapping Intervals
 *
 * https://leetcode.com/problems/non-overlapping-intervals/description/
 *
 * algorithms
 * Medium (48.51%)
 * Likes:    4060
 * Dislikes: 120
 * Total Accepted:    254.3K
 * Total Submissions: 524.1K
 * Testcase Example:  '[[1,2],[2,3],[3,4],[1,3]]'
 *
 * Given an array of intervals intervals where intervals[i] = [starti, endi],
 * return the minimum number of intervals you need to remove to make the rest
 * of the intervals non-overlapping.
 *
 *
 * Example 1:
 *
 *
 * Input: intervals = [[1,2],[2,3],[3,4],[1,3]]
 * Output: 1
 * Explanation: [1,3] can be removed and the rest of the intervals are
 * non-overlapping.
 *
 *
 * Example 2:
 *
 *
 * Input: intervals = [[1,2],[1,2],[1,2]]
 * Output: 2
 * Explanation: You need to remove two [1,2] to make the rest of the intervals
 * non-overlapping.
 *
 *
 * Example 3:
 *
 *
 * Input: intervals = [[1,2],[2,3]]
 * Output: 0
 * Explanation: You don't need to remove any of the intervals since they're
 * already non-overlapping.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= intervals.length <= 10^5
 * intervals[i].length == 2
 * -5 * 10^4 <= starti < endi <= 5 * 10^4
 *
 *
 */

// @lc code=start
class Solution
{
public:
    int eraseOverlapIntervals(vector<vector<int>> &intervals)
    {

        sort(intervals.begin(), intervals.end(), [](auto &a, auto &b)
             { return a[1] < b[1]; });
        int end = intervals[0][1], res = 0;
        for (int i = 1; i < intervals.size(); i++)
        {
            if (intervals[i][0] < end)
                res++;
            else
                end = intervals[i][1];
        }
        return res;
    }
};
// @lc code=end
