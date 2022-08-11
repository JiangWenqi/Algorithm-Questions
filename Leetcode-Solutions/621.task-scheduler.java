import java.util.ArrayList;
import java.util.HashMap;
import java.util.PriorityQueue;

/*
 * @lc app=leetcode id=621 lang=java
 *
 * [621] Task Scheduler
 */

// @lc code=start
class Solution {
    public int leastInterval(char[] tasks, int n) {
        HashMap<Character, Integer> frequencies = new HashMap<>();
        for (char task : tasks) {
            frequencies.put(task, frequencies.getOrDefault(task, 0) + 1);
        }
        PriorityQueue<Integer> heap = new PriorityQueue<>((a, b) -> b - a);
        heap.addAll(frequencies.values());

        int slot = n + 1, time = 0;
        while (!heap.isEmpty()) {
            int workingTime = 0;
            ArrayList<Integer> unfinishedTasks = new ArrayList<>();
            for (int i = 0; i < slot; i++) {
                if (!heap.isEmpty()) {
                    unfinishedTasks.add(heap.poll() - 1);
                    workingTime++;
                }
            }
            for (Integer unfinishedTask : unfinishedTasks) {
                if (unfinishedTask > 0) {
                    heap.add(unfinishedTask);
                }
            }
            time += heap.isEmpty() ? workingTime : slot;
        }
        return time;
    }
}
// @lc code=end
