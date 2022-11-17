/*
 * @lc app=leetcode id=223 lang=cpp
 *
 * [223] Rectangle Area
 *
 * https://leetcode.com/problems/rectangle-area/description/
 *
 * algorithms
 * Medium (40.92%)
 * Likes:    1300
 * Dislikes: 1340
 * Total Accepted:    166.9K
 * Total Submissions: 388.3K
 * Testcase Example:  '-3\n0\n3\n4\n0\n-1\n9\n2'
 *
 * Given the coordinates of two rectilinear rectangles in a 2D plane, return
 * the total area covered by the two rectangles.
 *
 * The first rectangle is defined by its bottom-left corner (ax1, ay1) and its
 * top-right corner (ax2, ay2).
 *
 * The second rectangle is defined by its bottom-left corner (bx1, by1) and its
 * top-right corner (bx2, by2).
 *
 *
 * Example 1:
 *
 *
 * Input: ax1 = -3, ay1 = 0, ax2 = 3, ay2 = 4, bx1 = 0, by1 = -1, bx2 = 9, by2
 * = 2
 * Output: 45
 *
 *
 * Example 2:
 *
 *
 * Input: ax1 = -2, ay1 = -2, ax2 = 2, ay2 = 2, bx1 = -2, by1 = -2, bx2 = 2,
 * by2 = 2
 * Output: 16
 *
 *
 *
 * Constraints:
 *
 *
 * -10^4 <= ax1 <= ax2 <= 10^4
 * -10^4 <= ay1 <= ay2 <= 10^4
 * -10^4 <= bx1 <= bx2 <= 10^4
 * -10^4 <= by1 <= by2 <= 10^4
 *
 *
 */

// @lc code=start
class Solution
{
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2)
    {
        long long x = min(ax2, bx2) - max(ax1, bx1);
        long long y = min(ay2, by2) - max(ay1, by1);

        long long a = (ax2 - ax1) * (ay2 - ay1), b = (bx2 - bx1) * (by2 - by1);
        return a + b - max(x, 0ll) * max(y, 0ll);
    }
};
// @lc code=end
