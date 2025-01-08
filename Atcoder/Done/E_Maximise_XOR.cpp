#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ff first
#define ss second
typedef vector<vector<long long>> vvi;
typedef vector<long long> vi;
#define int long long
#define endl "\n"

int N, K;
int ans;

void calc(int idx, vi &SUF, int X, vi &A, int k)
{
    if (idx == N || k == 0)
    {
        ans = max(ans, X);
        return;
    }
    if(idx + k == N) ans = max(ans, SUF[idx]);
    calc(idx + 1, SUF, X ^ A[idx], A, k - 1);
    calc(idx + 1, SUF, X, A, k);
}

void Solve()
{
    cin >> N >> K;
    vi A(N, 0);
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }
    ans = 0;
    calc(0, A, 0, A, K);
    cout << ans << endl;
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
