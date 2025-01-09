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
vi par;
int start, hMax = 0;
void dfs(int node, int height){
    vis[node] = 1;
    if(hMax<height){
        start = node;
        hMax = height;
    }
    for(auto x: g[node]){
        if(vis[x]==-1){
            par[x] = node;
            dfs(x, height + 1);
        }
    }
}
void Solve() {
    int n, m; cin>>n>>m;
    par.resize(n+1);
    g.resize(n+1);
    vis.assign(n+1, -1);
    for(int i = 0; i<m; i++){
        int a, b; cin>>a>>b;
        g[a].push_back(b);
    }
    for(int i = 1; i<=n; i++){
        if(vis[i]==-1){
            par[i] = i;
            dfs(i, 0);
        }
    }
    vi Travel;
    while(par[start]!=start){
        Travel.push_back(start);
        start = par[start];
    }
    cout<<Travel.size()<<endl;
    for(auto x: Travel)cout<<x<<" ";
    cout<<endl;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}