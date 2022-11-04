#include <iostream>
#include <vector>

using namespace std;

bool check(double cap, vector<int> grantsArray, int newBudget)
{

    double sum = 0;
    for (int grant : grantsArray)
    {
        if (grant > cap)
            sum += cap;
        else
            sum += grant;
    }
    return sum >= newBudget;
}

double findGrantsCap(vector<int> grantsArray, int newBudget)
{
    double l = 0.0, r = 1e5;
    double exp = 1e-5;
    while (r - l > exp)
    {

        double mid = (l + r) / 2; // as the result cap
        if (check(mid, grantsArray, newBudget))
            r = mid;
        else
            l = mid;
    }
    return l;
}

/**
 [2, 100, 50, 120, 1000]
l = 0, r = 10010 -> mid 5005
sum > newbudget


**/
int main()
{

    vector<int> grantsArray = {2, 100, 50, 120, 1000};
    cout << findGrantsCap(grantsArray, 190);
    return 0;
}