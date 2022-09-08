#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

int main() {
    int n, op;
    cin >> n;
    string res;
    stack<pair<int, string>> stk;

    for (int i = 0; i < n; i++) {
        cin >> op;
        if (op == 1) {
            string temp;
            cin >> temp;
            res += temp;
            stk.push(make_pair(op, temp));
        } else if (op == 2) {
            int del;
            cin >> del;
            string removed = res.substr(res.size() - del, del);
            res.resize(res.size() - del);
            stk.push(make_pair(op, removed));
        } else if (op == 3) {
            int idx;
            cin >> idx;
            cout << res[idx - 1] << endl;
        } else if (op == 4) {
            pair<int, string> undo = stk.top();
            if (undo.first == 1) {
                int del = undo.second.size();
                res.resize(res.size() - del);
                stk.pop();
            } else {
                res += undo.second;
                stk.pop();
            }
        }
    }
    return 0;
}

