#include <iostream>
#include <vector>
#include <unordered_map>

/*
Pairs with Specific Difference
Given an array arr of distinct integers and a nonnegative integer k, write a function findPairsWithGivenDifference that returns an array of all pairs [x,y] in arr, such that x - y = k. If no such pairs exist, return an empty array.

Note: the order of the pairs in the output array should maintain the order of the y element in the original array.

Examples:

input:  arr = [0, -1, -2, 2, 1], k = 1
output: [[1, 0], [0, -1], [-1, -2], [2, 1]]

input:  arr = [1, 7, 5, 3, 32, 17, 12], k = 17
output: []
Constraints:

[time limit] 5000ms

[input] array.integer arr

0 ≤ arr.length ≤ 100
[input]integer k

k ≥ 0
[output] array.array.integer
*/
using namespace std;
vector<vector<int>> findPairsWithGivenDifference(const vector<int>& arr, int k)
{
    unordered_map<int, bool> mp;
    vector<vector<int>> res;
    for (int i = 0; i < arr.size(); i++) {
        mp[arr[i]] = true;
    }
    for (int i = 0; i < arr.size(); i++) {
        if (mp[k + arr[i]]) res.push_back({ k + arr[i], arr[i] });
    }
    return res;
}

int main() {
    return 0;
}