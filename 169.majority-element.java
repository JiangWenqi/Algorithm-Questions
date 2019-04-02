/*
 * @lc app=leetcode id=169 lang=java
 *
 * [169] Majority Element
 *
 * https://leetcode.com/problems/majority-element/description/
 *
 * algorithms
 * Easy (51.73%)
 * Total Accepted:    361.8K
 * Total Submissions: 696.8K
 * Testcase Example:  '[3,2,3]'
 *
 * Given an array of size n, find the majority element. The majority element is
 * the element that appears more than ⌊ n/2 ⌋ times.
 * 
 * You may assume that the array is non-empty and the majority element always
 * exist in the array.
 * 
 * Example 1:
 * 
 * 
 * Input: [3,2,3]
 * Output: 3
 * 
 * Example 2:
 * 
 * 
 * Input: [2,2,1,1,1,2,2]
 * Output: 2
 * 
 * 
 */
class Solution {
    public int majorityElement(int[] nums) {
		int count = 0, result = 0;
		for (int num: nums) {
			if (count == 0) {
				result = num;
				count = 1;
			}else if (result == num) {
				count ++;
			}else {
				count --;
			}
		}
		return result;
    }
}
