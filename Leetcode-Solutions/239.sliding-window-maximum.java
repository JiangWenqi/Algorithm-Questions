import java.util.ArrayDeque;

/*
 * @lc app=leetcode id=239 lang=java
 *
 * [239] Sliding Window Maximum
 */

// @lc code=start
class Solution {
    public int[] maxSlidingWindow(int[] nums, int k) {
        int[] res = new int[nums.length - k + 1];
        Deque<Integer> deque = new LinkedList<>();
        for (int i = 0; i < nums.length; i++) {
            // 1. if first index in Q(Deque) < i-k+1
            if (!deque.isEmpty() && deque.peekFirst() == i - k) {
                deque.pollFirst();
            }
            // 2. loop: nums[i] > last element of the Q(Deque)?
            while (!deque.isEmpty() && nums[deque.peekLast()] < nums[i]) {
                deque.pollLast();
            }
            // 3. offer(i)
            deque.offerLast(i);
            // 4. if window is complete then ouput nums[peek()]
            if (i >= k - 1) {
                res[i + 1 - k] = nums[deque.peekFirst()];
            }
        }
        return res;
    }
}
// @lc code=end
