class Solution {
    public int[] twoSum(int[] nums, int target) {
	int length = nums.length;	
	HashMap<Integer,Integer> map = new HashMap<>(length);
	for (int i = 0; i < length; i++) {
		if (map.containsKey(nums[i])) {
			int left = map.get(nums[i]);
			return new int[]{left, i};
		} else {
			map.put(target - nums[i], i);
		}
	}
	return new int[2];        
    }

}
