/*
 * @lc app=leetcode id=1657 lang=cpp
 *
 * [1657] Determine if Two Strings Are Close
 *
 * https://leetcode.com/problems/determine-if-two-strings-are-close/description/
 *
 * algorithms
 * Medium (56.43%)
 * Likes:    1842
 * Dislikes: 91
 * Total Accepted:    91.2K
 * Total Submissions: 161.6K
 * Testcase Example:  '"abc"\n"bca"'
 *
 * Two strings are considered close if you can attain one from the other using
 * the following operations:
 *
 *
 * Operation 1: Swap any two existing characters.
 *
 *
 * For example, abcde -> aecdb
 *
 *
 * Operation 2: Transform every occurrence of one existing character into
 * another existing character, and do the same with the other
 * character.
 *
 * For example, aacabb -> bbcbaa (all a's turn into b's, and all b's turn into
 * a's)
 *
 *
 *
 *
 * You can use the operations on either string as many times as necessary.
 *
 * Given two strings, word1 and word2, return true if word1 and word2 are
 * close, and false otherwise.
 *
 *
 * Example 1:
 *
 *
 * Input: word1 = "abc", word2 = "bca"
 * Output: true
 * Explanation: You can attain word2 from word1 in 2 operations.
 * Apply Operation 1: "abc" -> "acb"
 * Apply Operation 1: "acb" -> "bca"
 *
 *
 * Example 2:
 *
 *
 * Input: word1 = "a", word2 = "aa"
 * Output: false
 * Explanation: It is impossible to attain word2 from word1, or vice versa, in
 * any number of operations.
 *
 *
 * Example 3:
 *
 *
 * Input: word1 = "cabbba", word2 = "abbccc"
 * Output: true
 * Explanation: You can attain word2 from word1 in 3 operations.
 * Apply Operation 1: "cabbba" -> "caabbb"
 * Apply Operation 2: "caabbb" -> "baaccc"
 * Apply Operation 2: "baaccc" -> "abbccc"
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= word1.length, word2.length <= 10^5
 * word1 and word2 contain only lowercase English letters.
 *
 *
 */

// @lc code=start
class Solution
{
public:
    bool closeStrings(string word1, string word2)
    {
        vector<int> counter1(26, 0), counter2(26, 0);
        vector<int> exist1(26, 0), exist2(26, 0);
        for (char &c : word1)
        {
            counter1[c - 'a']++;
            exist1[c - 'a'] = 1;
        }
        for (char &c : word2)
        {
            counter2[c - 'a']++;
            exist2[c - 'a'] = 1;
        }
        sort(counter1.begin(), counter1.end());
        sort(counter2.begin(), counter2.end());
        return counter1 == counter2 && exist1 == exist2;
    }
};
// @lc code=end
