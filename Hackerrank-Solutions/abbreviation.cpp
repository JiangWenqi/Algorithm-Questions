#include <bits/stdc++.h>

using namespace std;

string ltrim(const string&);
string rtrim(const string&);

/*
 * https://www.hackerrank.com/challenges/abbr/problem
 * Complete the 'abbreviation' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts following parameters:
 *  1. STRING a
 *  2. STRING b
 */

string abbreviation(string a, string b) {
    int m = a.size(), n = b.size();
    vector<vector<bool>> f(n + 1, vector<bool>(m + 1, false));
    f[0][0] = true;
    // the first row
    for (int i = 1; i <= m; i++) {
        if (isupper(a[i - 1])) f[0][i] = false;
        else f[0][i] = f[0][i - 1];
    }
    // the first col
    for (int i = 1; i <= n; i++) f[i][0] = false;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            char ca = a[j - 1], cb = b[i - 1];
            if (isupper(ca)) {
                if (ca == cb) f[i][j] = f[i - 1][j - 1];
                // cant delete the Upper case when they are not equal
                else f[i][j] = false;
            } else {
                if (toupper(ca) == cb) f[i][j] = f[i - 1][j - 1] || f[i][j - 1];
                else f[i][j] = f[i][j - 1];
            }
        }
    }
    return f[n][m] ? "YES" : "NO";
}
int main() {
    ofstream fout(getenv("OUTPUT_PATH"));

    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string a;
        getline(cin, a);

        string b;
        getline(cin, b);

        string result = abbreviation(a, b);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

string ltrim(const string& str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string& str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
