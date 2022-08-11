/*
 * @lc app=leetcode id=207 lang=cpp
 *
 * [207] Course Schedule
 *
 * https://leetcode.com/problems/course-schedule/description/
 *
 * algorithms
 * Medium (45.09%)
 * Likes:    9430
 * Dislikes: 382
 * Total Accepted:    879.9K
 * Total Submissions: 2M
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
 * Return true if you can finish all courses. Otherwise, return false.
 *
 *
 * Example 1:
 *
 *
 * Input: numCourses = 2, prerequisites = [[1,0]]
 * Output: true
 * Explanation: There are a total of 2 courses to take.
 * To take course 1 you should have finished course 0. So it is possible.
 *
 *
 * Example 2:
 *
 *
 * Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
 * Output: false
 * Explanation: There are a total of 2 courses to take.
 * To take course 1 you should have finished course 0, and to take course 0 you
 * should also have finished course 1. So it is impossible.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= numCourses <= 2000
 * 0 <= prerequisites.length <= 5000
 * prerequisites[i].length == 2
 * 0 <= ai, bi < numCourses
 * All the pairs prerequisites[i] are unique.
 *
 *
 */

// @lc code=start
class Solution
{
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<vector<int>> adj(numCourses);
        vector<int> ins(numCourses, 0);

        for (auto &prerequisite : prerequisites)
        {
            // b <- a
            int a = prerequisite[1], b = prerequisite[0];
            adj[a].push_back(b);
            ins[b]++;
        }
        // All courses that do not require other prerequisites, which means ins[i] == 0
        queue<int> q;
        for (int i = 0; i < numCourses; i++)
        {
            if (ins[i] == 0)
                q.push(i);
        }
        // courses
        int cnt = 0;
        while (!q.empty())
        {
            int i = q.front();
            q.pop();
            cnt++;
            for (int &course : adj[i])
            {
                if (--ins[course] == 0)
                    q.push(course);
            }
        }
        return cnt == numCourses;
    }
};
// @lc code=end
