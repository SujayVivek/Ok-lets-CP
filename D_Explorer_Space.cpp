#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ff first
#define ss second
typedef vector<vector<long long>> vvi;
typedef vector<long long> vi;
#define int long long
#define endl "\n"
typedef pair<int,int> pii;

int dfs(int node, vector<vector<pii>> &g, int k, vi &vis){
    int ans = 1e18;
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
    pq.emplace(0, node, k/2);
    while(!pq.empty()){
        auto Top = pq.top(); pq.pop();
        int cost = get<0>(Top);
        int nod = get<1>(Top);
        int remaining = get<2>(Top);
        vis[node] = 1;
        if(remaining==0){ans = min(ans,cost); continue;}
        for(auto nn: g[nod]){
            int nxt_nn = nn.first, dist = nn.second;
            if(!vis[nxt_nn]) pq.emplace(dist + cost, nxt_nn, remaining-1);
        }
    }
    return ans;
}
void Solve() {
    int n, m, k; cin>>n>>m>>k;
    vector<vector<pii>> g(n*m+1, vector<pii>());
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<m; j++){
            int a; cin>>a;
            g[m*(i-1) + j].push_back({m*(i-1) + j+1, a});
            g[m*(i-1) + j+1].push_back({m*(i-1)+ j, a});
        }
    }
    for(int i = 1; i<n; i++){
        for(int j = 1; j<=m; j++){
            int a; cin>>a;
            g[m*(i-1)+j].push_back({m*(i) + j, a});
            g[m*(i) + j].push_back({m*(i-1) + j, a});
        }
    }
    if(k%2==1){
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                cout<<-1<<" ";
            }cout<<endl;
        }cout<<endl;return;
    }
    vvi grid(n+1, vi(m+1, 0));
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=m; j++){
            vi vis(n*m + 1, 0);
            grid[i][j] = dfs((i-1)*m+j, g, k, vis);
        }
    }
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cout<<2*grid[i+1][j+1]<<" ";
        }cout<<endl;
    }return;
}

int32_t main() {
    int tt_ = 1;
    // cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}