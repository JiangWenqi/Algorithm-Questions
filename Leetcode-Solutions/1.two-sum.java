import java.util.HashMap;

class Solution {
	public int[] twoSum(int[] nums, int target) {

		HashMap<Integer, Integer> map = new HashMap<>();
		for (int i = 0; i < nums.length; i++) {
			int num = nums[i];
			if (map.containsKey(target - num)) {
				int index = map.get(target - num);
				return new int[] { i, index };
			} else {
				map.put(num, i);
			}
		}
		return null;
	}
}
