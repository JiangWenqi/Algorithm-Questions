import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.PriorityQueue;

/*
 * @lc app=leetcode id=658 lang=java
 *
 * [658] Find K Closest Elements
 *
 * https://leetcode.com/problems/find-k-closest-elements/description/
 *
 * algorithms
 * Medium (45.81%)
 * Likes:    5479
 * Dislikes: 482
 * Total Accepted:    346.8K
 * Total Submissions: 757.3K
 * Testcase Example:  '[1,2,3,4,5]\n4\n3'
 *
 * Given a sorted integer array arr, two integers k and x, return the k closest
 * integers to x in the array. The result should also be sorted in ascending
 * order.
 * 
 * An integer a is closer to x than an integer b if:
 * 
 * 
 * |a - x| < |b - x|, or
 * |a - x| == |b - x| and a < b
 * 
 * 
 * 
 * Example 1:
 * Input: arr = [1,2,3,4,5], k = 4, x = 3
 * Output: [1,2,3,4]
 * Example 2:
 * Input: arr = [1,2,3,4,5], k = 4, x = -1
 * Output: [1,2,3,4]
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= k <= arr.length
 * 1 <= arr.length <= 10^4
 * arr is sorted in ascending order.
 * -10^4 <= arr[i], x <= 10^4
 * 
 * 
 */

// @lc code=start
class Solution {
    public List<Integer> findClosestElements(int[] arr, int k, int x) {
        // Descending Order
        PriorityQueue<Integer> pq = new PriorityQueue<>((a, b) -> {
            int da = Math.abs(a - x);
            int db = Math.abs(b - x);
            if (da != db)
                return db - da;
            else
                return b - a;
        });
        for (int num : arr) {
            pq.offer(num);
            if (pq.size() > k)
                pq.poll();
        }
        List<Integer> res = new ArrayList<>(k);
        while (!pq.isEmpty()) {
            res.add(pq.poll());
        }
        Collections.sort(res);
        return res;
    }
}
// @lc code=end
