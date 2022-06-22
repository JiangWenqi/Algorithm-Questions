/*
 * @lc app=leetcode id=28 lang=java
 *
 * [28] Implement strStr()
 */

// @lc code=start
class Solution {
    public int strStr(String haystack, String needle) {
        if (needle.length() < 1)
            return 0;
        int m = needle.length(), n = haystack.length();
        char[] p = (" " + needle).toCharArray();
        char[] s = (" " + haystack).toCharArray();
        int[] next = new int[m + 10];
        // 预处理p的next数组
        // next[i]记录p[]数组中以i结尾的最大后缀等于最大前缀时的最大前缀的末尾位置
        for (int i = 2, j = 0; i <= m; i++) {
            while (j != 0 && p[i] != p[j + 1])
                j = next[j];
            if (p[i] == p[j + 1])
                j++;
            next[i] = j;
        }
        // 匹配
        for (int i = 1, j = 0; i <= n; i++) {
            while (j != 0 && s[i] != p[j + 1])
                j = next[j];
            if (s[i] == p[j + 1])
                j++;
            if (j == m) {
                j = next[j];
                return i - m;
            }
        }
        return -1;
    }
}
// @lc code=end
