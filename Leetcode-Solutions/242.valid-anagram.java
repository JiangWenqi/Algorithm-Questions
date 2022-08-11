import java.util.HashMap;

/*
 * @lc app=leetcode id=242 lang=java
 *
 * [242] Valid Anagram
 */

// @lc code=start
class Solution {
    public boolean isAnagram(String s, String t) {
        HashMap<Character, Integer> map = new HashMap<>();
        for (char c : t.toCharArray()) {
            map.put(c, map.getOrDefault(c, 0) + 1);
        }

        for (char c : s.toCharArray()) {
            if (!map.containsKey(c) || map.get(c) <= 0) {
                return false;
            } else {
                map.put(c, map.get(c) - 1);
            }
        }

        for (int count : map.values()) {
            if (count > 0) {
                return false;
            }
        }
        return true;
    }
}
// @lc code=end
