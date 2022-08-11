/*
 * @lc app=leetcode id=1354 lang=cpp
 *
 * [1354] Construct Target Array With Multiple Sums
 *
 * https://leetcode.com/problems/construct-target-array-with-multiple-sums/description/
 *
 * algorithms
 * Hard (31.19%)
 * Likes:    1279
 * Dislikes: 100
 * Total Accepted:    40.4K
 * Total Submissions: 119.3K
 * Testcase Example:  '[9,3,5]'
 *
 * You are given an array target of n integers. From a starting array arr
 * consisting of n 1's, you may perform the following procedure :
 *
 *
 * let x be the sum of all elements currently in your array.
 * choose index i, such that 0 <= i < n and set the value of arr at index i to
 * x.
 * You may repeat this procedure as many times as needed.
 *
 *
 * Return true if it is possible to construct the target array from arr,
 * otherwise, return false.
 *
 *
 * Example 1:
 *
 *
 * Input: target = [9,3,5]
 * Output: true
 * Explanation: Start with arr = [1, 1, 1]
 * [1, 1, 1], sum = 3 choose index 1
 * [1, 3, 1], sum = 5 choose index 2
 * [1, 3, 5], sum = 9 choose index 0
 * [9, 3, 5] Done
 *
 *
 * Example 2:
 *
 *
 * Input: target = [1,1,1,2]
 * Output: false
 * Explanation: Impossible to create target array from [1,1,1,1].
 *
 *
 * Example 3:
 *
 *
 * Input: target = [8,5]
 * Output: true
 *
 *
 *
 * Constraints:
 *
 *
 * n == target.length
 * 1 <= n <= 5 * 10^4
 * 1 <= target[i] <= 10^9
 *
 *
 */

// @lc code=start
class Solution {
 public:
  bool isPossible(vector<int>& target) {
    priority_queue<int> pq;
    unsigned int sum = 0;
    for (int num : target) sum += num, pq.push(num);
    while (true) {
      int num = pq.top();
      if (num == 1) return true;
      pq.pop();
      sum -= num;
      if (sum == 1)
        return true;
      else if (sum == 0 || sum >= num)
        return false;
      int r = num % sum;
      if (r == 0) return false;
      pq.push(r);
      sum += r;
    }
    return true;
  }
};
// @lc code=end
