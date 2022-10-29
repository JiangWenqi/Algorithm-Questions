#include <iostream>
#include <vector>

using namespace std;

int indexEqualsValueSearch(const vector<int> &arr)
{
    int l = 0, r = arr.size() - 1;
    while (l < r)
    {
        int mid = l + r >> 1;
        if (arr[mid] >= mid)
            r = mid;
        else
            l = mid + 1;
    }
    return arr[l] == l ? arr[l] : -1;
}

int main()
{
    return 0;
}