// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem126.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=126 lang=cpp
 *
 * [126] Word Ladder II
 *
 * https://leetcode.com/problems/word-ladder-ii/description/
 *
 * algorithms
 * Hard (27.02%)
 * Likes:    4168
 * Dislikes: 461
 * Total Accepted:    304.9K
 * Total Submissions: 1.1M
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
 * all the shortest transformation sequences from beginWord to endWord, or an
 * empty list if no such sequence exists. Each sequence should be returned as a
 * list of the words [beginWord, s1, s2, ..., sk].
 *
 *
 * Example 1:
 *
 *
 * Input: beginWord = "hit", endWord = "cog", wordList =
 * ["hot","dot","dog","lot","log","cog"]
 * Output: [["hit","hot","dot","dog","cog"],["hit","hot","lot","log","cog"]]
 * Explanation: There are 2 shortest transformation sequences:
 * "hit" -> "hot" -> "dot" -> "dog" -> "cog"
 * "hit" -> "hot" -> "lot" -> "log" -> "cog"
 *
 *
 * Example 2:
 *
 *
 * Input: beginWord = "hit", endWord = "cog", wordList =
 * ["hot","dot","dog","lot","log"]
 * Output: []
 * Explanation: The endWord "cog" is not in wordList, therefore there is no
 * valid transformation sequence.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= beginWord.length <= 5
 * endWord.length == beginWord.length
 * 1 <= wordList.length <= 500
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
    vector<vector<string>> res;
    vector<string> path;
    string start;
    void dfs(string word)
    {
        if (word == start)
        {
            reverse(path.begin(), path.end());
            res.push_back(path);
            reverse(path.begin(), path.end());
        }
        else
        {
            string temp;
            for (int i = 0; i < word.size(); i++)
            {
                temp = word;
                for (char c = 'a'; c <= 'z'; c++)
                {
                    temp[i] = c;
                    if (dist.count(temp) && dist[temp] + 1 == dist[word])
                    {
                        path.push_back(temp);
                        dfs(temp);
                        path.pop_back();
                    }
                }
            }
        }
    }

public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList)
    {
        for (auto word : wordList)
            words.insert(word);
        dist[beginWord] = 0;
        queue<string> q;
        q.push(beginWord);
        while (q.size())
        {
            auto word = q.front();
            q.pop();
            string temp;
            for (int i = 0; i < word.size(); i++)
            {
                temp = word;
                for (char c = 'a'; c <= 'z'; c++)
                {
                    temp[i] = c;
                    if (words.count(temp) && dist.count(temp) == 0)
                    {
                        dist[temp] = dist[word] + 1;
                        if (temp == endWord)
                            break;
                        q.push(temp);
                    }
                }
            }
        }

        if (dist.count(endWord) == 0)
            return res;
        start = beginWord;
        path.push_back(endWord);
        dfs(endWord);
        return res;
    }
};

// @lc code=end
