/*
 * @lc app=leetcode id=125 lang=java
 *
 * [125] Valid Palindrome
 *
 * https://leetcode.com/problems/valid-palindrome/description/
 *
 * algorithms
 * Easy (30.40%)
 * Total Accepted:    331.8K
 * Total Submissions: 1.1M
 * Testcase Example:  '"A man, a plan, a canal: Panama"'
 *
 * Given a string, determine if it is a palindrome, considering only
 * alphanumeric characters and ignoring cases.
 * 
 * Note: For the purpose of this problem, we define empty string as valid
 * palindrome.
 * 
 * Example 1:
 * 
 * 
 * Input: "A man, a plan, a canal: Panama"
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "race a car"
 * Output: false
 * 
 * 
 */
class Solution {
	public boolean isPalindrome(String s) {
		if (s.isEmpty())
			return true;
		int start = 0, tail = s.length() - 1;
		char cStart, cTail;
		while (start <= tail) {
			cStart = s.charAt(start);
			cTail = s.charAt(tail);

			if (!Character.isLetterOrDigit(cStart)) {
				start++;
			} else if (!Character.isLetterOrDigit(cTail)) {
				tail--;
			} else {
				if (Character.toLowerCase(cStart) != Character.toLowerCase(cTail))
					return false;
				start++;
				tail--;
			}
		}
		return true;
	}
}
