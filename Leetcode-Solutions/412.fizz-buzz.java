import java.util.ArrayList;
import java.util.List;

/*
 * @lc app=leetcode id=412 lang=java
 *
 * [412] Fizz Buzz
 */

// @lc code=start
class Solution {
    public List<String> fizzBuzz(int n) {
        List<String> ans = new ArrayList<>();

        for (int i = 1; i <= n; i++) {
            String str = "";
            boolean divisibleBy3 = i % 3 == 0;
            boolean divisibleBy5 = i % 5 == 0;

            if (divisibleBy3 && divisibleBy5) {
                str = "FizzBuzz";
            } else if (divisibleBy3) {
                str = "Fizz";
            } else if (divisibleBy5) {
                str = "Buzz";
            } else {
                str = String.valueOf(i);
            }

            ans.add(str);
        }
        return ans;
    }
}
// @lc code=end
