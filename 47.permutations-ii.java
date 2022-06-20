import java.util.*;;
/*
 * @lc app=leetcode id=47 lang=java
 *
 * [47] Permutations II
 *
 * https://leetcode.com/problems/permutations-ii/description/
 *
 * algorithms
 * Medium (55.69%)
 * Likes:    5849
 * Dislikes: 101
 * Total Accepted:    663.8K
 * Total Submissions: 1.2M
 * Testcase Example:  '[1,1,2]'
 *
 * Given a collection of numbers, nums, that might contain duplicates, return
 * all possible unique permutations in any order.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [1,1,2]
 * Output:
 * [[1,1,2],
 * ⁠[1,2,1],
 * ⁠[2,1,1]]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [1,2,3]
 * Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 8
 * -10 <= nums[i] <= 10
 * 
 * 
 */

// @lc code=start
class Solution {

    boolean[] used;
    LinkedList<Integer> child = new LinkedList<>();
    List<List<Integer>> ans = new LinkedList<>();

    private void dfs(int[] nums, int u) {
        int n = nums.length;
        if (u == n) {
            ans.add(new LinkedList<>(child));
            return;
        }
        for (int i = 0; i < n; i++) {
            // 当前元素若已使用过，则直接跳过
            if (!used[i]) {
                // 说明前面一个重复的元素还没有使用
                if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1])
                    continue;
                used[i] = true;
                child.add(nums[i]);
                dfs(nums, u + 1);
                child.removeLast();
                used[i] = false;
            }
        }
    }

    public List<List<Integer>> permuteUnique(int[] nums) {
        int n = nums.length;
        if (n == 0)
            return ans;
        used = new boolean[n];
        // 记得排序
        Arrays.sort(nums);
        dfs(nums, 0);
        return ans;
    }

}
// @lc code=end
