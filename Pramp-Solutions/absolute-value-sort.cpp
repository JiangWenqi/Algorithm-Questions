#import <iostream>
#import <vector>

using namespace std;

vector<int> absSort(const vector<int> &arr)
{
    vector<int> res = arr;
    sort(res.begin(), res.end(), [&](int &a, int &b)
         {
    int aa = abs(a), ab = abs(b);
    if (aa == ab) return a < b;
    else return aa < ab; });
    return res;
}

int main()
{
    return 0;
}
