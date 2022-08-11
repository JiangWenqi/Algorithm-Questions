#include <priority_queue>
#include <string>
#include <vector>

using namespace std;
/*
 * @lc app=leetcode id=1268 lang=cpp
 *
 * [1268] Search Suggestions System
 *
 * https://leetcode.com/problems/search-suggestions-system/description/
 *
 * algorithms
 * Medium (65.31%)
 * Likes:    2870
 * Dislikes: 148
 * Total Accepted:    180.6K
 * Total Submissions: 273.1K
 * Testcase Example:
 * '["mobile","mouse","moneypot","monitor","mousepad"]\n"mouse"'
 *
 * You are given an array of strings products and a string searchWord.
 *
 * Design a system that suggests at most three product names from products
 * after each character of searchWord is typed. Suggested products should have
 * common prefix with searchWord. If there are more than three products with a
 * common prefix return the three lexicographically minimums products.
 *
 * Return a list of lists of the suggested products after each character of
 * searchWord is typed.
 *
 *
 * Example 1:
 *
 *
 * Input: products = ["mobile","mouse","moneypot","monitor","mousepad"],
 * searchWord = "mouse"
 * Output: [
 * ["mobile","moneypot","monitor"],
 * ["mobile","moneypot","monitor"],
 * ["mouse","mousepad"],
 * ["mouse","mousepad"],
 * ["mouse","mousepad"]
 * ]
 * Explanation: products sorted lexicographically =
 * ["mobile","moneypot","monitor","mouse","mousepad"]
 * After typing m and mo all products match and we show user
 * ["mobile","moneypot","monitor"]
 * After typing mou, mous and mouse the system suggests ["mouse","mousepad"]
 *
 *
 * Example 2:
 *
 *
 * Input: products = ["havana"], searchWord = "havana"
 * Output:
 * [["havana"],["havana"],["havana"],["havana"],["havana"],["havana"]]
 *
 *
 * Example 3:
 *
 *
 * Input: products = ["bags","baggage","banner","box","cloths"], searchWord =
 * "bags"
 * Output:
 * [["baggage","bags","banner"],["baggage","bags","banner"],["baggage","bags"],["bags"]]
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= products.length <= 1000
 * 1 <= products[i].length <= 3000
 * 1 <= sum(products[i].length) <= 2 * 10^4
 * All the strings of products are unique.
 * products[i] consists of lowercase English letters.
 * 1 <= searchWord.length <= 1000
 * searchWord consists of lowercase English letters.
 *
 *
 */

// @lc code=start
const int N = 10000;
class Solution {
 public:
  vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
    vector<vector<string>> res;
    // sort the array so that we get  strings in lexixographically minimum order
    sort(products.begin(), products.end());
    for (int i = 0; i < searchWord.length(); i++) {
      vector<string> v;
      // start creating substrings till each index
      string s = searchWord.substr(0, i + 1);
      for (int j = 0; j < products.size(); j++) {
        string word = products[j].substr(0, i + 1);
        if (s == word && v.size() < 3) {
          v.push_back(products[j]);
        }
      }
      res.push_back(v);
    }
    return res;
  }
};
// @lc code=end
