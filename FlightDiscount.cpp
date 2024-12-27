#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ff first
#define ss second
typedef vector<vector<long long>> vvi;
typedef vector<long long> vi;
#define int long long
#define endl "\n"

vector<int> dij(int start, vi &v, int n){
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>()>pq;
    pq.push({0,start});
    while(!pq.empty()){
        auto pos = pq.top(); pq.pop();
        int cur_cost = pos.first, nn = pos.second;
        for(auto v: g[])
    }
}

vector<vector<pair<int,int>>> g;
vi adj, radj;
void Solve() {
    int n, m; cin>>n>>m;
    g.resize(n+1);
    adj.assign(n+1, 1e9);
    radj.assign(n+1, 1e9);
    vector<pair<int,pair<int,int>>>edges;
    adj[1] = 0; radj[n]= 0;
    for(int i = 0; i<m; i++){
        int a, b, c; cin>>a>>b>>c;
        g[a].push_back({b,c});
        edges.push_back({c, {a, b}});
    }
    dij()
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}