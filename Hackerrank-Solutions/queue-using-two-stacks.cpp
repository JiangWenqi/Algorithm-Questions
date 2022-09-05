#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;


class MyQueue {
private:
    stack<int> s1, s2;
public:
    void deque() {
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        s2.pop();
    }

    void enque(int x) {
        s1.push(x);
    }

    void print() {
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        if (!s2.empty()) {
            cout << s2.top() << endl;
        }
    }
};

int main() {
    int q;
    MyQueue* queue = new MyQueue();
    cin >> q;
    for (int i = 0;i <= q;i++) {
        string str;
        getline(cin, str);
        if (str[0] == '1') {
            int x = stoi(str.substr(2));
            queue->enque(x);
        } else if (str[0] == '2') {
            queue->deque();
        } else {
            queue->print();
        }
    }
    return 0;
}