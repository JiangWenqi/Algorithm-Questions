import java.util.ArrayList;
import java.util.List;

/*
 * @lc app=leetcode id=17 lang=java
 *
 * [17] Letter Combinations of a Phone Number
 *
 * https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/
 *
 * algorithms
 * Medium (54.97%)
 * Likes:    11926
 * Dislikes: 735
 * Total Accepted:    1.3M
 * Total Submissions: 2.4M
 * Testcase Example:  '"23"'
 *
 * Given a string containing digits from 2-9 inclusive, return all possible
 * letter combinations that the number could represent. Return the answer in
 * any order.
 * 
 * A mapping of digits to letters (just like on the telephone buttons) is given
 * below. Note that 1 does not map to any letters.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: digits = "23"
 * Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: digits = ""
 * Output: []
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: digits = "2"
 * Output: ["a","b","c"]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 0 <= digits.length <= 4
 * digits[i] is a digit in the range ['2', '9'].
 * 
 * 
 */

// @lc code=start
class Solution {
    String symbols[] = {
            "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
    };
    List<String> res = new ArrayList<>();

    private void dfs(int start, String path, String digits) {
        if (start == digits.length())
            res.add(path);
        else {
            for (char c : symbols[digits.charAt(start) - '0'].toCharArray()) {
                dfs(start + 1, path + c, digits);
            }
        }
    }

    public List<String> letterCombinations(String digits) {
        if (digits.isEmpty())
            return res;
        dfs(0, "", digits);
        return res;
    }
}
// @lc code=end
