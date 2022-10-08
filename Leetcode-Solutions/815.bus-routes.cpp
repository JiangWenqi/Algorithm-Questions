// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
#include "commoncppproblem815.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=815 lang=cpp
 *
 * [815] Bus Routes
 *
 * https://leetcode.com/problems/bus-routes/description/
 *
 * algorithms
 * Hard (45.71%)
 * Likes:    2608
 * Dislikes: 66
 * Total Accepted:    107.5K
 * Total Submissions: 235.1K
 * Testcase Example:  '[[1,2,7],[3,6,7]]\n1\n6'
 *
 * You are given an array routes representing bus routes where routes[i] is a
 * bus route that the i^th bus repeats forever.
 *
 *
 * For example, if routes[0] = [1, 5, 7], this means that the 0^th bus travels
 * in the sequence 1 -> 5 -> 7 -> 1 -> 5 -> 7 -> 1 -> ... forever.
 *
 *
 * You will start at the bus stop source (You are not on any bus initially),
 * and you want to go to the bus stop target. You can travel between bus stops
 * by buses only.
 *
 * Return the least number of buses you must take to travel from source to
 * target. Return -1 if it is not possible.
 *
 *
 * Example 1:
 *
 *
 * Input: routes = [[1,2,7],[3,6,7]], source = 1, target = 6
 * Output: 2
 * Explanation: The best strategy is take the first bus to the bus stop 7, then
 * take the second bus to the bus stop 6.
 *
 *
 * Example 2:
 *
 *
 * Input: routes = [[7,12],[4,5,15],[6],[15,19],[9,12,13]], source = 15, target
 * = 12
 * Output: -1
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= routes.length <= 500.
 * 1 <= routes[i].length <= 10^5
 * All the values of routes[i] are unique.
 * sum(routes[i].length) <= 10^5
 * 0 <= routes[i][j] < 10^6
 * 0 <= source, target < 10^6
 *
 *
 */

 // @lc code=start
class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if (source == target) return 0;
        int n = routes.size();
        unordered_map<int, vector<int>> g; // stop -> buses
        vector<int> dist(n, 1e8);
        queue<int> q; // buses
        for (int i = 0; i < n; i++) {
            for (int& x : routes[i]) {
                if (x == source) {
                    dist[i] = 1;
                    q.push(i);
                }
                g[x].push_back(i);
            }
        }
        while (q.size()) {
            int t = q.front(); // start bus
            q.pop();
            for (int& x : routes[t]) { // stops
                if (x == target) return dist[t];
                for (int& y : g[x]) { // next buses
                    if (dist[y] > dist[t] + 1) {
                        dist[y] = dist[t] + 1;
                        q.push(y);
                    }
                }
                g.erase(x);
            }
        }
        return -1;
    }

};
// @lc code=end

