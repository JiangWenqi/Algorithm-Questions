/*
 * @lc app=leetcode id=1220 lang=cpp
 *
 * [1220] Count Vowels Permutation
 *
 * https://leetcode.com/problems/count-vowels-permutation/description/
 *
 * algorithms
 * Hard (56.12%)
 * Likes:    1487
 * Dislikes: 115
 * Total Accepted:    64.2K
 * Total Submissions: 109.6K
 * Testcase Example:  '1'
 *
 * Given an integer n, your task is to count how many strings of length n can
 * be formed under the following rules:
 *
 *
 * Each character is a lower case vowel ('a', 'e', 'i', 'o', 'u')
 * Each vowel 'a' may only be followed by an 'e'.
 * Each vowel 'e' may only be followed by an 'a' or an 'i'.
 * Each vowel 'i' may not be followed by another 'i'.
 * Each vowel 'o' may only be followed by an 'i' or a 'u'.
 * Each vowel 'u' may only be followed by an 'a'.
 *
 *
 * Since the answer may be too large, return it modulo 10^9 + 7.
 *
 *
 * Example 1:
 *
 *
 * Input: n = 1
 * Output: 5
 * Explanation: All possible strings are: "a", "e", "i" , "o" and "u".
 *
 *
 * Example 2:
 *
 *
 * Input: n = 2
 * Output: 10
 * Explanation: All possible strings are: "ae", "ea", "ei", "ia", "ie", "io",
 * "iu", "oi", "ou" and "ua".
 *
 *
 * Example 3: 
 *
 *
 * Input: n = 5
 * Output: 68
 *
 *
 * Constraints:
 *
 *
 * 1 <= n <= 2 * 10^4
 *
 *
 */

 // @lc code=start
class Solution {
private:
    int MOD = 1e9 + 7;
    // i only be followed by j => ij
    int check[5][5] = {
        {0,1,0,0,0},
        {1,0,1,0,0},
        {1,1,0,1,1},
        {0,0,1,0,1},
        {1,0,0,0,0}
    };
public:
    int countVowelPermutation(int n) {
        // f[i][j], means A string of length i + 1 ends with j (a, e, i, o, u)
        vector<vector<int>> f(n, vector<int>(5, 0));

        for (int i = 0; i < 5; i++) f[0][i] = 1;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < 5; j++) {
                for (int k = 0; k < 5; k++) {
                    // kj
                    if (check[k][j]) {
                        f[i][j] += f[i - 1][k];
                        f[i][j] %= MOD;
                    }
                }
            }
        }
        int res = 0;
        for (int i = 0; i < 5; i++) {
            res += f[n - 1][i];
            res %= MOD;
        }
        return res;
    }
};
// @lc code=end

