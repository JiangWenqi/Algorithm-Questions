import java.io.*;
import java.util.*;

class Solution {
    static String decrypt(String word) {
        String s = "";
        int oldValue = 1, newValue;
        for (int i = 0; i < word.length(); i++) {
            newValue = word.charAt(i) - oldValue;
            oldValue = word.charAt(i);
            while (newValue < 'a') {
                newValue += 26;
            }
            s = s + (char) newValue;
        }
        return s;
    }

    public static void main(String[] args) {

    }

}