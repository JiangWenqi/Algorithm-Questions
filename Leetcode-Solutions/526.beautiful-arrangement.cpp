// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem526.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=526 lang=cpp
 *
 * [526] Beautiful Arrangement
 *
 * https://leetcode.com/problems/beautiful-arrangement/description/
 *
 * algorithms
 * Medium (64.43%)
 * Likes:    2168
 * Dislikes: 297
 * Total Accepted:    130.8K
 * Total Submissions: 203K
 * Testcase Example:  '2'
 *
 * Suppose you have n integers labeled 1 through n. A permutation of those n
 * integers perm (1-indexed) is considered a beautiful arrangement if for every
 * i (1 <= i <= n), either of the following is true:
 *
 *
 * perm[i] is divisible by i.
 * i is divisible by perm[i].
 *
 *
 * Given an integer n, return the number of the beautiful arrangements that you
 * can construct.
 *
 *
 * Example 1:
 *
 *
 * Input: n = 2
 * Output: 2
 * Explanation:
 * The first beautiful arrangement is [1,2]:
 * ⁠   - perm[1] = 1 is divisible by i = 1
 * ⁠   - perm[2] = 2 is divisible by i = 2
 * The second beautiful arrangement is [2,1]:
 * ⁠   - perm[1] = 2 is divisible by i = 1
 * ⁠   - i = 2 is divisible by perm[2] = 1
 *
 *
 * Example 2:
 *
 *
 * Input: n = 1
 * Output: 1
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= n <= 15
 *
 *
 */

// @lc code=start
class Solution
{

private:
    int res = 0;
    vector<int> visited;

    void dfs(int idx, int n)
    {
        if (idx > n)
        {
            res++;
            return;
        }
        for (int i = 1; i <= n; i++)
        {
            if (!visited[i] && (i % idx == 0 || idx % i == 0))
            {
                visited[i] = true;
                dfs(idx + 1, n);
                visited[i] = false;
            }
        }
    }

public:
    int countArrangement(int n)
    {
        visited = vector<int>(n + 1, 0);
        dfs(1, n);
        return res;
    }
};
// @lc code=end
