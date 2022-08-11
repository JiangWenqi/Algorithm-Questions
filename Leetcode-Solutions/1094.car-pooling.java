import java.util.Arrays;
import java.util.PriorityQueue;

/*
 * @lc app=leetcode id=1094 lang=java
 *
 * [1094] Car Pooling
 */

// @lc code=start
class Solution {
    public boolean carPooling(int[][] trips, int capacity) {
        // sort trips in ascending order by pick-up locations
        Arrays.sort(trips, (a, b) -> a[1] - b[1]);
        // find the first need to get off (ascending order by get off locations)
        PriorityQueue<int[]> queue = new PriorityQueue<>((a, b) -> a[1] - b[1]);

        for (int i = 0; i < trips.length; i++) {
            int passengers = trips[i][0], start = trips[i][1], end = trips[i][2];

            // if someone can get off the car, just let him go to free capacity
            while (!queue.isEmpty() && queue.peek()[1] <= start) {
                capacity += queue.poll()[0];
            }
            // check is there enough capacity to pick this guy up
            capacity -= passengers;
            if (capacity < 0) {
                return false;
            } else {
                queue.offer(new int[] { passengers, end });
            }

        }
        return true;
    }
}
// @lc code=end
