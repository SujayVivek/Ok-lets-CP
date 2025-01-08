#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ff first
#define ss second
typedef vector<vector<long long>> vvi;
typedef vector<long long> vi;
#define int long long
#define endl "\n"

vvi g;
vi vis;
void Solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n + 1);
    vector<int> in_degree(n + 1, 0);
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        in_degree[y]++;
    }
    queue<int> q;
    for (int i = 1; i < n + 1; i++)
    {
        if (in_degree[i] == 0)
        {
            q.push(i);
        }
    }
    vector<int> topo_sort;
    while (q.size())
    {
        int x = q.front();
        q.pop();
        topo_sort.push_back(x);
        for (auto &i : g[x])
        {
            in_degree[i]--;
            if (in_degree[i] == 0)
            {
                q.push(i);
            }
        }
    }
    if (topo_sort.size() == n)
    {
        for (auto i : topo_sort)
        {
            cout << i << " ";
        }
    }
    else
    {
        cout << "IMPOSSIBLE\n";
    }
}

int32_t main() {
    int tt_ = 1;
    // cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}