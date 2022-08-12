import java.io.*;
import java.util.*;

class Solution {

    static int deletionDistance(String str1, String str2) {
        int length1 = str1.length(), length2 = str2.length();
        int[][] dp = new int[length1 + 1][length2 + 1];

        // init
        for (int i = 1; i <= length1; i++) {
            dp[i][0] = i;
        }
        for (int i = 1; i <= length2; i++) {
            dp[0][i] = i;
        }

        for (int i = 1; i <= length1; i++) {
            for (int j = 1; j <= length2; j++) {
                if (str1.charAt(i - 1) == str2.charAt(j - 1)) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = 1 + Math.min(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        return dp[length1][length2];
    }

    public static void main(String[] args) {
        int count = deletionDistance("dog", "frog");
        System.out.println(count);
    }
}

