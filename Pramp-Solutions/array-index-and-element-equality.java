
/*
 * Given a sorted array arr of distinct integers, write a function
 * indexEqualsValueSearch that returns the lowest index i for which arr[i] == i.
 * Return -1 if there is no such index. Analyze the time and space complexities
 * of your solution and explain its correctness.
 * 
 * Examples:
 * 
 * input: arr = [-8,0,2,5]
 * output: 2 # since arr[2] == 2
 * 
 * input: arr = [-1,0,3,6]
 * output: -1 # since no index in arr satisfies arr[i] == i.
 * Constraints:
 * 
 * [time limit] 5000ms
 * 
 * [input] array.integer arr
 * 
 * 1 ≤ arr.length ≤ 100
 * [output] integer
 */
import java.io.*;
import java.util.*;

class Solution {

    static int indexEqualsValueSearch(int[] arr) {
        int l = 0, r = arr.length - 1;
        while (l < r) {
            int mid = (l + r) / 2;
            if (arr[mid] >= mid)
                r = mid;
            else
                l = mid + 1;
        }
        return arr[l] == l ? l : -1;
    }

    public static void main(String[] args) {

    }

}