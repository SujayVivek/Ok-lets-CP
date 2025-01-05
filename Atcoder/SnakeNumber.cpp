#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ff first
#define ss second
typedef vector<vector<long long>> vvi;
typedef vector<long long> vi;
#define int long long
#define endl "\n"

int dp[19][2][2][10]; 
string l, r;
int len;

int calc(int idx, int hi, int lo, int first_dig)
{
    if (idx == len)
    {
        return 1; // Reached the end of the number, valid number found.
    }
    if (dp[idx][hi][lo][first_dig] != -1)
    {
        return dp[idx][hi][lo][first_dig];
    }
    int ans = 0;
    int hiLim = (hi ? (r[idx] - '0') : 9); // If hi == 1, constrain by r[idx].
    int loLim = (lo ? (l[idx] - '0') : 0); // If lo == 1, constrain by l[idx].

    for (int i = loLim; i <= min(hiLim, max(0ll,first_dig-1)); i++)
    {
        int nlo = lo, nhi = hi;

        if (i != l[idx] - '0')
            nlo = 0; // Once lo bound is broken.
        if (i != r[idx] - '0')
            nhi = 0; // Once hi bound is broken.

        ans += calc(idx + 1, nhi, nlo, (idx == 0 ? i : first_dig)); // Pass first_dig.
    }

    return dp[idx][hi][lo][first_dig] = ans;
}

void Solve()
{
    int L, R;
    cin >> L >> R;

    l = to_string(L);
    r = to_string(R);
    len = r.length();

    int extra = len - l.length();
    string Zero(extra, '0');
    l = Zero + l; // Pad the smaller number with zeros.

    memset(dp, -1, sizeof(dp));
    int res = calc(0, 1, 1, 9);
    cout << res << endl;
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
