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
        int slowPointer = 0, fastPointer = 0, length = 0;
        HashSet<Character> set = new HashSet<>();
        while (fastPointer < s.length()) {
            char fastChar = s.charAt(fastPointer);
            if (!set.contains(fastChar)) {
                set.add(fastChar);
                length = Math.max(length, set.size());
                fastPointer++;
            } else {
                char slowChar = s.charAt(slowPointer);
                set.remove(slowChar);
                slowPointer++;
            }
        }
        return length;
    }
}
// @lc code=end

