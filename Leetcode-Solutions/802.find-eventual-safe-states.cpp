// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem802.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=802 lang=cpp
 *
 * [802] Find Eventual Safe States
 *
 * https://leetcode.com/problems/find-eventual-safe-states/description/
 *
 * algorithms
 * Medium (54.63%)
 * Likes:    2820
 * Dislikes: 340
 * Total Accepted:    99.5K
 * Total Submissions: 182.1K
 * Testcase Example:  '[[1,2],[2,3],[5],[0],[5],[],[]]'
 *
 * There is a directed graph of n nodes with each node labeled from 0 to n - 1.
 * The graph is represented by a 0-indexed 2D integer array graph where
 * graph[i] is an integer array of nodes adjacent to node i, meaning there is
 * an edge from node i to each node in graph[i].
 *
 * A node is a terminal node if there are no outgoing edges. A node is a safe
 * node if every possible path starting from that node leads to a terminal node
 * (or another safe node).
 *
 * Return an array containing all the safe nodes of the graph. The answer
 * should be sorted in ascending order.
 *
 *
 * Example 1:
 *
 *
 * Input: graph = [[1,2],[2,3],[5],[0],[5],[],[]]
 * Output: [2,4,5,6]
 * Explanation: The given graph is shown above.
 * Nodes 5 and 6 are terminal nodes as there are no outgoing edges from either
 * of them.
 * Every path starting at nodes 2, 4, 5, and 6 all lead to either node 5 or 6.
 *
 * Example 2:
 *
 *
 * Input: graph = [[1,2,3,4],[1,2],[3,4],[0,4],[]]
 * Output: [4]
 * Explanation:
 * Only node 4 is a terminal node, and every path starting at node 4 leads to
 * node 4.
 *
 *
 *
 * Constraints:
 *
 *
 * n == graph.length
 * 1 <= n <= 10^4
 * 0 <= graph[i].length <= n
 * 0 <= graph[i][j] <= n - 1
 * graph[i] is sorted in a strictly increasing order.
 * The graph may contain self-loops.
 * The number of edges in the graph will be in the range [1, 4 * 10^4].
 *
 *
 */

 // @lc code=start
class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> d(n);
        vector<vector<int>> g(n);
        // 1. reverse all edges
        // 2. store in-degrees of new graph
        for (int i = 0; i < n; i++) {
            for (auto& j : graph[i]) {
                g[j].push_back(i);
                d[i] ++;
            }
        }
        // 3. store indexes whose in-degree equals 0
        queue<int> q;
        for (int i = 0; i < n;i++) {
            if (!d[i]) q.push(i);
        }
        // 4. Cut off these edges linking above nodes
        while (q.size()) {
            int t = q.front();
            q.pop();
            for (auto u : g[t]) {
                if (--d[u] == 0) {
                    q.push(u);
                }
            }
        }
        vector<int> res;
        for (int i = 0;i < n; i++) {
            if (!d[i]) res.push_back(i);
        }
        return res;

    }
};
// @lc code=end

