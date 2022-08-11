import java.util.HashMap;
import java.util.PriorityQueue;

/*
 * @lc app=leetcode id=347 lang=java
 *
 * [347] Top K Frequent Elements
 */

// @lc code=start
class Solution {
    public int[] topKFrequent(int[] nums, int k) {
        HashMap<Integer, Integer> map = new HashMap<>();
        for (int i = 0; i < nums.length; i++) {
            int number = nums[i];
            map.put(number, map.getOrDefault(number, 0) + 1);
        }

        PriorityQueue<int[]> queue = new PriorityQueue<>((a, b) -> b[1] - a[1]);
        for (int number : map.keySet()) {
            int frequent = map.get(number);
            queue.offer(new int[] { number, frequent });
        }

        int[] ans = new int[k];
        for (int i = 0; i < k; i++) {
            int number = queue.poll()[0];
            ans[i] = number;
        }
        return ans;
    }

}
// @lc code=end
