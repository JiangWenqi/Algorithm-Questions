import java.util.Random;

/*
 * @lc app=leetcode id=384 lang=java
 *
 * [384] Shuffle an Array
 */

// @lc code=start
class Solution {

    private int[] original;
    private final static Random RANDOM = new Random();

    public Solution(int[] nums) {
        original = nums;
    }

    /** Resets the array to its original configuration and return it. */
    public int[] reset() {
        return original;
    }

    /** Returns a random shuffling of the array. */
    public int[] shuffle() {
        // copy the original array
        int[] copy = original.clone();

        for (int i = 0; i < copy.length; i++) {
            // find random index in the array
            int index = RANDOM.nextInt(copy.length);

            // swap current element with random
            int tmp = copy[i];
            copy[i] = copy[index];
            copy[index] = tmp;
        }
        return copy;
    }
}

/**
 * Your Solution object will be instantiated and called as such: Solution obj =
 * new Solution(nums); int[] param_1 = obj.reset(); int[] param_2 =
 * obj.shuffle();
 */
// @lc code=end
