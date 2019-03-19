class Solution {
    public int[] twoSum(int[] nums, int target) {
	int[] result = new int[2];
	HashMap<Integer,Integer> map = new HashMap<>(nums.length);
	for (int i = 0; i < nums.length; i++) {
		if (map.containsKey(target - nums[i])) {
			if (i > map.get(target - nums[i])) {
				result[0] = map.get(target - nums[i]);
				result[1] = i;
			} else {
				result[0] = i;
				result[1] = map.get(target - nums[i]);
			}
				 
	
		} else {
			map.put(nums[i], i);
		}
	}
	return result;        
    }

}
