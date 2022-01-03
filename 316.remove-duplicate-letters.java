
import java.util.HashSet;

import java.util.Stack;

/*
 * @lc app=leetcode id=316 lang=java
 *
 * [316] Remove Duplicate Letters
 */

// @lc code=start
class Solution {

    public String removeDuplicateLetters(String s) {
        Stack<Character> stack = new Stack<>();
        int[] freq = new int[26];
        boolean[] added = new boolean[26];
        for (char c : s.toCharArray()) {
            freq[c - 'a']++;
        }

        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            freq[c - 'a']--;
            if (added[c - 'a']) {
                continue;
            }
            while (!stack.isEmpty() && stack.peek() > c && freq[stack.peek() - 'a'] > 0) {
                added[stack.pop() - 'a'] = false;
            }
            stack.push(c);
            added[c - 'a'] = true;
        }
        StringBuilder ans = new StringBuilder();
        for (char c : stack) {
            ans.append(c);
        }
        return ans.toString();
    }
}
// @lc code=end
