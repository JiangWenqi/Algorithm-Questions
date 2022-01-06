import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;

/*
 * @lc app=leetcode id=131 lang=java
 *
 * [131] Palindrome Partitioning
 */

// @lc code=start
class Solution {
    public List<List<String>> partition(String s) {
        List<List<String>> res = new ArrayList<>();
        int length = s.length();

        boolean[][] dp = new boolean[length][length];

        for (int end = 0; end < length; end++) {
            for (int start = 0; start <= end; start++) {
                if (s.charAt(end) == s.charAt(start) && (end - start <= 1 || dp[start + 1][end - 1])) {
                    dp[start][end] = true;
                }
            }
        }

        helper(0, s, dp, new LinkedList<String>(), res);
        return res;

    }

    private void helper(int index, String s, boolean[][] dp, List<String> path, List<List<String>> res) {
        if (index == s.length()) {
            res.add(new ArrayList<>(path));
            return;
        }
        for (int i = index; i < s.length(); i++) {
            if (dp[index][i]) {
                path.add(s.substring(index, i + 1));
                helper(i + 1, s, dp, path, res);
                path.remove(path.size() - 1);
            }
        }

    }
}
// @lc code=end
