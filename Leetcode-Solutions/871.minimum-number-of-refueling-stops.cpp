// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem871.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=871 lang=cpp
 *
 * [871] Minimum Number of Refueling Stops
 *
 * https://leetcode.com/problems/minimum-number-of-refueling-stops/description/
 *
 * algorithms
 * Hard (36.00%)
 * Likes:    3248
 * Dislikes: 60
 * Total Accepted:    88.1K
 * Total Submissions: 234.4K
 * Testcase Example:  '1\n1\n[]'
 *
 * A car travels from a starting position to a destination which is target
 * miles east of the starting position.
 *
 * There are gas stations along the way. The gas stations are represented as an
 * array stations where stations[i] = [positioni, fueli] indicates that the
 * i^th gas station is positioni miles east of the starting position and has
 * fueli liters of gas.
 *
 * The car starts with an infinite tank of gas, which initially has startFuel
 * liters of fuel in it. It uses one liter of gas per one mile that it drives.
 * When the car reaches a gas station, it may stop and refuel, transferring all
 * the gas from the station into the car.
 *
 * Return the minimum number of refueling stops the car must make in order to
 * reach its destination. If it cannot reach the destination, return -1.
 *
 * Note that if the car reaches a gas station with 0 fuel left, the car can
 * still refuel there. If the car reaches the destination with 0 fuel left, it
 * is still considered to have arrived.
 *
 *
 * Example 1:
 *
 *
 * Input: target = 1, startFuel = 1, stations = []
 * Output: 0
 * Explanation: We can reach the target without refueling.
 *
 *
 * Example 2:
 *
 *
 * Input: target = 100, startFuel = 1, stations = [[10,100]]
 * Output: -1
 * Explanation: We can not reach the target (or even the first gas station).
 *
 *
 * Example 3:
 *
 *
 * Input: target = 100, startFuel = 10, stations =
 * [[10,60],[20,30],[30,30],[60,40]]
 * Output: 2
 * Explanation: We start with 10 liters of fuel.
 * We drive to position 10, expending 10 liters of fuel.  We refuel from 0
 * liters to 60 liters of gas.
 * Then, we drive from position 10 to position 60 (expending 50 liters of
 * fuel),
 * and refuel from 10 liters to 50 liters of gas.  We then drive to and reach
 * the target.
 * We made 2 refueling stops along the way, so we return 2.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= target, startFuel <= 10^9
 * 0 <= stations.length <= 500
 * 0 <= positioni <= positioni+1 < target
 * 1 <= fueli < 10^9
 *
 *
 */

 // @lc code=start
class Solution {
public:
    int minRefuelStops(int target, int start, vector<vector<int>>& stations) {
        // 1. add target to stations
        stations.push_back({ target, 0 });
        // 2. init result (stops) and backup stations
        int res = 0;
        priority_queue<int> heap;
        // 3. travel all stations
        for (auto& station : stations) {
            int pos = station[0], fuel = station[1];
            // we can't reach this postion
            while (start < pos) {
                // and the backup stations are not empty
                if (heap.size()) {
                    start += heap.top();
                    heap.pop();
                    res++;
                } else {
                    return -1;
                }
            }
            // we can reach this postion and add it to backup stations
            heap.push(fuel);
        }
        return res;
    }
};
// @lc code=end

