import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;

/*
 * @lc app=leetcode id=692 lang=java
 *
 * [692] Top K Frequent Words
 */

// @lc code=start
class Solution {
    public List<String> topKFrequent(String[] words, int k) {
        HashMap<String, Integer> map = new HashMap<>(words.length);
        for (String word : words) {
            map.put(word, map.getOrDefault(word, 0) + 1);
        }
        ArrayList<String> uniqueWords = new ArrayList<>(map.keySet());
        uniqueWords.sort((a, b) -> {
            if (map.get(a).equals(map.get(b))) {
                return a.compareTo(b);
            } else {
                return map.get(b) - map.get(a);
            }
        });
        return uniqueWords.subList(0, k);
    }
}
// @lc code=end
