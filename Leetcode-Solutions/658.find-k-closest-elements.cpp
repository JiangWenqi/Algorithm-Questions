// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem658.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=658 lang=cpp
 *
 * [658] Find K Closest Elements
 *
 * https://leetcode.com/problems/find-k-closest-elements/description/
 *
 * algorithms
 * Medium (45.03%)
 * Likes:    4966
 * Dislikes: 451
 * Total Accepted:    320.5K
 * Total Submissions: 711.7K
 * Testcase Example:  '[1,2,3,4,5]\n4\n3'
 *
 * Given a sorted integer array arr, two integers k and x, return the k closest
 * integers to x in the array. The result should also be sorted in ascending
 * order.
 *
 * An integer a is closer to x than an integer b if:
 *
 *
 * |a - x| < |b - x|, or
 * |a - x| == |b - x| and a < b
 *
 *
 *
 * Example 1:
 * Input: arr = [1,2,3,4,5], k = 4, x = 3
 * Output: [1,2,3,4]
 * Example 2:
 * Input: arr = [1,2,3,4,5], k = 4, x = -1
 * Output: [1,2,3,4]
 *
 *
 * Constraints:
 *
 *
 * 1 <= k <= arr.length
 * 1 <= arr.length <= 10^4
 * arr is sorted in ascending order.
 * -10^4 <= arr[i], x <= 10^4
 *
 *
 */

 // @lc code=start
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> res;
        priority_queue<pair<int, int>> pq;
        for (int i = 0; i < arr.size();i++) {
            int dis = abs(arr[i] - x);
            pq.push(make_pair(dis, i));
            if (pq.size() > k) pq.pop();
        }
        while (!pq.empty()) {
            res.push_back(arr[pq.top().second]);
            pq.pop();
        }
        sort(res.begin(), res.end());
        return res;
    }
};
// @lc code=end

