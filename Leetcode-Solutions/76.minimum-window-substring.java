/*
 * @lc app=leetcode id=76 lang=java
 *
 * [76] Minimum Window Substring
 */

// @lc code=start
class Solution {
    public String minWindow(String s, String t) {
        // 初始化 targets
        int[] targets = new int[128];
        for (int i = 0; i < t.length(); i++) {
            targets[t.charAt(i)]++;
        }
        int count = t.length();

        // 最小窗口相关
        int minStart = 0, miniLength = Integer.MAX_VALUE;

        for (int left = 0, right = 0; right < s.length(); right++) {
            char rightChar = s.charAt(right);
            // 如果当前字符在目标字符串中存在, 那么count就减1
            if (targets[rightChar] > 0) {
                count--;
            }

            targets[rightChar]--;
            // 如果完全匹配, 那就要挪左边的指针了
            while (count == 0) {
                char leftChar = s.charAt(left);
                targets[leftChar]++;
                if (targets[leftChar] > 0) {
                    if (right - left + 1 < miniLength) {
                        minStart = left;
                        miniLength = right - left + 1;
                    }
                    count++;
                }
                left++;
            }
        }
        return miniLength == Integer.MAX_VALUE ? "" : s.substring(minStart, minStart + miniLength);
    }
}
// @lc code=end
