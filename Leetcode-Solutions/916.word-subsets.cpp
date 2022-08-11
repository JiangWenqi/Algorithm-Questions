// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem916.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=916 lang=cpp
 *
 * [916] Word Subsets
 *
 * https://leetcode.com/problems/word-subsets/description/
 *
 * algorithms
 * Medium (52.32%)
 * Likes:    1654
 * Dislikes: 160
 * Total Accepted:    70.4K
 * Total Submissions: 132.5K
 * Testcase Example:  '["amazon","apple","facebook","google","leetcode"]\n["e","o"]'
 *
 * You are given two string arrays words1 and words2.
 *
 * A string b is a subset of string a if every letter in b occurs in a
 * including multiplicity.
 *
 *
 * For example, "wrr" is a subset of "warrior" but is not a subset of
 * "world".
 *
 *
 * A string a from words1 is universal if for every string b in words2, b is a
 * subset of a.
 *
 * Return an array of all the universal strings in words1. You may return the
 * answer in any order.
 *
 *
 * Example 1:
 *
 *
 * Input: words1 = ["amazon","apple","facebook","google","leetcode"], words2 =
 * ["e","o"]
 * Output: ["facebook","google","leetcode"]
 *
 *
 * Example 2:
 *
 *
 * Input: words1 = ["amazon","apple","facebook","google","leetcode"], words2 =
 * ["l","e"]
 * Output: ["apple","google","leetcode"]
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= words1.length, words2.length <= 10^4
 * 1 <= words1[i].length, words2[i].length <= 10
 * words1[i] and words2[i] consist only of lowercase English letters.
 * All the strings of words1 are unique.
 *
 *
 */

 // @lc code=start
class Solution {
private:
    bool check(string& word, unordered_map<char, int>& cnt) {
        int match = 0;
        unordered_map<char, int> frq;
        for (char& c : word) {
            frq[c]++;
            if (cnt.count(c) && frq[c] == cnt[c]) match++;
            if (match == cnt.size()) return true;
        }
        return false;
    }
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string> res;
        unordered_map<char, int> cnt;
        // get the max count for each char
        for (auto& word : words2) {
            unordered_map<char, int> tmp;
            for (auto& c : word) tmp[c] ++;
            for (auto& kv : tmp) {
                cnt[kv.first] = max(cnt[kv.first], kv.second);
            }
        }
        // compare
        for (auto& word : words1) {
            if (check(word, cnt)) res.push_back(word);
        }
        return res;
    }
};
// @lc code=end

