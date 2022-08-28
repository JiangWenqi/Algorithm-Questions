import java.util.Stack;

/*
 * @lc app=leetcode id=739 lang=java
 *
 * [739] Daily Temperatures
 *
 * https://leetcode.com/problems/daily-temperatures/description/
 *
 * algorithms
 * Medium (67.72%)
 * Likes:    7951
 * Dislikes: 172
 * Total Accepted:    451.6K
 * Total Submissions: 666.8K
 * Testcase Example:  '[73,74,75,71,69,72,76,73]'
 *
 * Given an array of integers temperatures represents the daily temperatures,
 * return an array answer such that answer[i] is the number of days you have to
 * wait after the i^th day to get a warmer temperature. If there is no future
 * day for which this is possible, keep answer[i] == 0 instead.
 * 
 * 
 * Example 1:
 * Input: temperatures = [73,74,75,71,69,72,76,73]
 * Output: [1,1,4,2,1,1,0,0]
 * Example 2:
 * Input: temperatures = [30,40,50,60]
 * Output: [1,1,1,0]
 * Example 3:
 * Input: temperatures = [30,60,90]
 * Output: [1,1,0]
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= temperatures.length <= 10^5
 * 30 <= temperatures[i] <= 100
 * 
 * 
 */

// @lc code=start
class Solution {
    public int[] dailyTemperatures(int[] temperatures) {
        int n = temperatures.length;
        int[] res = new int[n];
        Stack<Integer> stk = new Stack<>();
        for (int i = n - 1; i >= 0; i--) {
            while (!stk.empty() && temperatures[stk.peek()] <= temperatures[i])
                stk.pop();
            if (!stk.empty())
                res[i] = stk.peek() - i;
            stk.push(i);
        }
        return res;
    }
}
// @lc code=end
