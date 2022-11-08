/*
 * @lc app=leetcode id=1129 lang=cpp
 *
 * [1129] Shortest Path with Alternating Colors
 *
 * https://leetcode.com/problems/shortest-path-with-alternating-colors/description/
 *
 * algorithms
 * Medium (42.93%)
 * Likes:    1619
 * Dislikes: 81
 * Total Accepted:    45.6K
 * Total Submissions: 106.3K
 * Testcase Example:  '3\n[[0,1],[1,2]]\n[]'
 *
 * You are given an integer n, the number of nodes in a directed graph where
 * the nodes are labeled from 0 to n - 1. Each edge is red or blue in this
 * graph, and there could be self-edges and parallel edges.
 *
 * You are given two arrays redEdges and blueEdges where:
 *
 *
 * redEdges[i] = [ai, bi] indicates that there is a directed red edge from node
 * ai to node bi in the graph, and
 * blueEdges[j] = [uj, vj] indicates that there is a directed blue edge from
 * node uj to node vj in the graph.
 *
 *
 * Return an array answer of length n, where each answer[x] is the length of
 * the shortest path from node 0 to node x such that the edge colors alternate
 * along the path, or -1 if such a path does not exist.
 *
 *
 * Example 1:
 *
 *
 * Input: n = 3, redEdges = [[0,1],[1,2]], blueEdges = []
 * Output: [0,1,-1]
 *
 *
 * Example 2:
 *
 *
 * Input: n = 3, redEdges = [[0,1]], blueEdges = [[2,1]]
 * Output: [0,1,-1]
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= n <= 100
 * 0 <= redEdges.length, blueEdges.length <= 400
 * redEdges[i].length == blueEdges[j].length == 2
 * 0 <= ai, bi, uj, vj < n
 *
 * Solution
 * https://www.acwing.com/activity/content/problem/content/5937/
 */

// @lc code=start
class Solution
{
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>> &redEdges, vector<vector<int>> &blueEdges)
    {
        const int INF = 1e8;
        vector<vector<pair<int, int>>> g(n);
        for (auto &edge : redEdges)
            g[edge[0]].push_back({edge[1], 0});
        for (auto &edge : blueEdges)
            g[edge[0]].push_back({edge[1], 1});

        vector<vector<int>> dist(n, vector<int>(2, INF));
        dist[0][0] = dist[0][1] = 0;
        queue<pair<int, int>> q;
        q.push({0, 0}), q.push({0, 1});

        while (!q.empty())
        {
            auto node = q.front();
            q.pop();
            for (auto &next : g[node.first])
            {
                if (node.second != next.second && dist[node.first][node.second] + 1 < dist[next.first][next.second])
                {
                    dist[next.first][next.second] = dist[node.first][node.second] + 1;
                    q.push(next);
                }
            }
        }
        vector<int> res(n);
        for (int i = 0; i < n; i++)
        {
            // answer[x] is the length of the shortest path from node 0 to node x 
            res[i] = min(dist[i][0], dist[i][1]);
            res[i] = res[i] == INF ? -1 : res[i];
        }
        return res;
    }
};
// @lc code=end
