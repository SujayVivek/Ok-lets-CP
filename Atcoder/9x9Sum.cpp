#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ff first
#define ss second
typedef vector<vector<long long>> vvi;
typedef vector<long long> vi;
#define int long long
#define endl "\n"

void Solve()
{
    int X;
    cin >> X;
    map<int, int> mpp;
    int S = 0;
    for (int i = 1; i <= 9; i++)
    {
        for (int j = 1; j <= 9; j++)
        {
            mpp[i * j]++;
            S += i * j;
        }
    }
    cout << S - mpp[X] * X << endl;
}

int32_t main()
{
    int tt_ = 1;
    // cin >> tt_;
    while (tt_--)
    {
        Solve();
    }
    return 0;
}