#include <iostream>
#include <vector>

using namespace std;

/*
index = 0  1  2  3  4
arr =   1, 5, 4, 3, 2
flip 2 (index of max)
5, 1,4,3,2
flip 5 (index of the real index)
2,3,4,1,5
find the max in left 4 number?
flip 3 (index of max)
flip 4 (index of the real indx of 4)

*/

void flip(vector<int> &arr, int k)
{
    int l = 0, r = k;
    while (l < r)
    {
        swap(arr[l], arr[r]);
        l++, r--;
    }
    for (int num : arr)
    {
        cout << num << ",";
    }
}

vector<int> pancakeSort(const vector<int> &arr)
{
    pair<int, int> mx = {INT_MIN, -1}; // max, indx of max
    int n = arr.size();
    vector<int> res = arr;
    for (int i = n - 1; i >= 1; i--)
    {
        mx = {INT_MIN, -1};
        for (int j = 0; j <= i; j++)
        {
            if (res[j] > mx.first)
                mx = {res[j], j}; // update the max with its idx
        }

        flip(res, mx.second);
        flip(res, i);
    }
    return res;
}

int main()
{
    vector<int> arr = {2, 3, 1, 5, 4};
    vector<int> res = pancakeSort(arr);
    for (int num : res)
    {
        cout << num << ",";
    }
    return 0;
}