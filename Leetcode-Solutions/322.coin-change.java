import java.util.Arrays;

/*
 * @lc app=leetcode id=322 lang=java
 *
 * [322] Coin Change
 */

// @lc code=start
class Solution {
    public int coinChange(int[] coins, int amount) {
        int[] f = new int[amount + 1];
        Arrays.fill(f, amount + 1);
        f[0] = 0;
        for (int coin : coins) {
            for (int i = coin; i <= amount; i++) {
                f[i] = Math.min(f[i], f[i - coin] + 1);
            }
        }
        return f[amount] > amount ? -1 : f[amount];
    }
}
// @lc code=end
