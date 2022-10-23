#include <iostream>
#include <vector>

using namespace std;

int calcDroneMinEnergy(const vector<vector<int>> &route)
{
    int highest = route[0][2];
    for (int i = 1; i < route.size(); i++)
    {
        highest = max(route[i][2], highest);
    }
    return highest - route[0][2];
}

int main()
{
    return 0;
}