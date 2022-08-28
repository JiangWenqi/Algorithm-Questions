// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem735.h"

using namespace std;
// @before-stub-for-debug-end

#include <vector>

using namespace std;
/*
 * @lc app=leetcode id=735 lang=cpp
 *
 * [735] Asteroid Collision
 *
 * https://leetcode.com/problems/asteroid-collision/description/
 *
 * algorithms
 * Medium (44.36%)
 * Likes:    3966
 * Dislikes: 335
 * Total Accepted:    222.4K
 * Total Submissions: 501.3K
 * Testcase Example:  '[5,10,-5]'
 *
 * We are given an array asteroids of integers representing asteroids in a
 * row.
 *
 * For each asteroid, the absolute value represents its size, and the sign
 * represents its direction (positive meaning right, negative meaning left).
 * Each asteroid moves at the same speed.
 *
 * Find out the state of the asteroids after all collisions. If two asteroids
 * meet, the smaller one will explode. If both are the same size, both will
 * explode. Two asteroids moving in the same direction will never meet.
 *
 *
 * Example 1:
 *
 *
 * Input: asteroids = [5,10,-5]
 * Output: [5,10]
 * Explanation: The 10 and -5 collide resulting in 10. The 5 and 10 never
 * collide.
 *
 *
 * Example 2:
 *
 *
 * Input: asteroids = [8,-8]
 * Output: []
 * Explanation: The 8 and -8 collide exploding each other.
 *
 *
 * Example 3:
 *
 *
 * Input: asteroids = [10,2,-5]
 * Output: [10]
 * Explanation: The 2 and -5 collide resulting in -5. The 10 and -5 collide
 * resulting in 10.
 *
 *
 *
 * Constraints:
 *
 *
 * 2 <= asteroids.length <= 10^4
 * -1000 <= asteroids[i] <= 1000
 * asteroids[i] != 0
 *
 *
 */

 // @lc code=start
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> res;
        for (int& asteroid : asteroids) {
            // 1. go right
            if (asteroid > 0) {
                res.push_back(asteroid);
            // 2. go left
            } else {
                // pop all right asteroid which are smaller than current asteroid
                while (res.size() && res.back() > 0 && res.back() < -asteroid) res.pop_back();
                // if there are equal asteroid go right, just delete it
                if (res.size() && res.back() == -asteroid) res.pop_back();
                // if res is empty or the rest asteroids are go left, just keep it
                else if (res.empty() || res.back() < 0) res.push_back(asteroid);
            }
        }
        return res;
    }
};
// @lc code=end

