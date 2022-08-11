// @before-stub-for-debug-begin
#include <string>
#include <vector>

#include "commoncppproblem1054.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=1054 lang=cpp
 *
 * [1054] Distant Barcodes
 *
 * https://leetcode.com/problems/distant-barcodes/description/
 *
 * algorithms
 * Medium (45.29%)
 * Likes:    881
 * Dislikes: 38
 * Total Accepted:    30.9K
 * Total Submissions: 68.3K
 * Testcase Example:  '[1,1,1,2,2,2]'
 *
 * In a warehouse, there is a row of barcodes, where the i^th barcode is
 * barcodes[i].
 *
 * Rearrange the barcodes so that no two adjacent barcodes are equal. You may
 * return any answer, and it is guaranteed an answer exists.
 *
 *
 * Example 1:
 * Input: barcodes = [1,1,1,2,2,2]
 * Output: [2,1,2,1,2,1]
 * Example 2:
 * Input: barcodes = [1,1,1,1,2,2,3,3]
 * Output: [1,3,1,3,1,2,1,2]
 *
 *
 * Constraints:
 *
 *
 * 1 <= barcodes.length <= 10000
 * 1 <= barcodes[i] <= 10000
 *
 *
 */

// @lc code=start
class Solution {
 public:
  /**
   * 先计数，然后按次数从大到小错位摆放
   **/
  vector<int> rearrangeBarcodes(vector<int>& barcodes) {
    int n = barcodes.size(), idx = 0;
    // frequency
    unordered_map<int, int> kvs;
    for (int& barcode : barcodes) kvs[barcode]++;

    // sorted frequency
    vector<pair<int, int>> vks(kvs.size());
    for (auto& kv : kvs) vks[idx++] = make_pair(kv.second, kv.first);
    sort(vks.begin(), vks.end(), greater<pair<int, int>>());

    idx = 0;
    for (auto& vk : vks) {
      while (vk.first--) {
        barcodes[idx] = vk.second;
        idx += 2;
        if (idx >= n) idx = 1;
      }
    }

    return barcodes;
  }
};
// @lc code=end
