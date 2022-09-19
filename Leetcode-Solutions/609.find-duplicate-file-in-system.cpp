/*
 * @lc app=leetcode id=609 lang=cpp
 *
 * [609] Find Duplicate File in System
 *
 * https://leetcode.com/problems/find-duplicate-file-in-system/description/
 *
 * algorithms
 * Medium (64.03%)
 * Likes:    1057
 * Dislikes: 1209
 * Total Accepted:    113K
 * Total Submissions: 172.5K
 * Testcase Example:  '["root/a 1.txt(abcd) 2.txt(efgh)","root/c 3.txt(abcd)","root/c/d 4.txt(efgh)","root 4.txt(efgh)"]'
 *
 * Given a list paths of directory info, including the directory path, and all
 * the files with contents in this directory, return all the duplicate files in
 * the file system in terms of their paths. You may return the answer in any
 * order.
 *
 * A group of duplicate files consists of at least two files that have the same
 * content.
 *
 * A single directory info string in the input list has the following
 * format:
 *
 *
 * "root/d1/d2/.../dm f1.txt(f1_content) f2.txt(f2_content) ...
 * fn.txt(fn_content)"
 *
 *
 * It means there are n files (f1.txt, f2.txt ... fn.txt) with content
 * (f1_content, f2_content ... fn_content) respectively in the directory
 * "root/d1/d2/.../dm". Note that n >= 1 and m >= 0. If m = 0, it means the
 * directory is just the root directory.
 *
 * The output is a list of groups of duplicate file paths. For each group, it
 * contains all the file paths of the files that have the same content. A file
 * path is a string that has the following format:
 *
 *
 * "directory_path/file_name.txt"
 *
 *
 *
 * Example 1:
 * Input: paths = ["root/a 1.txt(abcd) 2.txt(efgh)","root/c
 * 3.txt(abcd)","root/c/d 4.txt(efgh)","root 4.txt(efgh)"]
 * Output:
 * [["root/a/2.txt","root/c/d/4.txt","root/4.txt"],["root/a/1.txt","root/c/3.txt"]]
 * Example 2:
 * Input: paths = ["root/a 1.txt(abcd) 2.txt(efgh)","root/c
 * 3.txt(abcd)","root/c/d 4.txt(efgh)"]
 * Output:
 * [["root/a/2.txt","root/c/d/4.txt"],["root/a/1.txt","root/c/3.txt"]]
 *
 *
 * Constraints:
 *
 *
 * 1 <= paths.length <= 2 * 10^4
 * 1 <= paths[i].length <= 3000
 * 1 <= sum(paths[i].length) <= 5 * 10^5
 * paths[i] consist of English letters, digits, '/', '.', '(', ')', and '
 * '.
 * You may assume no files or directories share the same name in the same
 * directory.
 * You may assume each given directory info represents a unique directory. A
 * single blank space separates the directory path and file info.
 *
 *
 *
 * Follow up:
 *
 *
 * Imagine you are given a real file system, how will you search files? DFS or
 * BFS?
 * If the file content is very large (GB level), how will you modify your
 * solution?
 * If you can only read the file by 1kb each time, how will you modify your
 * solution?
 * What is the time complexity of your modified solution? What is the most
 * time-consuming part and memory-consuming part of it? How to optimize?
 * How to make sure the duplicated files you find are not false positive?
 *
 *
 */

 // @lc code=start
class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string, vector<string>> hash;
        for (auto& path : paths) {
            // 这里用stringstream按照空格隔开读入
            stringstream ssin(path);
            // p是最开头的目录，file是文件名加内容的一整段，name是文件名部分，content是目录部分
            string p, file, name, content;
            ssin >> p;
            while (ssin >> file) {
                // 对于每个文件找到左括号和右括号的位置就能切分文件名和文件内容了
                int lp = file.find('('), rp = file.find(')');
                name = file.substr(0, lp), content = file.substr(lp + 1, rp - lp - 1);
                // 在哈希表里按照内容放入"路径/文件名"
                hash[content].push_back(p + '/' + name);
            }
        }
        // 找同一个内容有多个path的
        vector<vector<string>> res;
        for (auto& [k, v] : hash)
            if (v.size() > 1)
                res.push_back(v);
        return res;
    }
};

// @lc code=end

