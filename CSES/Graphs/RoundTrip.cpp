#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ff first
#define ss second
typedef vector<vector<long long>> vvi;
typedef vector<long long> vi;
#define int long long
#define endl "\n"

int n, m;
vvi g;
vi vis;
vi par;
bool ok = false;
void dfs(int nn){
    vis[nn] = 1;
    for(auto v: g[nn]){
        if(!vis[v]){
            dfs(v);
            par[v] = nn;
        }
    }
}
void Solve() {
    cin>>n>>m;
    g.resize(n+1);
    vis.assign(n+1, 0);
    par.assign(n+1, 0);
    for(int i = 0; i<m ;i++){
        int a, b; cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for(int i = 1; i<=n; i++){
        if(!vis[i]) dfs(i);
    }
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}