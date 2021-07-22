import java.util.Arrays;

/*
 * @lc app=leetcode id=322 lang=java
 *
 * [322] Coin Change
 */

// @lc code=start
class Solution {
    public int coinChange(int[] coins, int amount) {
        Arrays.sort(coins); // 对金币做了排序, 从小到大
        int[] dp = new int[amount + 1];
        Arrays.fill(dp, amount + 1); // 所有值都置为无效[amount + 1](只要大于amount就是无效)
        dp[0] = 0;
        for (int target = 1; target <= amount; target++) {
            for (int coin : coins) {
                if (coin <= target) {
                    dp[target] = Math.min(dp[target], 1 + dp[target - coin]);
                } else {
                    break; // 如果当前金币都已经大于target了，就没有必要进行下去了
                }
            }
        }
        return dp[amount] > amount ? -1 : dp[amount];
    }
}
// @lc code=end
