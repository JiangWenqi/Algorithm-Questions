import java.util.Stack;

/*
 * @lc app=leetcode id=735 lang=java
 *
 * [735] Asteroid Collision
 *
 * https://leetcode.com/problems/asteroid-collision/description/
 *
 * algorithms
 * Medium (44.36%)
 * Likes:    4211
 * Dislikes: 354
 * Total Accepted:    233.7K
 * Total Submissions: 526.7K
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
    public int[] asteroidCollision(int[] asteroids) {
        Stack<Integer> stk = new Stack<>();
        for (int asteroid : asteroids) {
            if (asteroid > 0) {
                stk.push(asteroid);
            } else {
                while (!stk.empty() && stk.peek() + asteroid < 0)
                    stk.pop();
                if (!stk.empty() && stk.peek() + asteroid == 0)
                    stk.pop();
                else if (stk.empty() || stk.peek() < 0)
                    stk.push(asteroid);
            }
        }
        int[] res = new int[stk.size()];
        for (int i = 0; i < stk.size(); i++) {
            res[i] = stk.get(i);
        }
        return res;
    }
}
// @lc code=end
