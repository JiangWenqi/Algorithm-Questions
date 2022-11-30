/*
 * @lc app=leetcode id=1207 lang=cpp
 *
 * [1207] Unique Number of Occurrences
 *
 * https://leetcode.com/problems/unique-number-of-occurrences/description/
 *
 * algorithms
 * Easy (70.90%)
 * Likes:    2936
 * Dislikes: 62
 * Total Accepted:    230.2K
 * Total Submissions: 312.7K
 * Testcase Example:  '[1,2,2,1,1,3]'
 *
 * Given an array of integers arr, return true if the number of occurrences of
 * each value in the array is unique, or false otherwise.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: arr = [1,2,2,1,1,3]
 * Output: true
 * Explanation: The value 1 has 3 occurrences, 2 has 2 and 3 has 1. No two
 * values have the same number of occurrences.
 * 
 * Example 2:
 * 
 * 
 * Input: arr = [1,2]
 * Output: false
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: arr = [-3,0,1,-3,1,1,1,-3,10,0]
 * Output: true
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= arr.length <= 1000
 * -1000 <= arr[i] <= 1000
 * 
 * 
 */

// @lc code=start
class Solution
{
    public:
        bool uniqueOccurrences(vector<int> &arr)
        {
            unordered_map<int, int> counter;
            unordered_set<int> checker;
            for (int &num: arr) counter[num]++;
            for (auto[k, v]: counter)
            {
                if (checker.count(v)) return false;
                else checker.insert(v);
            }
            return true;
        }
};
// @lc code=end

