import java.util.Arrays;
import java.util.HashMap;

/*
 * @lc app=leetcode id=464 lang=java
 *
 * [464] Can I Win
 */

// @lc code=start
class Solution {
    HashMap<String, Boolean> map = new HashMap<>();

    public boolean canIWin(int maxChoosableInteger, int desiredTotal) {

        if (desiredTotal <= 0)
            return true;
        if ((1 + maxChoosableInteger) * maxChoosableInteger / 2 < desiredTotal)
            return false;

        char[] state = new char[maxChoosableInteger + 1];
        Arrays.fill(state, '0');
        return backtracking(state, maxChoosableInteger, desiredTotal);

    }

    private boolean backtracking(char[] state, int maxChoosableInteger, int desiredTotal) {
        String key = new String(state);

        if (map.containsKey(key))
            return map.get(key);

        for (int i = 1; i <= maxChoosableInteger; i++) {
            if (state[i] == '1')
                continue;
            // 标记当前数字已经使用过
            state[i] = '1';

            // 如果我赢了，或者对手输了
            if (desiredTotal <= i || !backtracking(state, maxChoosableInteger, desiredTotal - i)) {
                map.put(key, true);
                state[i] = '0';
                return true;
            }

            state[i] = '0';
        }

        map.put(key, false);
        return false;

    }

}
// @lc code=end
