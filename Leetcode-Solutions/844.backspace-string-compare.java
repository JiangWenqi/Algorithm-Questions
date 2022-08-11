import java.util.Stack;

/*
 * @lc app=leetcode id=844 lang=java
 *
 * [844] Backspace String Compare
 */

// @lc code=start
class Solution {
    public boolean backspaceCompare(String s, String t) {

        Stack<Character> sStack = new Stack<>();

        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '#') {
                if (!sStack.empty()) {
                    sStack.pop();
                }
            } else {
                sStack.push(s.charAt(i));
            }
        }

        Stack<Character> tStack = new Stack<>();

        for (int i = 0; i < t.length(); i++) {
            if (t.charAt(i) == '#') {
                if (!tStack.empty()) {
                    tStack.pop();
                }
            } else {
                tStack.push(t.charAt(i));
            }
        }

        if (sStack.size() != tStack.size()) {
            return false;
        } else {
            while (!sStack.isEmpty() && !tStack.isEmpty()) {
                if (sStack.pop() != tStack.pop()) {
                    return false;
                }
            }
            return true;
        }
    }
}
// @lc code=end
