// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem30.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=30 lang=cpp
 *
 * [30] Substring with Concatenation of All Words
 *
 * https://leetcode.com/problems/substring-with-concatenation-of-all-words/description/
 *
 * algorithms
 * Hard (29.70%)
 * Likes:    2794
 * Dislikes: 2107
 * Total Accepted:    290.1K
 * Total Submissions: 977.4K
 * Testcase Example:  '"barfoothefoobarman"\n["foo","bar"]'
 *
 * You are given a string s and an array of strings words of the same length.
 * Return all starting indices of substring(s) in s that is a concatenation of
 * each word in words exactly once, in any order, and without any intervening
 * characters.
 *
 * You can return the answer in any order.
 *
 *
 * Example 1:
 *
 *
 * Input: s = "barfoothefoobarman", words = ["foo","bar"]
 * Output: [0,9]
 * Explanation: Substrings starting at index 0 and 9 are "barfoo" and "foobar"
 * respectively.
 * The output order does not matter, returning [9,0] is fine too.
 *
 *
 * Example 2:
 *
 *
 * Input: s = "wordgoodgoodgoodbestword", words = ["word","good","best","word"]
 * Output: []
 *
 *
 * Example 3:
 *
 *
 * Input: s = "barfoofoobarthefoobarman", words = ["bar","foo","the"]
 * Output: [6,9,12]
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 10^4
 * 1 <= words.length <= 5000
 * 1 <= words[i].length <= 30
 * s and words[i] consist of lowercase English letters.
 *
 *
 */

 // @lc code=start
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        if (words.empty()) return res;
        int m = words.size(), w = words[0].size(), mw = m * w, cnt = 0;
        unordered_map<string, int> wf, wd;
        for (auto& word : words) wf[word]++;
        for (int i = 0; i < w; i++) {
            for (int j = i; j + w <= s.size(); j += w) {
                if (j >= i + mw) {
                    string word = s.substr(j - mw, w);
                    wd[word]--;
                    if (wd[word] < wf[word]) cnt--;
                }
                string word = s.substr(j, w);
                wd[word]++;
                if (wd[word] <= wf[word]) cnt++;
                if (cnt == m) res.push_back(j - (m - 1) * w);
            }
            wd.clear();
            cnt = 0;
        }
        return res;
    }
};
// @lc code=end

