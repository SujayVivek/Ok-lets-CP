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
vi par;
vi vis;
  
void dfs(int nn, int par){
    vis[nn] = 1;
    for(auto X: g[nn]){
        if(vis[X]){
            par[X] = nn;
        }
    }
}
void Solve() {
    int n, m; cin>>n>>m;
    g.resize(n+1);
    par.assign(n+1, -1);
    vis.assign(n+1, 0);
    for(int i = 0; i<m; i++){
        int a, b; cin>>a>>b;
        g[a].push_back(b);
    }
    for(int i = 1; i<=n; i++){
        if(!vis[i])dfs(i, -1);
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