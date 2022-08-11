import java.util.HashMap;
import java.util.LinkedList;

/*
 * @lc app=leetcode id=350 lang=java
 *
 * [350] Intersection of Two Arrays II
 */

// @lc code=start
class Solution {
    public int[] intersect(int[] nums1, int[] nums2) {
        HashMap<Integer, Integer> map = new HashMap<>();
        LinkedList<Integer> sameNumber = new LinkedList<>();

        for (int num : nums1) {
            map.put(num, map.getOrDefault(num, 0) + 1);
        }

        for (int num : nums2) {
            if (map.containsKey(num) && map.get(num) > 0) {
                sameNumber.add(num);
                map.put(num, map.get(num) - 1);
            }
        }

        int[] ans = new int[sameNumber.size()];
        for (int i = 0; i < sameNumber.size(); i++) {
            ans[i] = sameNumber.get(i);
        }
        return ans;
    }
}
// @lc code=end
