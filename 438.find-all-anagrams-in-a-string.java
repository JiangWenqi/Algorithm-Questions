import java.util.ArrayList;
import java.util.Arrays;

import java.util.List;

/*
 * @lc app=leetcode id=438 lang=java
 *
 * [438] Find All Anagrams in a String
 */

// @lc code=start
class Solution {
    public List<Integer> findAnagrams(String s, String p) {

        List<Integer> result = new ArrayList<>();

        char[] target = new char[26];
        for (int i = 0; i < p.length(); i++) {
            target[p.charAt(i) - 'a']++;
        }
        char[] window = new char[26];
        int start = 0, end = 0;

        while (end < s.length()) {
            window[s.charAt(end) - 'a']++;
            if (end - start + 1 == p.length()) {
                if (Arrays.equals(window, target)) {
                    result.add(start);
                }
                window[s.charAt(start) - 'a']--;
                start++;
            }
            end++;
        }

        return result;
    }

}
// @lc code=end
