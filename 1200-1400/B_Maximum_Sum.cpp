#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ff first
#define ss second
typedef vector<vector<long long>> vvi;
typedef vector<long long> vi;
#define int long long
#define endl "\n"

int maxi(vector<int> &arr)
{
    int res = arr[0];
    int maxEnding = arr[0];
    for (int i = 1; i < arr.size(); i++)
    {
        maxEnding = max((maxEnding + arr[i]), arr[i]);
        res = max(res, maxEnding);
    }
    return res;
}

void Solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        sum = (sum + arr[i] + mod) % mod;
    }
    int res = maxi(arr);

    if (res < 0)
    {
        res = 0;
    }
    sum = (sum - res + mod) % mod;

    for (int i = 0; i < k; i++)
    {
        res = (res * 2) % mod;
    }
    cout << (sum + res + mod) % mod << endl;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}