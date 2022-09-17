/*
 * @lc app=leetcode id=336 lang=cpp
 *
 * [336] Palindrome Pairs
 *
 * https://leetcode.com/problems/palindrome-pairs/description/
 *
 * algorithms
 * Hard (35.06%)
 * Likes:    3360
 * Dislikes: 331
 * Total Accepted:    163K
 * Total Submissions: 464.9K
 * Testcase Example:  '["abcd","dcba","lls","s","sssll"]'
 *
 * Given a list of unique words, return all the pairs of the distinct indices
 * (i, j) in the given list, so that the concatenation of the two words
 * words[i] + words[j] is a palindrome.
 *
 *
 * Example 1:
 *
 *
 * Input: words = ["abcd","dcba","lls","s","sssll"]
 * Output: [[0,1],[1,0],[3,2],[2,4]]
 * Explanation: The palindromes are ["dcbaabcd","abcddcba","slls","llssssll"]
 *
 *
 * Example 2:
 *
 *
 * Input: words = ["bat","tab","cat"]
 * Output: [[0,1],[1,0]]
 * Explanation: The palindromes are ["battab","tabbat"]
 *
 *
 * Example 3:
 *
 *
 * Input: words = ["a",""]
 * Output: [[0,1],[1,0]]
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= words.length <= 5000
 * 0 <= words[i].length <= 300
 * words[i] consists of lower-case English letters.
 *
 *
 */

 // @lc code=start
typedef unsigned long long ULL;

const int N = 310, P = 131;

ULL p[N];

class Solution {
public:
    vector<vector<ULL>> h1, h2;

    ULL get(vector<ULL>& h, int l, int r) {
        return h[r] - h[l - 1] * p[r - l + 1];
    }

    vector<vector<int>> palindromePairs(vector<string>& words) {
        p[0] = 1;
        for (int i = 1; i < N; i++) p[i] = p[i - 1] * P;

        for (int i = 0; i < words.size(); i++) {
            int n = words[i].size();
            vector<ULL> a(1), b(1);
            for (int j = 1; j <= n; j++) a.push_back(a.back() * P + words[i][j - 1]);
            for (int j = n; j; j--) b.push_back(b.back() * P + words[i][j - 1]);
            h1.push_back(a);
            h2.push_back(b);
        }

        unordered_map<ULL, int> hash;
        for (int i = 0; i < words.size(); i++)
            hash[get(h2[i], 1, words[i].size())] = i;

        vector<vector<int>> res;
        for (int i = 0; i < words.size(); i++) {
            int n = words[i].size();
            for (int j = 0; j <= n; j++) {
                auto left = get(h1[i], 1, j), right = get(h1[i], j + 1, n);
                if (right == get(h2[i], 1, n - j) && hash.count(left) && hash[left] != i) res.push_back({ i, hash[left] });
                if (left == get(h2[i], n - j + 1, n) && hash.count(right) && hash[right] != i && words[i].size() != words[hash[right]].size())
                    res.push_back({ hash[right], i });
            }
        }
        return res;
    }
};



// @lc code=end

