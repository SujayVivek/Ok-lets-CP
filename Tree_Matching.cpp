#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ff first
#define ss second
typedef vector<vector<long long>> vvi;
typedef vector<long long> vi;
#define int long long
#define endl "\n"

// Globals
set<pair<int, int>> Over; // Use a set of pairs to store edges
vi par;
vvi g;
vi vis;

// DFS function
void dfs(int node)
{
    vis[node] = 1;
    for (auto nn : g[node])
    {
        if (!vis[nn])
        {
            par[nn] = node; // Assign parent
            dfs(nn);
        }
    }
    // Add the edge to the Over set if both node and parent are "special"
    if (par[node] != -1 && Over.count({par[node], node}) == 0)
    {
        Over.insert({min(node, par[node]), max(node, par[node])});
    }
}

// Solve function
void Solve()
{
    int n;
    cin >> n;
    par.assign(n + 1, -1); // Initialize parent array
    g.resize(n + 1);       // Resize the adjacency list
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a); // Add reverse edge for undirected graph
    }
    vis.assign(n + 1, 0);        // Initialize visited array
    dfs(1);                      // Start DFS from node 1
    cout << Over.size()/2 << endl; // Output the number of edges in Over
}

int32_t main()
{
    int tt_ = 1;
    // cin >> tt_;  // Uncomment for multiple test cases
    while (tt_--)
    {
        Solve();
    }
    return 0;
}
