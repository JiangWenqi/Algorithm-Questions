/*
 * @lc app=leetcode id=127 lang=cpp
 *
 * [127] Word Ladder
 *
 * https://leetcode.com/problems/word-ladder/description/
 *
 * algorithms
 * Hard (36.64%)
 * Likes:    9313
 * Dislikes: 1735
 * Total Accepted:    855.5K
 * Total Submissions: 2.3M
 * Testcase Example:  '"hit"\n"cog"\n["hot","dot","dog","lot","log","cog"]'
 *
 * A transformation sequence from word beginWord to word endWord using a
 * dictionary wordList is a sequence of words beginWord -> s1 -> s2 -> ... ->
 * sk such that:
 *
 *
 * Every adjacent pair of words differs by a single letter.
 * Every si for 1 <= i <= k is in wordList. Note that beginWord does not need
 * to be in wordList.
 * sk == endWord
 *
 *
 * Given two words, beginWord and endWord, and a dictionary wordList, return
 * the number of words in the shortest transformation sequence from beginWord
 * to endWord, or 0 if no such sequence exists.
 *
 *
 * Example 1:
 *
 *
 * Input: beginWord = "hit", endWord = "cog", wordList =
 * ["hot","dot","dog","lot","log","cog"]
 * Output: 5
 * Explanation: One shortest transformation sequence is "hit" -> "hot" -> "dot"
 * -> "dog" -> cog", which is 5 words long.
 *
 *
 * Example 2:
 *
 *
 * Input: beginWord = "hit", endWord = "cog", wordList =
 * ["hot","dot","dog","lot","log"]
 * Output: 0
 * Explanation: The endWord "cog" is not in wordList, therefore there is no
 * valid transformation sequence.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= beginWord.length <= 10
 * endWord.length == beginWord.length
 * 1 <= wordList.length <= 5000
 * wordList[i].length == beginWord.length
 * beginWord, endWord, and wordList[i] consist of lowercase English
 * letters.
 * beginWord != endWord
 * All the words in wordList are unique.
 *
 *
 */

// @lc code=start
class Solution
{
private:
    unordered_set<string> words;
    unordered_map<string, int> dist;
    queue<string> q;

public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        for (auto &word : wordList)
            words.insert(word);
        dist[beginWord] = 1;
        q.push(beginWord);
        while (!q.empty())
        {
            string word = q.front();
            q.pop();
            string temp;
            for (int i = 0; i < word.size(); i++)
            {
                temp = word;
                for (char c = 'a'; c <= 'z'; c++)
                {
                    if (c != word[i])
                    {
                        temp[i] = c;
                        if (words.count(temp) && !dist.count(temp))
                        {
                            dist[temp] = dist[word] + 1;
                            if (temp == endWord)
                                return dist[temp];
                            q.push(temp);
                        }
                    }
                }
            }
        }
        return 0;
    }
};
// @lc code=end
