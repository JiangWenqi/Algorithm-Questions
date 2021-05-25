/*
 * @lc app=leetcode id=1456 lang=java
 *
 * [1456] Maximum Number of Vowels in a Substring of Given Length
 */

// @lc code=start
class Solution {
    public int maxVowels(String s, int k) {
        int vowelNumber = 0;
        for (int i = 0; i < k; i++) {
            if(isVowel(s.charAt(i))) vowelNumber++;
        }

        int maxVowelNumber = vowelNumber;
        for (int i = k; i < s.length(); i++) {
            if (isVowel(s.charAt(i))) vowelNumber++;
            if (isVowel(s.charAt(i-k))) vowelNumber--;
            maxVowelNumber = Math.max(maxVowelNumber, vowelNumber);

        }
        return maxVowelNumber;
    }

    private boolean isVowel(char c) {
        if((c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')) return true;
        return false;
    }
}
// @lc code=end

