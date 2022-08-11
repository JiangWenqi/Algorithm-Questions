import java.util.Arrays;

/*
 * @lc app=leetcode id=849 lang=java
 *
 * [849] Maximize Distance to Closest Person
 */

// @lc code=start
class Solution {
    public int maxDistToClosest(int[] seats) {
        int n = seats.length;
        int[] left = new int[n], right = new int[n];
        Arrays.fill(left, n);
        Arrays.fill(right, n);

        for (int i = 0; i < n; i++) {
            if (seats[i] == 1) {
                left[i] = 0;
            } else if (i > 0) {
                left[i] = left[i - 1] + 1;
            }
        }
        for (int i = n - 1; i >= 0; i--) {
            if (seats[i] == 1) {
                right[i] = 0;
            } else if (i < n - 1) {
                right[i] = right[i + 1] + 1;
            }
        }

        int maxDist = 0;
        for (int i = 0; i < n; i++) {
            if (seats[i] == 0) {
                int closet = Math.min(left[i], right[i]);
                maxDist = Math.max(maxDist, closet);
            }
        }
        return maxDist;
    }
}
// @lc code=end
