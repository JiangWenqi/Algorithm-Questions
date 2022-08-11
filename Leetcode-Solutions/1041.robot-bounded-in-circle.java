/*
 * @lc app=leetcode id=1041 lang=java
 *
 * [1041] Robot Bounded In Circle
 */

// @lc code=start
class Solution {

    private final int[][] DIRECTIONS = new int[][] {
            { 1, 0 }, // up
            { 0, 1 }, // right
            { -1, 0 }, // down
            { 0, -1 }// left
    };

    public boolean isRobotBounded(String instructions) {
        // start point
        int x = 0, y = 0;
        // default direction index is 0, means go up
        int index = 0;
        for (char instruction : instructions.toCharArray()) {
            switch (instruction) {
                case 'L':
                    // index = 3 means go left
                    index = (index + 3) % 4;
                    break;
                case 'R':
                    // index = 1 means go right
                    index = (index + 1) % 4;
                    break;
                default:
                    // move towards direction
                    x += DIRECTIONS[index][0];
                    y += DIRECTIONS[index][1];
            }
        }
        // back start point or direction is not go up
        return x == 0 && y == 0 || index != 0;
    }
}
// @lc code=end
