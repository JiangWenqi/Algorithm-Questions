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
        Arrays.sort(trips, (a, b) -> a[1] - b[1]);
        PriorityQueue<int[]> queue = new PriorityQueue<>((a, b) -> a[1] - b[1]);

        for (int[] trip : trips) {
            int passenger = trip[0], start = trip[1], end = trip[2];
            while (!queue.isEmpty() && queue.peek()[1] <= start) {
                capacity += (queue.poll()[0]);
            }
            capacity -= passenger;
            if (capacity < 0) {
                return false;
            } else {
                queue.offer(new int[] { passenger, end });
            }
        }
        return true;
    }
}
// @lc code=end
