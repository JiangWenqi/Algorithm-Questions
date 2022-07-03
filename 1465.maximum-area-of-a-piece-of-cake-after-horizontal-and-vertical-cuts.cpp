/*
 * @lc app=leetcode id=1465 lang=cpp
 *
 * [1465] Maximum Area of a Piece of Cake After Horizontal and Vertical Cuts
 *
 * https://leetcode.com/problems/maximum-area-of-a-piece-of-cake-after-horizontal-and-vertical-cuts/description/
 *
 * algorithms
 * Medium (37.23%)
 * Likes:    1667
 * Dislikes: 277
 * Total Accepted:    116.8K
 * Total Submissions: 298.9K
 * Testcase Example:  '5\n4\n[1,2,4]\n[1,3]'
 *
 * You are given a rectangular cake of size h x w and two arrays of integers
 * horizontalCuts and verticalCuts where:
 *
 *
 * horizontalCuts[i] is the distance from the top of the rectangular cake to
 * the i^th horizontal cut and similarly, and
 * verticalCuts[j] is the distance from the left of the rectangular cake to the
 * j^th vertical cut.
 *
 *
 * Return the maximum area of a piece of cake after you cut at each horizontal
 * and vertical position provided in the arrays horizontalCuts and
 * verticalCuts. Since the answer can be a large number, return this modulo
 * 10^9 + 7.
 *
 *
 * Example 1:
 *
 *
 * Input: h = 5, w = 4, horizontalCuts = [1,2,4], verticalCuts = [1,3]
 * Output: 4
 * Explanation: The figure above represents the given rectangular cake. Red
 * lines are the horizontal and vertical cuts. After you cut the cake, the
 * green piece of cake has the maximum area.
 *
 *
 * Example 2:
 *
 *
 * Input: h = 5, w = 4, horizontalCuts = [3,1], verticalCuts = [1]
 * Output: 6
 * Explanation: The figure above represents the given rectangular cake. Red
 * lines are the horizontal and vertical cuts. After you cut the cake, the
 * green and yellow pieces of cake have the maximum area.
 *
 *
 * Example 3:
 *
 *
 * Input: h = 5, w = 4, horizontalCuts = [3], verticalCuts = [3]
 * Output: 9
 *
 *
 *
 * Constraints:
 *
 *
 * 2 <= h, w <= 10^9
 * 1 <= horizontalCuts.length <= min(h - 1, 10^5)
 * 1 <= verticalCuts.length <= min(w - 1, 10^5)
 * 1 <= horizontalCuts[i] < h
 * 1 <= verticalCuts[i] < w
 * All the elements in horizontalCuts are distinct.
 * All the elements in verticalCuts are distinct.
 *
 *
 */

 // @lc code=start
class Solution {
public:
    long M = 1e9 + 7;
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        horizontalCuts.insert(horizontalCuts.begin(), 0);
        verticalCuts.insert(verticalCuts.begin(), 0);
        horizontalCuts.push_back(h);
        verticalCuts.push_back(w);
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        int length = 0, width = 0;
        for (int i = 1; i < horizontalCuts.size(); i++)
            length = max(horizontalCuts[i] - horizontalCuts[i - 1], length);

        for (int i = 1; i < verticalCuts.size(); i++)
            width = max(verticalCuts[i] - verticalCuts[i - 1], width);

        return ((long)length * width) % M;
    }
};
// @lc code=end

