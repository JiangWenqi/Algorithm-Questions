import java.util.ArrayList;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.Queue;

/*
 * @lc app=leetcode id=1345 lang=java
 *
 * [1345] Jump Game IV
 */

// @lc code=start
class Solution {
    public int minJumps(int[] arr) {
        int n = arr.length;
        if (n == 1) {
            return 0;
        }
        // number with indexes
        Map<Integer, List<Integer>> map = new HashMap<>();

        for (int i = 0; i < n; i++) {
            List<Integer> list = map.getOrDefault(arr[i], new ArrayList<>());
            list.add(i);
            map.put(arr[i], list);
        }

        // bfs
        Queue<Integer> queue = new LinkedList<>();
        // start at index 0
        queue.offer(0);
        // init steps with 0
        int steps = 0;
        while (!queue.isEmpty()) {
            steps++;
            int size = queue.size();
            for (int i = 0; i < size; i++) {
                
                int index = queue.poll();
                int number = arr[index];

                // left index
                if (index - 1 >= 0 && map.containsKey(arr[index - 1])) {
                    queue.offer(index - 1);
                }
                // right index
                if (index + 1 <= n - 1 && map.containsKey(arr[index + 1])) {
                    if (index + 1 == n - 1) {
                        return steps;
                    }
                    queue.offer(index + 1);
                }
                // other indexes with same number
                if (map.containsKey(number)) {
                    for (int sameNumberIndex : map.get(number)) {
                        if (sameNumberIndex != index) {
                            if (sameNumberIndex == n - 1) {
                                return steps;
                            }
                            queue.offer(sameNumberIndex);
                        }
                    }
                }
                map.remove(number);
            }

        }
        return steps;

    }
}
// @lc code=end
