// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem890.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=890 lang=cpp
 *
 * [890] Find and Replace Pattern
 *
 * https://leetcode.com/problems/find-and-replace-pattern/description/
 *
 * algorithms
 * Medium (75.59%)
 * Likes:    2413
 * Dislikes: 131
 * Total Accepted:    117.3K
 * Total Submissions: 153.2K
 * Testcase Example:  '["abc","deq","mee","aqq","dkd","ccc"]\n"abb"'
 *
 * Given a list of strings words and a string pattern, return a list of
 * words[i] that match pattern. You may return the answer in any order.
 *
 * A word matches the pattern if there exists a permutation of letters p so
 * that after replacing every letter x in the pattern with p(x), we get the
 * desired word.
 *
 * Recall that a permutation of letters is a bijection from letters to letters:
 * every letter maps to another letter, and no two letters map to the same
 * letter.
 *
 *
 * Example 1:
 *
 *
 * Input: words = ["abc","deq","mee","aqq","dkd","ccc"], pattern = "abb"
 * Output: ["mee","aqq"]
 * Explanation: "mee" matches the pattern because there is a permutation {a ->
 * m, b -> e, ...}.
 * "ccc" does not match the pattern because {a -> c, b -> c, ...} is not a
 * permutation, since a and b map to the same letter.
 *
 *
 * Example 2:
 *
 *
 * Input: words = ["a","b","c"], pattern = "a"
 * Output: ["a","b","c"]
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= pattern.length <= 20
 * 1 <= words.length <= 50
 * words[i].length == pattern.length
 * pattern and words[i] are lowercase English letters.
 *
 *
 */

 // @lc code=start
class Solution {
private:
    bool check(string& word, string& pattern) {
        unordered_map<char, char> f, g;
        for (int i = 0; i < word.size(); i++) {
            if (f.count(word[i]) && f[word[i]] != pattern[i]) return false;
            if (g.count(pattern[i]) && g[pattern[i]] != word[i]) return false;
            f[word[i]] = pattern[i];
            g[pattern[i]] = word[i];
        }
        return true;
    }
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string>res;
        for (string& word : words) {
            if (check(word, pattern)) res.push_back(word);
        }
        return res;
    }
};
// @lc code=end

