// @before-stub-for-debug-begin
#include <string>
#include <unordered_set>>
#include <vector>

#include "commoncppproblem260.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=260 lang=cpp
 *
 * [260] Single Number III
 *
 * https://leetcode.com/problems/single-number-iii/description/
 *
 * algorithms
 * Medium (67.21%)
 * Likes:    3933
 * Dislikes: 186
 * Total Accepted:    256.6K
 * Total Submissions: 381.8K
 * Testcase Example:  '[1,2,1,3,2,5]'
 *
 * Given an integer array nums, in which exactly two elements appear only once
 * and all the other elements appear exactly twice. Find the two elements that
 * appear only once. You can return the answer in any order.
 *
 * You must write an algorithm that runs in linear runtime complexity and uses
 * only constant extra space.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [1,2,1,3,2,5]
 * Output: [3,5]
 * Explanation:  [5, 3] is also a valid answer.
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [-1,0]
 * Output: [-1,0]
 *
 *
 * Example 3:
 *
 *
 * Input: nums = [0,1]
 * Output: [1,0]
 *
 *
 *
 * Constraints:
 *
 *
 * 2 <= nums.length <= 3 * 10^4
 * -2^31 <= nums[i] <= 2^31 - 1
 * Each integer in nums will appear twice, only two integers will appear once.
 *
 *
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
 private:
  int get(int flag, int idx, vector<int>& nums) {
    int res = 0;
    for (auto num : nums) {
      if ((num >> idx & 1) == flag) res ^= num;
    }
    return res;
  }

 public:
  vector<int> singleNumber(vector<int>& nums) {
    int ab = 0;
    for (int& num : nums) ab ^= num;
    int idx = 0;
    while ((ab >> idx & 1) == 0) idx++;
    return {get(0, idx, nums), get(1, idx, nums)};
  }
};
/* class Solution {
 public:
  vector<int> singleNumber(vector<int>& nums) {
    vector<int> res;
    unordered_set<int> s;
    for (int& num : nums) {
      if (s.count(num) == 0)
        s.insert(num);
      else
        s.erase(num);
    }
    for (const int& num : s) res.push_back(num);
    return res;
  }
}; */
// @lc code=end
