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
vi maxHeights;
vi levels;
int mxlvl;
void dfs(int node, int lvl, int par){
    mxlvl = max(lvl, mxlvl);
    levels[lvl]++;
    maxHeights[node] = lvl;
    for(auto nn: g[node]){
        if(nn!=par){
            dfs(nn, lvl + 1, node);
            maxHeights[node] = max(maxHeights[node], maxHeights[nn]);
        }
    }
}
void Solve() {
    int n; cin>>n;
    g.assign(n+5,{}); mxlvl = 0; levels.assign(n+5, 0), maxHeights.assign(n+5, 0); 
    for(int i = 0; i<n-1; i++){
        int u, v; cin>>u>>v; g[u].push_back(v), g[v].push_back(u);
    }
    dfs(1, 1, 0);
    vi pref(n+5,0);
    for(int i = 1; i<=n; i++) pref[maxHeights[i]]++;
    for(int i = 1; i<=n; i++) {pref[i]+= pref[i-1]; levels[i]+= levels[i-1];}
    int ans = 1e18;
    for(int i = 1; i<=mxlvl; i++){
        int prune = levels[mxlvl]-levels[i] + pref[i-1];
        ans = min(ans, prune);
    }cout<<ans<<endl;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}