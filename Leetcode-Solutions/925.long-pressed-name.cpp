/*
 * @lc app=leetcode id=925 lang=cpp
 *
 * [925] Long Pressed Name
 */

// @lc code=start
class Solution
{
public:
    bool isLongPressedName(string name, string typed)
    {
        int i = 0, j = 0;
        while (i < name.size() && j < typed.size())
        {
            if (name[i] != typed[j])
                return false;
            int x = i + 1, y = j + 1;
            while (x < name.size() && name[x] == name[i])
                x++;
            while (y < typed.size() && typed[y] == typed[j])
                y++;
            if (x - i > y - j)
                return false;
            i = x, j = y;
        }
        return i == name.size() && j == typed.size();
    }
};
// @lc code=end
