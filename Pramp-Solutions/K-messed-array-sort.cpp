#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> sortKMessedArray(const vector<int> &arr, int k)
{
    // your code goes here
    /**
      vector<int> res = arr;
      for (int i = 1; i < res.size(); i++) {
        // unsoreted
        if (res[i] < res[i-1]) {
          // k steps
          for (int j = k; j >= 0; j--) {
            if (i-j >= 0 && res[i-j] > res[i]) swap(res[i-j], res[i]);
          }
        }
      }
      **/

    vector<int> res;

    priority_queue<int, vector<int>, greater<int>> q;
    // build pq from 0 - k+1
    // for()

    // i = k+1
    for (int i = 0; i < arr.size(); i++)
    {
        if (q.size() > k)
        {
            int num = q.top();
            q.pop();
            res.push_back(num);
        }
        q.push(arr[i]);
    }
    while (!q.empty())
    {
        int num = q.top();
        q.pop();
        res.push_back(num);
    }
    return res;
}

int main()
{
    return 0;
}
