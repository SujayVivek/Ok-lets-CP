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
void Solve() {
    int n, m; cin>>n>>m;
    vector<vector<pii>> g(n), grev(n);
    for(int i = 0; i<m; i++){
        int a, b, c; cin>>a>>b>>c; a--, b--;
        g[a].push_back({b, c});
        grev[b].push_back({a, c});
    }
    vi dist(n, -1);
    priority_queue<pii, vector<pii>, greater<pii>>pq;;
    pq.emplace(0,0);
    while(!pq.empty()){
        auto Top = pq.top(); int d = Top.first, node = Top.second; pq.pop();
        if(dist[node]!=-1) continue;
        dist[node] = d;
        for(auto nn: g[node]){
            pq.emplace(nn.second + d, nn.first);
        }
    }
    for(int i = 0; i<n; i++){
        if(dist[i] !=-1) pq.emplace(dist[i], i);
    } dist.assign(n, -1);
    while(!pq.empty()){
        auto Top = pq.top(); int d = Top.first, node = Top.second; pq.pop();
        if(dist[node]!=-1) continue;
        dist[node] = d;
        for(auto nn: grev[node]){
            pq.emplace(nn.second + d, nn.first);
        }
    }
    for(int i = 1; i<n; i++)cout<<dist[i]<<" ";
    cout<<endl;
}

int32_t main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int tt_ = 1;
    // cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}