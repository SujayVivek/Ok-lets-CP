#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

vector<vector<int>> adj;
int n, k, res;

int dfs(int u, int p, int x)
{
    int size = 1;
    for (int v : adj[u])
    {
        if (v == p)
            continue;
        size += dfs(v, u, x);
    }
    if (size >= x)
    {
        res++;
        return 0;
    }
    return size;
}

bool canPartition(int x)
{
    res = 0;
    dfs(0, -1, x);
    return res > k;
}

void solve()
{
    cin >> n >> k;
    adj.assign(n, vector<int>());

    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        u--, v--; 
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int lo = 1, hi = n;
    while (lo < hi)
    {
        int x = (lo + hi + 1) / 2;
        if (canPartition(x))
        {
            lo = x;
        }
        else
        {
            hi = x - 1;
        }
    }
    cout << lo << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}
