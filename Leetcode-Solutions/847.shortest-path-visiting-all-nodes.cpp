/*
 * @lc app=leetcode id=847 lang=cpp
 *
 * [847] Shortest Path Visiting All Nodes
 *
 * https://leetcode.com/problems/shortest-path-visiting-all-nodes/description/
 *
 * algorithms
 * Hard (61.30%)
 * Likes:    2931
 * Dislikes: 134
 * Total Accepted:    65K
 * Total Submissions: 106.1K
 * Testcase Example:  '[[1,2,3],[0],[0],[0]]'
 *
 * You have an undirected, connected graph of n nodes labeled from 0 to n - 1.
 * You are given an array graph where graph[i] is a list of all the nodes
 * connected with node i by an edge.
 *
 * Return the length of the shortest path that visits every node. You may start
 * and stop at any node, you may revisit nodes multiple times, and you may
 * reuse edges.
 *
 *
 * Example 1:
 *
 *
 * Input: graph = [[1,2,3],[0],[0],[0]]
 * Output: 4
 * Explanation: One possible path is [1,0,2,0,3]
 *
 *
 * Example 2:
 *
 *
 * Input: graph = [[1],[0,2,4],[1,3,4],[2],[1,2]]
 * Output: 4
 * Explanation: One possible path is [0,1,4,2,3]
 *
 *
 *
 * Constraints:
 *
 *
 * n == graph.length
 * 1 <= n <= 12
 * 0 <= graph[i].length < n
 * graph[i] does not contain i.
 * If graph[a] contains b, then graph[b] contains a.
 * The input graph is always connected.
 *
 *
 */

// @lc code=start
class Solution
{
public:
    int shortestPathLength(vector<vector<int>> &graph)
    {
        int n = graph.size(), INF = 1e8;
        vector<vector<int>> f(1 << n, vector<int>(n, INF));
        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++)
        {
            int x = 1 << i, y = i;
            f[x][y] = 0;
            q.push({x, y});
        }
        while (q.size())
        {
            auto curr = q.front();
            q.pop();
            for (auto next : graph[curr.second])
            {
                int x = curr.first | 1 << next, y = next;
                if (f[x][y] > f[curr.first][curr.second] + 1)
                {
                    f[x][y] = f[curr.first][curr.second] + 1;
                    q.push({x, y});
                }
            }
        }
        int res = INF;
        for (int i = 0; i < n; i++)
        {
            res = min(res, f[(1 << n) - 1][i]);
        }
        return res;
    }
};
// @lc code=end
