#include <iostream>
#include <vector>

using namespace std;

vector<int> findArrayQuadruplet(const vector<int> &arr, int s)
{
    // 1. sort the array
    vector<int> nums = arr;
    sort(nums.begin(), nums.end());
    // 2. loop the array to find the four nums
    int n = nums.size();
    for (int i = 0; i < n - 3; i++)
    {
        int first = nums[i];
        for (int j = i + 1; j < n - 2; j++)
        {
            int second = nums[j];
            int l = j + 1, r = n - 1;
            while (l < r)
            {
                int sum = first + second + nums[l] + nums[r];
                if (sum == s)
                    return {first, second, nums[l], nums[r]};
                else if (sum > s)
                    r--;
                else
                    l++;
            }
        }
    }
    return {};

    // time complexity: O(n^3)
    // space complexity: O(n) 
}

int main()
{
    return 0;
}