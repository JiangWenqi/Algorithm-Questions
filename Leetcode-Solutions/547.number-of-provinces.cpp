// @before-stub-for-debug-begin
#include <string>
#include <vector>

#include "commoncppproblem547.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=547 lang=cpp
 *
 * [547] Number of Provinces
 *
 * https://leetcode.com/problems/number-of-provinces/description/
 *
 * algorithms
 * Medium (62.69%)
 * Likes:    5312
 * Dislikes: 243
 * Total Accepted:    476.6K
 * Total Submissions: 760.2K
 * Testcase Example:  '[[1,1,0],[1,1,0],[0,0,1]]'
 *
 * There are n cities. Some of them are connected, while some are not. If city
 * a is connected directly with city b, and city b is connected directly with
 * city c, then city a is connected indirectly with city c.
 *
 * A province is a group of directly or indirectly connected cities and no
 * other cities outside of the group.
 *
 * You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the
 * i^th city and the j^th city are directly connected, and isConnected[i][j] =
 * 0 otherwise.
 *
 * Return the total number of provinces.
 *
 *
 * Example 1:
 *
 *
 * Input: isConnected = [[1,1,0],[1,1,0],[0,0,1]]
 * Output: 2
 *
 *
 * Example 2:
 *
 *
 * Input: isConnected = [[1,0,0],[0,1,0],[0,0,1]]
 * Output: 3
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= n <= 200
 * n == isConnected.length
 * n == isConnected[i].length
 * isConnected[i][j] is 1 or 0.
 * isConnected[i][i] == 1
 * isConnected[i][j] == isConnected[j][i]
 *
 *
 */

// @lc code=start
const int N = 210;
class Solution
{
private:
  int p[N];
  int find(int x)
  {
    if (p[x] != x)
      p[x] = find(p[x]);
    return p[x];
  }

public:
  int findCircleNum(vector<vector<int>> &isConnected)
  {
    int n = isConnected.size();
    for (int i = 0; i < n; i++)
      p[i] = i;
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < isConnected[i].size(); j++)
      {
        if (isConnected[i][j])
          p[find(i)] = find(j);
      }
    }
    int res = 0;
    for (int i = 0; i < n; i++)
    {
      if (p[i] == i)
        res++;
    }
    return res;
  }
};
// @lc code=end
