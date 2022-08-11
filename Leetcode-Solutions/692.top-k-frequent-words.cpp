// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem692.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=692 lang=cpp
 *
 * [692] Top K Frequent Words
 *
 * https://leetcode.com/problems/top-k-frequent-words/description/
 *
 * algorithms
 * Medium (54.74%)
 * Likes:    4804
 * Dislikes: 259
 * Total Accepted:    401.5K
 * Total Submissions: 733.6K
 * Testcase Example:  '["i","love","leetcode","i","love","coding"]\n2'
 *
 * Given an array of strings words and an integer k, return the k most frequent
 * strings.
 *
 * Return the answer sorted by the frequency from highest to lowest. Sort the
 * words with the same frequency by their lexicographical order.
 *
 *
 * Example 1:
 *
 *
 * Input: words = ["i","love","leetcode","i","love","coding"], k = 2
 * Output: ["i","love"]
 * Explanation: "i" and "love" are the two most frequent words.
 * Note that "i" comes before "love" due to a lower alphabetical order.
 *
 *
 * Example 2:
 *
 *
 * Input: words =
 * ["the","day","is","sunny","the","the","the","sunny","is","is"], k = 4
 * Output: ["the","is","sunny","day"]
 * Explanation: "the", "is", "sunny" and "day" are the four most frequent
 * words, with the number of occurrence being 4, 3, 2 and 1 respectively.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= words.length <= 500
 * 1 <= words[i].length <= 10
 * words[i] consists of lowercase English letters.
 * k is in the range [1, The number of unique words[i]]
 *
 *
 *
 * Follow-up: Could you solve it in O(n log(k)) time and O(n) extra space?
 *
 */

 // @lc code=start
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> wdfq;
        for (string& w : words) wdfq[w]++;

        vector<pair<string, int>> heap;
        for (auto& wf : wdfq)
            heap.push_back({ wf.first,wf.second });

        sort(heap.begin(), heap.end(), [&](auto& a, auto& b) {
            return a.second == b.second ? a.first < b.first : a.second > b.second;
            });
        vector<string> res;
        int i = 0;
        while (i < k)
            res.push_back(heap[i++].first);

        return res;
    }
};
// @lc code=end

