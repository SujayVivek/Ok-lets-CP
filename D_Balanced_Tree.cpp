#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ff first
#define ss second
typedef vector<vector<long long>> vvi;
typedef vector<long long> vi;
#define int long long
#define endl "\n"

vector<int> vals; 
vvi g;
vector<pair<int, int>> vpi;
vi dp;

void dfs2(int node, int par)
{
    for (auto nn : g[node])
    {
        if (nn == par)
            continue;
        dfs2(nn, node);
        dp[node] += dp[nn];
        if (vals[nn] > vals[node])
        {
            dp[node] += vals[nn] - vals[node];
        }
    }
}

void dfs(int node, int par)
{
    int mx = 0;
    for (auto nn : g[node])
    {
        if (nn == par)
            continue;
        dfs(nn, node);
        mx = max(mx, vals[nn]);
    }
    vals[node] = max(vpi[node - 1].first, min(vpi[node - 1].second, mx));
}

void Solve()
{
    int n;
    cin >> n;
    g.assign(n + 1, {});
    vpi.clear();
    vals.assign(n + 1, 0);
    dp.assign(n + 1, 0);

    for (int i = 0; i < n; i++)
    {
        int l, r;
        cin >> l >> r;
        vpi.emplace_back(l, r);
    }

    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    dfs(1, -1);
    dfs2(1, -1);
    cout << dp[1] + vals[1] << endl;
}

int32_t main()
{
    int tt_;
    cin >> tt_;
    while (tt_--)
    {
        Solve();
    }
    return 0;
}
