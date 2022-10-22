#import <iostream>
#import <string>
#import <vector>

using namespace std;

int decodeVariations(const string &S)
{
    int n = S.size();
    vector<int> dp(n + 1, 0);
    int one = 1, two = 1;
    for (int i = 2; i <= n; i++)
    {

        int curr = S[i - 1] - '0';
        int prev = S[i - 2] - '0';
        int num = prev * 10 + curr;
        if (S[i - 1] == '0' && num != 20)
            return 0;
        int three = two;
        if (num >= 10 && num <= 26)
        {
            three += one;
        }
        one = two;
        two = three;
    }
    return two;
}
/*

x 1 2 6 2
0 1 2 3 3


*/

int main()
{
    int num = decodeVariations("1262");
    cout << num << endl;
    return 0;
}
