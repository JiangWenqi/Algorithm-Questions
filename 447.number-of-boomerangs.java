import java.util.HashMap;

/*
 * @lc app=leetcode id=447 lang=java
 *
 * [447] Number of Boomerangs
 */

// @lc code=start
class Solution {
    public int numberOfBoomerangs(int[][] points) {
        int result = 0;
        HashMap<Integer, Integer> map = new HashMap<>();
        for (int i = 0; i < points.length; i++) {
            for (int j = 0; j < points.length; j++) {
                if (i == j) {
                    continue;
                }
                int dx = points[i][0] - points[j][0];
                int dy = points[i][1] - points[j][1];
                int distance = dx * dx + dy * dy;
                map.put(distance, map.getOrDefault(distance, 0) + 1);
            }
            for (int number : map.values()) {
                result += number * (number - 1);
            }
            map.clear();
        }
        return result;
    }
}
// @lc code=end

