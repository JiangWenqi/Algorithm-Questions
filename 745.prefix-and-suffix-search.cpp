// @before-stub-for-debug-begin
#include <string>
#include <vector>

#include "commoncppproblem745.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=745 lang=cpp
 *
 * [745] Prefix and Suffix Search
 *
 * https://leetcode.com/problems/prefix-and-suffix-search/description/
 *
 * algorithms
 * Hard (36.60%)
 * Likes:    1579
 * Dislikes: 396
 * Total Accepted:    65.9K
 * Total Submissions: 169.9K
 * Testcase Example:  '["WordFilter","f"]\n[[["apple"]],["a","e"]]'
 *
 * Design a special dictionary with some words that searchs the words in it by
 * a prefix and a suffix.
 *
 * Implement the WordFilter class:
 *
 *
 * WordFilter(string[] words) Initializes the object with the words in the
 * dictionary.
 * f(string prefix, string suffix) Returns the index of the word in the
 * dictionary, which has the prefix prefix and the suffix suffix. If there is
 * more than one valid index, return the largest of them. If there is no such
 * word in the dictionary, return -1.
 *
 *
 *
 * Example 1:
 *
 *
 * Input
 * ["WordFilter", "f"]
 * [[["apple"]], ["a", "e"]]
 * Output
 * [null, 0]
 *
 * Explanation
 * WordFilter wordFilter = new WordFilter(["apple"]);
 * wordFilter.f("a", "e"); // return 0, because the word at index 0 has prefix
 * = "a" and suffix = 'e".
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= words.length <= 15000
 * 1 <= words[i].length <= 10
 * 1 <= prefix.length, suffix.length <= 10
 * words[i], prefix and suffix consist of lower-case English letters only.
 * At most 15000 calls will be made to the function f.
 *
 *
 */

// @lc code=start
const int N = 2000000;

class WordFilter {
 private:
  int son[N][27], w[N], idx;

  void insert(string& s, int id) {
    int p = 0;
    for (auto c : s) {
      int t = c == '#' ? 26 : c - 'a';
      if (!son[p][t]) son[p][t] = ++idx;
      p = son[p][t];
      w[p] = id;
    }
  }

  int query(string s) {
    int p = 0;
    for (auto c : s) {
      int t = c == '#' ? 26 : c - 'a';
      if (!son[p][t]) return -1;
      p = son[p][t];
    }
    return w[p];
  }

 public:
  WordFilter(vector<string>& words) {
    memset(son, 0, sizeof son);
    idx = 0;
    for (int i = 0; i < words.size(); i++) {
      string s = '#' + words[i];
      insert(s, i);
      for (int j = words[i].size() - 1; j >= 0; j--) {
        s = words[i][j] + s;
        insert(s, i);
      }
    }
  }

  int f(string prefix, string suffix) { return query(suffix + '#' + prefix); }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */
// @lc code=end
