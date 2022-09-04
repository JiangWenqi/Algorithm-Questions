#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

/*
n(tanks number) k(input flow)
30 (capacity)
3
7
20

----
10(last tank starts overflowing) 30(all tanks are completely full)

2 2
4 6

---
2 2

*/

vector<string> split(const string& str) {
    vector<string> tokens;
    int start = 0, end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));
        start = end + 1;
    }
    tokens.push_back(str.substr(start));
    return tokens;
}

bool check1(double second, vector<int> capacities, int k) {
    int n = capacities.size();
    double input = second * k, least = 0;
    for (int i = 0; i < n; i++) {
        double water = input + least;
        if (water >= capacities[i]) {
            if (i == n - 1) return true;
            least = water - capacities[i];
        } else {
            least = 0;
        }
    }
    return false;
}

bool check2(double second, vector<int> capacities, int k) {
    int n = capacities.size(), full = 0;
    double input = second * k, least = 0;
    for (int i = 0; i < n; i++) {
        double water = input + least;
        if (water >= capacities[i]) {
            full++;
            least = water - capacities[i];
        } else {
            least = 0;
        }
    }
    if (full == n) return true;
    else return false;
}

vector<int> run(vector<int> capacities, int k) {
    vector<int> res(2, 0);
    int n = capacities.size();
    int maxCapacity = 0, minCapacity = INT_MAX;
    for (int& cpacity : capacities) {
        maxCapacity = max(maxCapacity, cpacity);
        minCapacity = min(minCapacity, cpacity);
    }
    double l = minCapacity / k, r = maxCapacity / k;

    while (l < r) {
        double mid = (l + r) / 2;
        if (check1(mid, capacities, k)) r = mid;
        else l = mid + 1;
    }
    res[0] = l;

    l = minCapacity / k, r = maxCapacity / k;
    while (l < r) {
        double mid = l + (r - l) / 2;
        if (check2(mid, capacities, k)) r = mid;
        else l = mid + 1;
    }
    res[1] = l;
    return res;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    string t_temp;
    getline(cin, t_temp);
    vector<string> nAndK = split(t_temp);

    int n = stoi(nAndK[0]), k = stoi(nAndK[1]);
    vector<int> capacities(n, 0);
    for (int i = 0; i < n; i++) {
        string num;
        getline(cin, num);
        capacities[i] = stoi(num);
    }
    vector<int> res = run(capacities, k);
    cout << res[0] << " " << res[1] << endl;
    return 0;
}


