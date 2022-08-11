import java.util.HashMap;

/*
 * @lc app=leetcode id=290 lang=java
 *
 * [290] Word Pattern
 */

// @lc code=start
class Solution {
    public boolean wordPattern(String pattern, String s) {
        String[] words = s.split(" ");
        if (words.length != pattern.length()) {
            return false;
        }
        HashMap<Character, String> map = new HashMap<>();

        for (int i = 0; i < words.length; i++) {
            char c = pattern.charAt(i);
            String w = words[i];
            if (map.containsKey(c)) {
                if (!map.get(c).equals(w)) {
                    return false;
                }
            } else {
                if (map.containsValue(w)) {
                    return false;
                }
                map.put(c, w);
            }
        }

        return true;
    }
}
// @lc code=end
