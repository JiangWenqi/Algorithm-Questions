/*
 * @lc app=leetcode id=218 lang=cpp
 *
 * [218] The Skyline Problem
 *
 * https://leetcode.com/problems/the-skyline-problem/description/
 *
 * algorithms
 * Hard (39.39%)
 * Likes:    4550
 * Dislikes: 227
 * Total Accepted:    229.7K
 * Total Submissions: 572.1K
 * Testcase Example:  '[[2,9,10],[3,7,15],[5,12,12],[15,20,10],[19,24,8]]'
 *
 * A city's skyline is the outer contour of the silhouette formed by all the
 * buildings in that city when viewed from a distance. Given the locations and
 * heights of all the buildings, return the skyline formed by these buildings
 * collectively.
 *
 * The geometric information of each building is given in the array buildings
 * where buildings[i] = [lefti, righti, heighti]:
 *
 *
 * lefti is the x coordinate of the left edge of the i^th building.
 * righti is the x coordinate of the right edge of the i^th building.
 * heighti is the height of the i^th building.
 *
 *
 * You may assume all buildings are perfect rectangles grounded on an
 * absolutely flat surface at height 0.
 *
 * The skyline should be represented as a list of "key points" sorted by their
 * x-coordinate in the form [[x1,y1],[x2,y2],...]. Each key point is the left
 * endpoint of some horizontal segment in the skyline except the last point in
 * the list, which always has a y-coordinate 0 and is used to mark the
 * skyline's termination where the rightmost building ends. Any ground between
 * the leftmost and rightmost buildings should be part of the skyline's
 * contour.
 *
 * Note: There must be no consecutive horizontal lines of equal height in the
 * output skyline. For instance, [...,[2 3],[4 5],[7 5],[11 5],[12 7],...] is
 * not acceptable; the three lines of height 5 should be merged into one in the
 * final output as such: [...,[2 3],[4 5],[12 7],...]
 *
 *
 * Example 1:
 *
 *
 * Input: buildings = [[2,9,10],[3,7,15],[5,12,12],[15,20,10],[19,24,8]]
 * Output: [[2,10],[3,15],[7,12],[12,0],[15,10],[20,8],[24,0]]
 * Explanation:
 * Figure A shows the buildings of the input.
 * Figure B shows the skyline formed by those buildings. The red points in
 * figure B represent the key points in the output list.
 *
 *
 * Example 2:
 *
 *
 * Input: buildings = [[0,2,3],[2,5,3]]
 * Output: [[0,3],[5,0]]
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= buildings.length <= 10^4
 * 0 <= lefti < righti <= 2^31 - 1
 * 1 <= heighti <= 2^31 - 1
 * buildings is sorted by lefti in non-decreasing order.
 *
 *
 */

 // @lc code=start
class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int>> res;
        multiset<pair<int, int>> events;
        multiset<int> height;
        height.insert(0);
        int n = buildings.size();
        for (int i = 0; i < n; i++) {
            events.insert(make_pair(buildings[i][0], -buildings[i][2]));
            events.insert(make_pair(buildings[i][1], buildings[i][2]));
        }
        for (auto event : events) {
            if (event.second < 0) {
                if (-event.second > *height.rbegin())
                    res.push_back({ event.first, -event.second });
                height.insert(-event.second);
            } else {
                height.erase(height.find(event.second));
                if (event.second > *height.rbegin())
                    res.push_back({ event.first, *height.rbegin() });
            }
        }
        return res;
    }
};
// @lc code=end

