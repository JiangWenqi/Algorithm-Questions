import java.io.*;
import java.util.*;

class Solution {

    static int findBusiestPeriod(int[][] data) {
        if (data.length == 1)
            return data[0][0];
        int timestamp = -1;
        int people = 0;
        int max = -1;
        for (int i = 0; i < data.length; i++) {
            int t = data[i][0];
            int p = data[i][1];
            int type = data[i][2];
            // 0 for exit
            if (type == 0) {
                people -= p;
            } else if (type == 1) {
                people += p;
            }
            if ((i != data.length - 1 && t != data[i + 1][0]) || i == data.length - 1) {
                if (max < people) {
                    max = people;
                    timestamp = t;
                }
            }

        }
        return timestamp;

    }

    public static void main(String[] args) {

    }

}
/*
 * put: data = [ [1487799425, 14, 1], i=0
 * [1487799425, 4, 0],i =1
 * [1487799425, 2, 0],i =2
 * [1487800378, 10, 1], i = 3
 * [1487801478, 18, 0], i = 4
 * [1487801478, 18, 1],
 * [1487901013, 1, 0],
 * [1487901211, 7, 1],
 * [1487901211, 7, 0] ]
 */


// timestamp, people, type(in or out)
// return the busy timestamp of this market
