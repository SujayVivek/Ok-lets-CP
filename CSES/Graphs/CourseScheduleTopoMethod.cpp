#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
typedef vector<vector<long long>> vvi;
typedef vector<long long> vi;
#define int long long
#define endl "\n"

vvi g;
vi vis;
vi topo;
bool cycle = false;

void dfs(int node)
{
    vis[node] = 0;
    for (auto x : g[node])
    {
        if (vis[x] == 0)
        { 
            cycle = true;
            return;
        }
        else if (vis[x] == -1)
        {
            dfs(x);
        }
    }
    vis[node] = 1;        
    topo.push_back(node);
}

void Solve()
{
    int N, M;
    cin >> N >> M;
    g.resize(N + 1);
    vis.assign(N + 1, -1);

    
    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
    }

   
    for (int i = 1; i <= N; i++)
    {
        if (vis[i] == -1)
        {
            dfs(i);
        }
        if (cycle)
        {
            cout << "IMPOSSIBLE" << endl;
            return;
        }
    }

    reverse(topo.begin(), topo.end()); 
    for (auto x : topo)
    {
        cout << x << " ";
    }
    cout << endl;
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
