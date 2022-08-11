// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem57.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=57 lang=cpp
 *
 * [57] Insert Interval
 *
 * https://leetcode.com/problems/insert-interval/description/
 *
 * algorithms
 * Medium (37.47%)
 * Likes:    4875
 * Dislikes: 340
 * Total Accepted:    512.8K
 * Total Submissions: 1.4M
 * Testcase Example:  '[[1,3],[6,9]]\n[2,5]'
 *
 * You are given an array of non-overlapping intervals intervals where
 * intervals[i] = [starti, endi] represent the start and the end of the i^th
 * interval and intervals is sorted in ascending order by starti. You are also
 * given an interval newInterval = [start, end] that represents the start and
 * end of another interval.
 *
 * Insert newInterval into intervals such that intervals is still sorted in
 * ascending order by starti and intervals still does not have any overlapping
 * intervals (merge overlapping intervals if necessary).
 *
 * Return intervals after the insertion.
 *
 *
 * Example 1:
 *
 *
 * Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
 * Output: [[1,5],[6,9]]
 *
 *
 * Example 2:
 *
 *
 * Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
 * Output: [[1,2],[3,10],[12,16]]
 * Explanation: Because the new interval [4,8] overlaps with
 * [3,5],[6,7],[8,10].
 *
 *
 *
 * Constraints:
 *
 *
 * 0 <= intervals.length <= 10^4
 * intervals[i].length == 2
 * 0 <= starti <= endi <= 10^5
 * intervals is sorted by starti in ascending order.
 * newInterval.length == 2
 * 0 <= start <= end <= 10^5
 *
 *
 */

 // @lc code=start
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        int idx = 0, n = intervals.size();
        while (idx < n && intervals[idx][1] < newInterval[0])
            res.push_back(intervals[idx++]);
        if (idx < n) {
            newInterval[0] = min(intervals[idx][0], newInterval[0]);
            while (idx < n && intervals[idx][0] <= newInterval[1])
                newInterval[1] = max(intervals[idx++][1], newInterval[1]);
        }
        res.push_back(newInterval);
        while (idx < n)
            res.push_back(intervals[idx++]);
        return res;
    }
};
// @lc code=end
