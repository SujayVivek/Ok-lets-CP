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
    int n, m; cin>>n>>m;
    vector<vector<pair<int,int>>>g(n+1);
    for(int i = 0; i<m; i++){
        int a, b, c;cin>>a>>b>>c;
        g[a].push_back({b,c});
        g[b].push_back({a,c});
    }
    vi Slow(n+1);
    for(int i = 1; i<=n; i++) cin>>Slow[i];
    priority_queue<array<int,3>, vector<array<int,3>>, greater<array<int,3>>>pq;
    vvi dist(n+1, vi(1001, 1e18));
    vvi vis(n+1, vi(1001,0));
    dist[1][1] = 0;
    pq.push({0,1,1});
    while(!pq.empty()){
        auto it = pq.top(); pq.pop();
        int dis = it[0], node = it[1], bike = it[2];
        if(vis[node][bike])continue;
        vis[node][bike] = 1;
        for(auto nn: g[node]){
            int weight = nn.second, neigh = nn.first;
            int newBike = bike;
            if(Slow[neigh]<Slow[bike]) newBike = neigh;

            if(dist[neigh][newBike]>dist[node][bike] + weight*Slow[bike]){
                dist[neigh][newBike] = dist[node][bike] + weight*Slow[bike];
                pq.push({dist[neigh][newBike], neigh, newBike});
            }
        }
    }int Ans = 1e18;
    for(int i = 1; i<=1000; i++){
        Ans = min(Ans, dist[n][i]);
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