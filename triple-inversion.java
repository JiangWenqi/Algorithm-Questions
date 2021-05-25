import java.util.*;

class Solution {
    public int solve(int[] nums) {
        int result = 0;

        ArrayList<Integer> sortedNumbers = new ArrayList<>();

        for (int i = 0; i < nums.length; i++) {
            int leftBorder = findLeftBorder(sortedNumbers, nums[i] * 3);
            result += i - leftBorder;
            int insertIndex = findLeftBorder(sortedNumbers, nums[i]);
            sortedNumbers.add(insertIndex, nums[i]);
        }
        return result;
    }

    private int findLeftBorder(List<Integer> sortedNumbers, int target) {
        int left = 0, right = sortedNumbers.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (sortedNumbers.get(mid) <= target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return left;
    }
}