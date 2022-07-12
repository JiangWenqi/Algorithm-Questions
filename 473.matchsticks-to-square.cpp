// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem473.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=473 lang=cpp
 *
 * [473] Matchsticks to Square
 *
 * https://leetcode.com/problems/matchsticks-to-square/description/
 *
 * algorithms
 * Medium (40.23%)
 * Likes:    2429
 * Dislikes: 181
 * Total Accepted:    99K
 * Total Submissions: 247.6K
 * Testcase Example:  '[1,1,2,2,2]'
 *
 * You are given an integer array matchsticks where matchsticks[i] is the
 * length of the i^th matchstick. You want to use all the matchsticks to make
 * one square. You should not break any stick, but you can link them up, and
 * each matchstick must be used exactly one time.
 *
 * Return true if you can make this square and false otherwise.
 *
 *
 * Example 1:
 *
 *
 * Input: matchsticks = [1,1,2,2,2]
 * Output: true
 * Explanation: You can form a square with length 2, one side of the square
 * came two sticks with length 1.
 *
 *
 * Example 2:
 *
 *
 * Input: matchsticks = [3,3,3,3,4]
 * Output: false
 * Explanation: You cannot find a way to form a square with all the
 * matchsticks.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= matchsticks.length <= 15
 * 1 <= matchsticks[i] <= 10^8
 *
 *
 */

 // @lc code=start
class Solution {
private:

    vector<int> visited;
    bool backtracking(int idx, int currSum, int targetSum, int currEdge, vector<int>& matchsticks) {
        // Trick: only need 3 edges equal target
        if (currEdge == 3) return true;
        else if (currSum == targetSum) return backtracking(0, 0, targetSum, currEdge + 1, matchsticks);
        for (int i = idx; i < matchsticks.size(); i++) {
            if (visited[i] || currSum + matchsticks[i] > targetSum) continue;
            visited[i] = true;
            if (backtracking(i + 1, currSum + matchsticks[i], targetSum, currEdge, matchsticks)) return true;
            visited[i] = false;
        }
        return false;
    }
public:
    bool makesquare(vector<int>& matchsticks) {
        int n = matchsticks.size();
        visited.resize(n, false);
        int sum = 0;
        for (int& matchstick : matchsticks) sum += matchstick;
        if (sum % 4) return false;
        return backtracking(0, 0, sum / 4, 0, matchsticks);
    }
};
// @lc code=end

