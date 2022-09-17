/*
 * @lc app=leetcode id=2007 lang=cpp
 *
 * [2007] Find Original Array From Doubled Array
 *
 * https://leetcode.com/problems/find-original-array-from-doubled-array/description/
 *
 * algorithms
 * Medium (38.37%)
 * Likes:    1243
 * Dislikes: 76
 * Total Accepted:    71.9K
 * Total Submissions: 178.5K
 * Testcase Example:  '[1,3,4,2,6,8]'
 *
 * An integer array original is transformed into a doubled array changed by
 * appending twice the value of every element in original, and then randomly
 * shuffling the resulting array.
 *
 * Given an array changed, return original if changed is a doubled array. If
 * changed is not a doubled array, return an empty array. The elements in
 * original may be returned in any order.
 *
 *
 * Example 1:
 *
 *
 * Input: changed = [1,3,4,2,6,8]
 * Output: [1,3,4]
 * Explanation: One possible original array could be [1,3,4]:
 * - Twice the value of 1 is 1 * 2 = 2.
 * - Twice the value of 3 is 3 * 2 = 6.
 * - Twice the value of 4 is 4 * 2 = 8.
 * Other original arrays could be [4,3,1] or [3,1,4].
 *
 *
 * Example 2:
 *
 *
 * Input: changed = [6,3,0,1]
 * Output: []
 * Explanation: changed is not a doubled array.
 *
 *
 * Example 3:
 *
 *
 * Input: changed = [1]
 * Output: []
 * Explanation: changed is not a doubled array.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= changed.length <= 10^5
 * 0 <= changed[i] <= 10^5
 *
 *
 */

 // @lc code=start
class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        int n = changed.size();
        if (n % 2) return {};
        sort(changed.begin(), changed.end());
        unordered_map<int, int> counter;
        for (int& num : changed)
            counter[num] ++;

        vector<int> res;
        for (int& num : changed) {
            if (counter[num] == 0) continue;
            if (counter[num * 2] == 0) return {};
            res.push_back(num);
            counter[num]--;
            counter[num * 2]--;
        }

        return res;
    }
};
// @lc code=end

