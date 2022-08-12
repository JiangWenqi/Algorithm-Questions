#include <iostream>
#include <string>
#include <vector>

using namespace std;

int deletionDistance(const string& str1, const string& str2)
{
    int m = str1.size(), n = str2.size();
    vector<vector<int>> f(m + 1, vector<int>(n + 1, INT_MAX));

    for (int i = 0; i <= n; i++) {
        f[0][i] = i;
    }
    for (int i = 0; i <= m; i++) {
        f[i][0] = i;
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (str1[i - 1] == str2[j - 1]) f[i][j] = f[i - 1][j - 1];
            else f[i][j] = 1 + min(f[i - 1][j], f[i][j - 1]);
        }
    }
    return f[m][n];
}

int main() {
    return 0;
}