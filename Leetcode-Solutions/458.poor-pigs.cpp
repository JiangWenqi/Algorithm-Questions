/*
 * @lc app=leetcode id=458 lang=cpp
 *
 * [458] Poor Pigs
 *
 * https://leetcode.com/problems/poor-pigs/description/
 *
 * algorithms
 * Hard (55.89%)
 * Likes:    968
 * Dislikes: 1985
 * Total Accepted:    49.3K
 * Total Submissions: 79.8K
 * Testcase Example:  '1000\n15\n60'
 *
 * There are buckets buckets of liquid, where exactly one of the buckets is
 * poisonous. To figure out which one is poisonous, you feed some number of
 * (poor) pigs the liquid to see whether they will die or not. Unfortunately,
 * you only have minutesToTest minutes to determine which bucket is poisonous.
 *
 * You can feed the pigs according to these steps:
 *
 *
 * Choose some live pigs to feed.
 * For each pig, choose which buckets to feed it. The pig will consume all the
 * chosen buckets simultaneously and will take no time.
 * Wait for minutesToDie minutes. You may not feed any other pigs during this
 * time.
 * After minutesToDie minutes have passed, any pigs that have been fed the
 * poisonous bucket will die, and all others will survive.
 * Repeat this process until you run out of time.
 *
 *
 * Given buckets, minutesToDie, and minutesToTest, return the minimum number of
 * pigs needed to figure out which bucket is poisonous within the allotted
 * time.
 *
 *
 * Example 1:
 * Input: buckets = 1000, minutesToDie = 15, minutesToTest = 60
 * Output: 5
 * Example 2:
 * Input: buckets = 4, minutesToDie = 15, minutesToTest = 15
 * Output: 2
 * Example 3:
 * Input: buckets = 4, minutesToDie = 15, minutesToTest = 30
 * Output: 2
 *
 *
 * Constraints:
 *
 *
 * 1 <= buckets <= 1000
 * 1 <= minutesToDie <= minutesToTest <= 100
 *
 *
 */

 // @lc code=start
class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int k = minutesToTest / minutesToDie;
        return ceil(log(buckets) / log(k + 1));
    }
};
// @lc code=end

