// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=792 lang=cpp
 *
 * [792] Number of Matching Subsequences
 *
 * https://leetcode.com/problems/number-of-matching-subsequences/description/
 *
 * algorithms
 * Medium (50.69%)
 * Likes:    3697
 * Dislikes: 168
 * Total Accepted:    155.6K
 * Total Submissions: 304.4K
 * Testcase Example:  '"abcde"\n["a","bb","acd","ace"]'
 *
 * Given a string s and an array of strings words, return the number of
 * words[i] that is a subsequence of s.
 *
 * A subsequence of a string is a new string generated from the original string
 * with some characters (can be none) deleted without changing the relative
 * order of the remaining characters.
 *
 *
 * For example, "ace" is a subsequence of "abcde".
 *
 *
 *
 * Example 1:
 *
 *
 * Input: s = "abcde", words = ["a","bb","acd","ace"]
 * Output: 3
 * Explanation: There are three strings in words that are a subsequence of s:
 * "a", "acd", "ace".
 *
 *
 * Example 2:
 *
 *
 * Input: s = "dsahjpjauf", words = ["ahjpjau","ja","ahbwzgqnuk","tnmlanowax"]
 * Output: 2
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 5 * 10^4
 * 1 <= words.length <= 5000
 * 1 <= words[i].length <= 50
 * s and words[i] consist of only lowercase English letters.
 *
 *
 */

 // @lc code=start
class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        // prefix -> list of words index in words array
        unordered_map<char, vector<int>> ps; 
        for (int i = 0; i < words.size(); ++i)
            ps[words[i][0]].push_back(i);
        int res = 0;
        for (char& c : s) {
            vector<int> idxes = ps[c];
            ps.erase(c);
            for (int idx : idxes) {
                if (words[idx].size() == 1) res++;
                else {
                    words[idx].erase(0, 1);
                    ps[words[idx][0]].push_back(idx);
                }
            }
        }
        return res;
    }

};
// @lc code=end

