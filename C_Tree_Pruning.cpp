#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ff first
#define ss second
typedef vector<vector<long long>> vvi;
typedef vector<long long> vi;
#define int long long
#define endl "\n"

vi subTreeSZ;
vvi levels;
vi maxHeights;
vvi g;
void dfs(int node, int lvl){
    subTreeSZ[node] = 1;
    levels[lvl].push_back(node);
    for(auto nn: g[node]){
        dfs(nn, lvl + 1);
        subTreeSZ[node]+= subTreeSZ[nn];
        maxHeights[node] = max(maxHeights[nn], lvl);
    }
}
void Solve() {
    int n; cin>>n;
    g.resize(n+1);
    levels.resize(n+1);
    maxHeights.assign(n+1, 0);
    subTreeSZ.resize(n+1);
    for(int i = 0; i<n-1; i++){
        int u, v; cin>>u>>v;
        g[u].push_back(v);
    }
    dfs(1, 1); int Ans = 1e18;
    for(int j = levels.size()-1; j>=0; j--){
        int prune = 0;
        for(auto nn: levels[j]){
            prune+= subTreeSZ[nn];
        }
        for(int i = j-1; i>0; i--){
            for(auto nn: levels[i]) if(maxHeights[nn]<j) prune++;
        }
        Ans = min(Ans, prune);
    }
    cout<<Ans<<endl;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}