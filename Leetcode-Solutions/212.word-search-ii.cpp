/*
 * @lc app=leetcode id=212 lang=cpp
 *
 * [212] Word Search II
 *
 * https://leetcode.com/problems/word-search-ii/description/
 *
 * algorithms
 * Hard (36.88%)
 * Likes:    7431
 * Dislikes: 326
 * Total Accepted:    504.2K
 * Total Submissions: 1.4M
 * Testcase Example:  '[["o","a","a","n"],["e","t","a","e"],["i","h","k","r"],["i","f","l","v"]]\n' +
  '["oath","pea","eat","rain"]'
 *
 * Given an m x n board of characters and a list of strings words, return all
 * words on the board.
 *
 * Each word must be constructed from letters of sequentially adjacent cells,
 * where adjacent cells are horizontally or vertically neighboring. The same
 * letter cell may not be used more than once in a word.
 *
 *
 * Example 1:
 *
 *
 * Input: board =
 * [["o","a","a","n"],["e","t","a","e"],["i","h","k","r"],["i","f","l","v"]],
 * words = ["oath","pea","eat","rain"]
 * Output: ["eat","oath"]
 *
 *
 * Example 2:
 *
 *
 * Input: board = [["a","b"],["c","d"]], words = ["abcb"]
 * Output: []
 *
 *
 *
 * Constraints:
 *
 *
 * m == board.length
 * n == board[i].length
 * 1 <= m, n <= 12
 * board[i][j] is a lowercase English letter.
 * 1 <= words.length <= 3 * 10^4
 * 1 <= words[i].length <= 10
 * words[i] consists of lowercase English letters.
 * All the strings of words are unique.
 *
 *
 */

// @lc code=start
class Solution
{
private:
    struct Node
    {
        int id;
        Node *children[26];
        Node()
        {
            id = -1;
            for (int i = 0; i < 26; i++)
                children[i] = NULL;
        }
    } * root;
    int dirs[5] = {0, 1, 0, -1, 0};

    unordered_set<int> ids;
    int n, m;

    /**
     * insert word to the tire tree
     */
    void insert(int id, string &word)
    {
        Node *node = root;
        for (auto c : word)
        {
            int idx = c - 'a';
            if (!node->children[idx])
                node->children[idx] = new Node();
            node = node->children[idx];
        }
        node->id = id;
    }

    
    void dfs(int x, int y, vector<vector<char>> &board, Node *node)
    {
        if (node->id != -1)
            ids.insert(node->id);
        char c = board[x][y];
        board[x][y] = '.';
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dirs[i], ny = y + dirs[i + 1];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && board[nx][ny] != '.')
            {
                int idx = board[nx][ny] - 'a';
                if (node->children[idx])
                    dfs(nx, ny, board, node->children[idx]);
            }
        }
        board[x][y] = c;
    }

public:
    vector<string> findWords(vector<vector<char>> &board, vector<string> &words)
    {
        board = board;
        n = board.size(), m = board[0].size();
        root = new Node();
        for (int i = 0; i < words.size(); i++)
            insert(i, words[i]);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int idx = board[i][j] - 'a';
                if (root->children[idx])
                    dfs(i, j, board, root->children[idx]);
            }
        }
        vector<string> res;
        for (int id : ids)
            res.push_back(words[id]);
        return res;
    }
};
// @lc code=end
