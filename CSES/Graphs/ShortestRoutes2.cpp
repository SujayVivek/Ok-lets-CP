#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ff first
#define ss second
typedef vector<vector<long long>> vvi;
typedef vector<long long> vi;
#define int long long
#define endl "\n"

void Solve() {
    int n, m, q;cin>>n>>m>>q;
    // vector<vector<pair<int,int>>> g(n+1);
    vvi adj(n+1, vi(n+1,1e18));
    for(int i = 0; i<=n; i++){
        adj[i][i] = 0;
    }
    for(int i = 0; i<m; i++){
        int a, b, c; cin>>a>>b>>c;
        adj[a][b] = min(adj[a][b], c);
        adj[b][a] = min(adj[b][a], c);
    }
    for(int k = 1; k<=n; k++){
        for(int i = 1; i<=n; i++){
            for(int j = 1; j<=n; j++){
                if(adj[i][k]!=1e18 && adj[k][i]!=1e18)
                adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
            }
        }
    }
    while(q--){
        int a, b; cin>>a>>b;
        if(a>=n || b>=n || adj[a][b] == 1e18) {
            cout<<-1<<endl;continue;
        }
        cout<<adj[a][b]<<endl;
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