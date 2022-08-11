import java.util.Arrays;
import java.util.HashMap;

/*
 * @lc app=leetcode id=1590 lang=java
 *
 * [1590] Make Sum Divisible by P
 */

// @lc code=start
class Solution {
    public int minSubarray(int[] nums, int p) {
        int ans = Integer.MAX_VALUE;
        long sum = 0;
        for (int num : nums) {
            sum += num;
        }
        // 用 reminder 存储 和 的余数
        long reminder = sum % p;
        // 如果 余数 为零，就说明整个数组的和是能被整除的！
        if (reminder == 0) {
            return 0;
        }

        HashMap<Long, Integer> map = new HashMap<>();
        // 把 0 设置为 -1，因为数组起始坐标为0！
        map.put(0L, -1);
        // sum存储的是 nums[0] 到 nums[i]的和，也就是前缀和
        long preSum = 0;
        for (int i = 0; i < nums.length; i++) {
            preSum += nums[i];
            // 求出 前缀和 对 p 取余!
            long counter = preSum % p;
            // 求出目标的前缀和
            long aimNum = (counter - reminder + p) % p;
            if (map.containsKey(aimNum)) {
                ans = Math.min(ans, i - map.get(aimNum));
            }
            // 将当前位置的前缀和存储map中！
            map.put(counter, i);
        }
        return ans >= nums.length ? -1 : ans;
    }
}
// @lc code=end
