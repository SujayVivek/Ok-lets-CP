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
bool ok = true;
void dfs(int i, int team){
    if(!ok) return;
    vis[i] = team;
    for(auto v: g[i]){
        if(vis[v] == team){
            ok = false; return;
        }
        if(!vis[v]){
            dfs(v, 3-team);
        }
    }
}
void Solve() {
    cin>>n>>m;
    g.resize(n+1);
    vis.assign(n+1, 0);
    for(int i = 0; i<m; i++){
        int a, b; cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int team = 1;
    for(int i = 1; i<=n; i++){
        if(!vis[i]){
            dfs(i, team);
        }
    }
    if(!ok){
        cout<<"IMPOSSIBLE"<<endl; return;
    }
    for(size_t i = 1; i<vis.size(); i++){
        cout<<vis[i]<<" ";
    }cout<<endl;
    return;
}

int32_t main() {
    int tt_ = 1;
    // cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}