/*
 * @lc app=leetcode id=108 lang=java
 *
 * [108] Convert Sorted Array to Binary Search Tree
 *
 * https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/description/
 *
 * algorithms
 * Easy (49.53%)
 * Total Accepted:    244.4K
 * Total Submissions: 492.7K
 * Testcase Example:  '[-10,-3,0,5,9]'
 *
 * Given an array where elements are sorted in ascending order, convert it to a
 * height balanced BST.
 * 
 * For this problem, a height-balanced binary tree is defined as a binary tree
 * in which the depth of the two subtrees of every node never differ by more
 * than 1.
 * 
 * Example:
 * 
 * 
 * Given the sorted array: [-10,-3,0,5,9],
 * 
 * One possible answer is: [0,-3,9,-10,null,5], which represents the following
 * height balanced BST:
 * 
 * ⁠     0
 * ⁠    / \
 * ⁠  -3   9
 * ⁠  /   /
 * ⁠-10  5
 * 
 * 
 */
/**
 * Definition for a binary tree node. public class TreeNode { int val; TreeNode
 * left; TreeNode right; TreeNode(int x) { val = x; } }
 */
class Solution {
	public TreeNode sortedArrayToBST(int[] nums) {

		return getMidNode(nums, 0, nums.length - 1);

	}

	private TreeNode getMidNode(int[] nums, int left, int right) {

		if (left > right)
			return null;
		int mid = left + right >> 1;
		TreeNode midNode = new TreeNode(nums[mid]);
		midNode.left = getMidNode(nums, left, mid - 1);
		midNode.right = getMidNode(nums, mid + 1, right);
		return midNode;

	}

}
