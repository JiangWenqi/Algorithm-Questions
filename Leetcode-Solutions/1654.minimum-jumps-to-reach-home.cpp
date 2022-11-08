/*
 * @lc app=leetcode id=1654 lang=cpp
 *
 * [1654] Minimum Jumps to Reach Home
 *
 * https://leetcode.com/problems/minimum-jumps-to-reach-home/description/
 *
 * algorithms
 * Medium (28.66%)
 * Likes:    1146
 * Dislikes: 214
 * Total Accepted:    30.8K
 * Total Submissions: 107.6K
 * Testcase Example:  '[14,4,18,1,15]\n3\n15\n9'
 *
 * A certain bug's home is on the x-axis at position x. Help them get there
 * from position 0.
 *
 * The bug jumps according to the following rules:
 *
 *
 * It can jump exactly a positions forward (to the right).
 * It can jump exactly b positions backward (to the left).
 * It cannot jump backward twice in a row.
 * It cannot jump to any forbidden positions.
 *
 *
 * The bug may jump forward beyond its home, but it cannot jump to positions
 * numbered with negative integers.
 *
 * Given an array of integers forbidden, where forbidden[i] means that the bug
 * cannot jump to the position forbidden[i], and integers a, b, and x, return
 * the minimum number of jumps needed for the bug to reach its home. If there
 * is no possible sequence of jumps that lands the bug on position x, return
 * -1.
 *
 *
 * Example 1:
 *
 *
 * Input: forbidden = [14,4,18,1,15], a = 3, b = 15, x = 9
 * Output: 3
 * Explanation: 3 jumps forward (0 -> 3 -> 6 -> 9) will get the bug home.
 *
 *
 * Example 2:
 *
 *
 * Input: forbidden = [8,3,16,6,12,20], a = 15, b = 13, x = 11
 * Output: -1
 *
 *
 * Example 3:
 *
 *
 * Input: forbidden = [1,6,2,14,5,17,4], a = 16, b = 9, x = 7
 * Output: 2
 * Explanation: One jump forward (0 -> 16) then one jump backward (16 -> 7)
 * will get the bug home.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= forbidden.length <= 1000
 * 1 <= a, b, forbidden[i] <= 2000
 * 0 <= x <= 2000
 * All the elements in forbidden are distinct.
 * Position x is not forbidden.
 *
 *
 */

// @lc code=start
class Solution
{
public:
    int minimumJumps(vector<int> &forbidden, int a, int b, int x)
    {
        int n = 10000;
        unordered_set<int> forbidden_set(forbidden.begin(), forbidden.end());
        vector<vector<bool>> visited(2, vector<bool>(n, false));
        // visited array has two states:
        // visited[0][i] means the ith cell was reached from its left hand side jumping forward,
        // visited[1][i] means the ith cell was reached from its right hand side jumping backward.
        queue<pair<int, bool>> q;
        // true means this position comes from left, -1 means this position comes from right
        q.push({0, true});
        visited[0][0] = true;
        visited[1][0] = true;
        int res = 0;
        while (!q.empty())
        {
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                int cur = q.front().first;
                bool dir = q.front().second;
                if (cur == x)
                    return res;

                q.pop();
                int forward = cur + a;
                int backward = cur - b;
                if (forward < n && !visited[0][forward] && !forbidden_set.count(forward))
                {
                    q.push({forward, true});
                    visited[0][forward] = true;
                }
                if (backward >= 0 && !visited[1][backward] && !forbidden_set.count(backward) && dir)
                {
                    q.push({backward, false});
                    visited[1][backward] = true;
                }
            }
            res++;
        }
        return -1;
    }
};
// @lc code=end
