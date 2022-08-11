#import <iostream>
#import <vector>
#import <stack>

using namespace std;

int shortestCellPath(const vector<vector<int>>& grid, int sr, int sc, int tr, int tc) {

    int dirs[5] = { 0, 1, 0, -1, 0 };
    int m = grid.size(), n = grid[0].size();
    // 4-directionally
    // bfs question
    // 1. init a stack
    stack<pair<int, int>> stk;
    // 2. store the start point
    stk.push(make_pair(sr, sc));
    // 3. set a flag as visited
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    visited[sr][sc] = true;
    int res = 0;
    while (!stk.empty()) {
        int sz = stk.size();
        for (int i = 0; i < sz; i++) {
            int x = stk.top().first, y = stk.top().second;
            stk.pop();
            if (x == tr && y == tc) return res;
            for (int j = 0; j < 4; j++) {
                // 4. go 4 directions
                int nx = x + dirs[j], ny = y + dirs[j + 1];
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] && !visited[nx][ny]) {
                    stk.push(make_pair(nx, ny));
                    visited[nx][ny] = true;
                }
            }
            res++;
        }

    }
    return -1;
}

int main() {

}
