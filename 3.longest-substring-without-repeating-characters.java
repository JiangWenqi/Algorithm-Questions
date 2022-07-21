import java.util.HashMap;
import java.util.HashSet;

/*
 * @lc app=leetcode id=3 lang=java
 *
 * [3] Longest Substring Without Repeating Characters
 */

// @lc code=start
class Solution {
    public int lengthOfLongestSubstring(String s) {

        int res = 0;
        HashMap<Character, Integer> cnt = new HashMap<>();
        for (int i = 0, j = 0; i < s.length(); i++) {
            cnt.put(s.charAt(i), cnt.getOrDefault(s.charAt(i), 0) + 1);
            while (cnt.get(s.charAt(i)) > 1) {
                cnt.put(s.charAt(j), cnt.get(s.charAt(j)) > 0 ? cnt.get(s.charAt(j)) - 1 : 0);
                j++;
            }
            res = Math.max(res, i - j + 1);
        }
        return res;
    }
    /**
     * public int lengthOfLongestSubstring(String s) {
     * int slowPointer = 0, fastPointer = 0, length = 0;
     * HashSet<Character> set = new HashSet<>();
     * while (fastPointer < s.length()) {
     * char fastChar = s.charAt(fastPointer);
     * if (!set.contains(fastChar)) {
     * set.add(fastChar);
     * length = Math.max(length, set.size());
     * fastPointer++;
     * } else {
     * char slowChar = s.charAt(slowPointer);
     * set.remove(slowChar);
     * slowPointer++;
     * }
     * }
     * return length;
     * }
     */
}
// @lc code=end
