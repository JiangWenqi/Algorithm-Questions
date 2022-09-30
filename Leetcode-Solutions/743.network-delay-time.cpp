/*
 * @lc app=leetcode id=743 lang=cpp
 *
 * [743] Network Delay Time
 *
 * https://leetcode.com/problems/network-delay-time/description/
 *
 * algorithms
 * Medium (51.26%)
 * Likes:    5607
 * Dislikes: 318
 * Total Accepted:    327.6K
 * Total Submissions: 639.1K
 * Testcase Example:  '[[2,1,1],[2,3,1],[3,4,1]]\n4\n2'
 *
 * You are given a network of n nodes, labeled from 1 to n. You are also given
 * times, a list of travel times as directed edges times[i] = (ui, vi, wi),
 * where ui is the source node, vi is the target node, and wi is the time it
 * takes for a signal to travel from source to target.
 *
 * We will send a signal from a given node k. Return the minimum time it takes
 * for all the n nodes to receive the signal. If it is impossible for all the n
 * nodes to receive the signal, return -1.
 *
 *
 * Example 1:
 *
 *
 * Input: times = [[2,1,1],[2,3,1],[3,4,1]], n = 4, k = 2
 * Output: 2
 *
 *
 * Example 2:
 *
 *
 * Input: times = [[1,2,1]], n = 2, k = 1
 * Output: 1
 *
 *
 * Example 3:
 *
 *
 * Input: times = [[1,2,1]], n = 2, k = 2
 * Output: -1
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= k <= n <= 100
 * 1 <= times.length <= 6000
 * times[i].length == 3
 * 1 <= ui, vi <= n
 * ui != vi
 * 0 <= wi <= 100
 * All the pairs (ui, vi) are unique. (i.e., no multiple edges.)
 *
 *
 */

 // @lc code=start
const int N = 110, M = 6010, INF = 0x3f3f3f3f;
int h[N], e[M], w[M], ne[M], idx;
int dist[N];
bool st[N];
class Solution {
private:
    void add(int a, int b, int c) {
        e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
    }
    void spfa(int start) {
        queue<int> q;
        q.push(start);
        memset(dist, INF, sizeof dist);
        dist[start] = 0;
        while (q.size()) {
            int t = q.front();
            q.pop();
            st[t] = false;
            for (int i = h[t]; ~i; i = ne[i]) {
                int j = e[i];
                if (dist[j] > dist[t] + w[i]) {
                    dist[j] = dist[t] + w[i];
                    if (!st[j]) {
                        q.push(j);
                        st[j] = true;
                    }
                }
            }
        }

    }
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        memset(h, -1, sizeof h);
        idx = 0;
        for (auto& e : times) {
            int a = e[0], b = e[1], c = e[2];
            add(a, b, c);
        }
        spfa(k);
        int res = 1;
        for (int i = 1; i <= n; i++)
            res = max(res, dist[i]);

        return res == INF ? -1 : res;
    }
};
// @lc code=end

