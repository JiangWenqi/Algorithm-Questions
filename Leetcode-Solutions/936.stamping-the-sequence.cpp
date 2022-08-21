// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem936.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=936 lang=cpp
 *
 * [936] Stamping The Sequence
 *
 * https://leetcode.com/problems/stamping-the-sequence/description/
 *
 * algorithms
 * Hard (53.85%)
 * Likes:    887
 * Dislikes: 154
 * Total Accepted:    34K
 * Total Submissions: 58.1K
 * Testcase Example:  '"abc"\n"ababc"'
 *
 * You are given two strings stamp and target. Initially, there is a string s
 * of length target.length with all s[i] == '?'.
 *
 * In one turn, you can place stamp over s and replace every letter in the s
 * with the corresponding letter from stamp.
 *
 *
 * For example, if stamp = "abc" and target = "abcba", then s is "?????"
 * initially. In one turn you can:
 *
 *
 * place stamp at index 0 of s to obtain "abc??",
 * place stamp at index 1 of s to obtain "?abc?", or
 * place stamp at index 2 of s to obtain "??abc".
 *
 * Note that stamp must be fully contained in the boundaries of s in order to
 * stamp (i.e., you cannot place stamp at index 3 of s).
 *
 *
 * We want to convert s to target using at most 10 * target.length turns.
 *
 * Return an array of the index of the left-most letter being stamped at each
 * turn. If we cannot obtain target from s within 10 * target.length turns,
 * return an empty array.
 *
 *
 * Example 1:
 *
 *
 * Input: stamp = "abc", target = "ababc"
 * Output: [0,2]
 * Explanation: Initially s = "?????".
 * - Place stamp at index 0 to get "abc??".
 * - Place stamp at index 2 to get "ababc".
 * [1,0,2] would also be accepted as an answer, as well as some other
 * answers.
 *
 *
 * Example 2:
 *
 *
 * Input: stamp = "abca", target = "aabcaca"
 * Output: [3,0,1]
 * Explanation: Initially s = "???????".
 * - Place stamp at index 3 to get "???abca".
 * - Place stamp at index 0 to get "abcabca".
 * - Place stamp at index 1 to get "aabcaca".
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= stamp.length <= target.length <= 1000
 * stamp and target consist of lowercase English letters.
 *
 *
 */

 // @lc code=start
class Solution {
private:
    bool work(int k, string& stamp, string& target) {
        if (target.substr(k, stamp.size()) == string(stamp.size(), '?')) return false;
        for (int i = 0; i < stamp.size(); i++) {
            if (target[k + i] != '?' && stamp[i] != target[k + i]) {
                return false;
            }
        }
        for (int i = 0; i < stamp.size();i++) {
            target[k + i] = '?';
        }
        return true;
    }

public:
    vector<int> movesToStamp(string stamp, string target) {
        vector<int> res;
        while (true) {
            bool flag = true;
            for (int i = 0; i + stamp.size() <= target.size(); i++) {
                if (work(i, stamp, target)) {
                    res.push_back(i);
                    flag = false;
                }
            }
            if (flag) break;
        }
        if (target != string(target.size(), '?')) return {};
        reverse(res.begin(), res.end());
        return res;
    }
};
// @lc code=end

