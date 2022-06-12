// @before-stub-for-debug-begin
#include "commoncppproblem677.h"
#include <string>
#include <vector>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=677 lang=cpp
 *
 * [677] Map Sum Pairs
 *
 * https://leetcode.com/problems/map-sum-pairs/description/
 *
 * algorithms
 * Medium (56.99%)
 * Likes:    1246
 * Dislikes: 126
 * Total Accepted:    89.9K
 * Total Submissions: 157.7K
 * Testcase Example:  '["MapSum","insert","sum","insert","sum"]\n' +
  '[[],["apple",3],["ap"],["app",2],["ap"]]'
 *
 * Design a map that allows you to do the following:
 *
 *
 * Maps a string key to a given value.
 * Returns the sum of the values that have a key with a prefix equal to a given
 * string.
 *
 *
 * Implement the MapSum class:
 *
 *
 * MapSum() Initializes the MapSum object.
 * void insert(String key, int val) Inserts the key-val pair into the map. If
 * the key already existed, the original key-value pair will be overridden to
 * the new one.
 * int sum(string prefix) Returns the sum of all the pairs' value whose key
 * starts with the prefix.
 *
 *
 *
 * Example 1:
 *
 *
 * Input
 * ["MapSum", "insert", "sum", "insert", "sum"]
 * [[], ["apple", 3], ["ap"], ["app", 2], ["ap"]]
 * Output
 * [null, null, 3, null, 5]
 *
 * Explanation
 * MapSum mapSum = new MapSum();
 * mapSum.insert("apple", 3);
 * mapSum.sum("ap");           // return 3 (apple = 3)
 * mapSum.insert("app", 2);
 * mapSum.sum("ap");           // return 5 (apple + app = 3 + 2 = 5)
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= key.length, prefix.length <= 50
 * key and prefix consist of only lowercase English letters.
 * 1 <= val <= 1000
 * At most 50 calls will be made to insert and sum.
 *
 *
 */

// @lc code=start
const int N = 1010;

class MapSum {

private:
  int son[N][26], vals[N], prefixSums[N], idx;
  void insert(string &key, int val, int lastVal) {
    int p = 0;
    for (char &c : key) {
      int i = c - 'a';
      if (!son[p][i])
        son[p][i] = ++idx;
      p = son[p][i];
      prefixSums[p] += val - lastVal;
    }
    vals[p] = val;
  }

  int query(string &prefix) {
    int p = 0;
    for (char &c : prefix) {
      int i = c - 'a';
      if (!son[p][i])
        return 0;
      p = son[p][i];
    }
    return p;
  }

public:
  MapSum() {
    memset(son, 0, sizeof son);
    memset(vals, 0, sizeof vals);
    memset(prefixSums, 0, sizeof prefixSums);
    idx = 0;
  }

  void insert(string key, int val) { insert(key, val, vals[query(key)]); }

  int sum(string prefix) { return prefixSums[query(prefix)]; }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */
// @lc code=end
