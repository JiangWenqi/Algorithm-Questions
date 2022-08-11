// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem210.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=210 lang=cpp
 *
 * [210] Course Schedule II
 *
 * https://leetcode.com/problems/course-schedule-ii/description/
 *
 * algorithms
 * Medium (47.33%)
 * Likes:    7458
 * Dislikes: 254
 * Total Accepted:    679.4K
 * Total Submissions: 1.4M
 * Testcase Example:  '2\n[[1,0]]'
 *
 * There are a total of numCourses courses you have to take, labeled from 0 to
 * numCourses - 1. You are given an array prerequisites where prerequisites[i]
 * = [ai, bi] indicates that you must take course bi first if you want to take
 * course ai.
 *
 *
 * For example, the pair [0, 1], indicates that to take course 0 you have to
 * first take course 1.
 *
 *
 * Return the ordering of courses you should take to finish all courses. If
 * there are many valid answers, return any of them. If it is impossible to
 * finish all courses, return an empty array.
 *
 *
 * Example 1:
 *
 *
 * Input: numCourses = 2, prerequisites = [[1,0]]
 * Output: [0,1]
 * Explanation: There are a total of 2 courses to take. To take course 1 you
 * should have finished course 0. So the correct course order is [0,1].
 *
 *
 * Example 2:
 *
 *
 * Input: numCourses = 4, prerequisites = [[1,0],[2,0],[3,1],[3,2]]
 * Output: [0,2,1,3]
 * Explanation: There are a total of 4 courses to take. To take course 3 you
 * should have finished both courses 1 and 2. Both courses 1 and 2 should be
 * taken after you finished course 0.
 * So one correct course order is [0,1,2,3]. Another correct ordering is
 * [0,2,1,3].
 *
 *
 * Example 3:
 *
 *
 * Input: numCourses = 1, prerequisites = []
 * Output: [0]
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= numCourses <= 2000
 * 0 <= prerequisites.length <= numCourses * (numCourses - 1)
 * prerequisites[i].length == 2
 * 0 <= ai, bi < numCourses
 * ai != bi
 * All the pairs [ai, bi] are distinct.
 *
 *
 */

 // @lc code=start
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> g(numCourses);
        vector<int> in(numCourses, 0);
        for (auto& p : prerequisites) {
            int a = p[0], b = p[1];
            // b -> a
            g[b].push_back(a);
            // how many prerequisites need to learn a course?
            in[a] ++;
        }

        queue<int> q;
        // in = 0, means you've already finished the prerequisites, and you can learn this course
        for (int i = 0; i < numCourses; i++)
            if (in[i] == 0) q.push(i);

        vector<int> res;
        while (!q.empty()) {
            int p = q.front();
            q.pop();
            res.push_back(p);
            for (auto& c : g[p]) {
                if (--in[c] == 0) q.push(c);
            }
        }
        if (res.size() == numCourses) return res;
        else return {};
    }
};
// @lc code=end

