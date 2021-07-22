import java.util.HashMap;

/*
 * @lc app=leetcode id=387 lang=java
 *
 * [387] First Unique Character in a String
 */

// @lc code=start
class Solution {
    public int firstUniqChar(String s) {

        HashMap<Character, Integer> map = new HashMap<>();
        char[] chars = s.toCharArray();

        for (char c : chars) {
            map.put(c, map.getOrDefault(c, 0) + 1);
        }

        for (int i = 0; i < chars.length; i++) {
            if (map.get(chars[i]) == 1) {
                return i;
            }
        }w
        return -1;
    }
}
// @lc code=end
