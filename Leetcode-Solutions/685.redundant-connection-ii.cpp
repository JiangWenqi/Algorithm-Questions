/*
 * @lc app=leetcode id=685 lang=cpp
 *
 * [685] Redundant Connection II
 *
 * https://leetcode.com/problems/redundant-connection-ii/description/
 *
 * algorithms
 * Hard (34.08%)
 * Likes:    1880
 * Dislikes: 286
 * Total Accepted:    57.7K
 * Total Submissions: 169.4K
 * Testcase Example:  '[[1,2],[1,3],[2,3]]'
 *
 * In this problem, a rooted tree is a directed graph such that, there is
 * exactly one node (the root) for which all other nodes are descendants of
 * this node, plus every node has exactly one parent, except for the root node
 * which has no parents.
 *
 * The given input is a directed graph that started as a rooted tree with n
 * nodes (with distinct values from 1 to n), with one additional directed edge
 * added. The added edge has two different vertices chosen from 1 to n, and was
 * not an edge that already existed.
 *
 * The resulting graph is given as a 2D-array of edges. Each element of edges
 * is a pair [ui, vi] that represents a directed edge connecting nodes ui and
 * vi, where ui is a parent of child vi.
 *
 * Return an edge that can be removed so that the resulting graph is a rooted
 * tree of n nodes. If there are multiple answers, return the answer that
 * occurs last in the given 2D-array.
 *
 *
 * Example 1:
 *
 *
 * Input: edges = [[1,2],[1,3],[2,3]]
 * Output: [2,3]
 *
 *
 * Example 2:
 *
 *
 * Input: edges = [[1,2],[2,3],[3,4],[4,1],[1,5]]
 * Output: [4,1]
 *
 *
 *
 * Constraints:
 *
 *
 * n == edges.length
 * 3 <= n <= 1000
 * edges[i].length == 2
 * 1 <= ui, vi <= n
 * ui != vi
 *
 *
 */

// @lc code=start
class Solution
{
private:
    int n; // 边数
    //某个边是否在环里，某条边是否某个点的两个入边之一，找环的时候判重数组，某个点是否在栈里，某个点是否在环里。
    vector<bool> st1, st2, st, in_k, in_c;
    vector<vector<int>> g; //开一个邻接表来存所有的边
    stack<int> stk;

    //找环函数
    bool dfs(int u)
    {
        st[u] = true;                //标记这个点被遍历过了
        stk.push(u), in_k[u] = true; // u放进栈里，所以它在栈里in_k(u)=在的
        // 枚举出点
        for (int x : g[u])
        {
            if (!st[x])
            {
                if (dfs(x))
                    return true; //如果找到环 return true
            }
            else if (in_k[x]) //如果x是在栈里
            {
                //还需把环里所有点找出来
                while (stk.top() != x)
                {                           //一直弹栈
                    in_c[stk.top()] = true; //都在环里，标记
                    stk.pop();
                }
                in_c[x] = true; //最后标记x也在环里
                return true;    //找到环了
            }
        }
        stk.pop(), in_k[u] = false; //最后弹栈
        return false;
    }
    void work1(vector<vector<int>> &edges)
    {
        //先初始化邻接表
        for (auto &e : edges)
        {
            int a = e[0], b = e[1];
            g[a].push_back(b); //
        }
        // 枚举（遍历这个图）直到找到环
        for (int i = 1; i <= n; i++)
            if (!st[i] && dfs(i))
                break;
        for (int i = 0; i < n; i++)
        {
            int a = edges[i][0], b = edges[i][1];
            if (in_c[a] && in_c[b]) //如果这(构成ab边的)两个点a和b都在环里
                st1[i] = true;      //说明这个边在环里
        }
    }
    void work2(vector<vector<int>> &edges)
    {
        vector<int> p(n + 1, -1); //初始化每个点的入边。 初始化为-1
        //从前往后枚举所有边
        for (int i = 0; i < n; i++)
        {
            int a = edges[i][0], b = edges[i][1]; // 这个边的第一个点a，第二个点b
            if (p[b] != -1)
            {                              //如果这个点已经存过某条入边的话。
                st2[p[b]] = st2[i] = true; // 两个入边标记一下。
                //入边p[b]是某个点的两条入边
                // 这个研究一下s[p[b]]的含义 和这个循环的作用
                break;
            }
            else
                p[b] = i; //否则入边标记为i
        }
    }

public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>> &edges)
    {
        // 有向树有很多情况。3
        // ①【只有环】 有一个子节点连到了根节点 ---》奇环树，去掉环上任意一条边都行
        // ② 【无环，但有个点入度为2】 (出现了两个根节点)，任意去除入度2的任意一边
        // ③【以上①②都有】只能去掉①②公共边。既在环里，又是某个点的2条入边之一
        // st1[i] 表示：第i条边在环里
        // st2[i] 表示：两条入边之一
        // 解：从后往前找第一个i，使得st1[i],st2[i] = true.
        // targan算法 找出每条边是否在图里。
        // 此题特殊：一棵树里带了一个环。 所以写简化版即可。
        // dfs根节点到该点肯定会路过它的祖先节点。
        // stk 栈存一下dfs上的点
        // in_stk[] bool布尔数组存某个点是否在栈里
        // 所以【搜的时候，如果找到了栈当中的点，那么就找到了环】
        // O(N)
        // 【实际为找环模板题】
        n = edges.size();
        //初始化。长度n+1
        st1 = st2 = st = in_k = in_c = vector<bool>(n + 1);
        g.resize(n + 1);
        work1(edges);
        work2(edges);

        //枚举一下，看是否是情况③，即情况①和情况②都满足
        for (int i = n - 1; i >= 0; i--)
            if (st1[i] && st2[i]) //如果edge(i)既是st1也是st2的边
                return edges[i];  //返回这个，即情况③

        //否则，说明是情况一或情况二。找最后一边即可。
        for (int i = n - 1; i >= 0; i--)
            if (st1[i] || st2[i]) //第一个集合或者第二个集合出现的话。当前边就是答案。
                return edges[i];
        return {}; //这个不执行，只是lc格式
    }
};
// @lc code=end
