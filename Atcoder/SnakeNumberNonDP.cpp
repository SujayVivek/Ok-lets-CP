#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ff first
#define ss second
typedef vector<vector<long long>> vvi;
typedef vector<long long> vi;
#define int long long
#define endl "\n"
int pow(int a, int t)
{
    int res = 1;
    for (int i = 0; i < t; i++)
        res *= a;
    return res;
}
int calc(int R)
{
    vi digit;
    while (R)
    {
        digit.push_back(R % 10);
        R /= 10;
    }
    reverse(digit.begin(), digit.end());
    int res = 0;
    int N = digit.size();
    for (int i = 1; i <= N; i++)
    {
        if (i == N)
        {
            res++;
            break;
        }
        res += pow(digit[0], N - i - 1) * min(digit[0], digit[i]);
        if (digit[i] >= digit[0])
            break;
    }
    for (int i = 0; i < N; i++)
    {
        int mx = (i ? 9 : (digit[0] - 1));
        for (int j = 1; j <= mx; j++)
        {
            res += pow(j, N - 1 - i);
        }
    }
    return res;
}
void Solve()
{
    int L, R;
    cin >> L >> R;
    cout << calc(R) - calc(L - 1) << endl;
    return;
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