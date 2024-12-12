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
    vector<vector<pair<int, int>>>g;
    for(int i = 1; i<=m; i++){
        int a, b, c; cin>>a>>b>>c;
        g[a].push_back({c, b});
    }
    vi par(n+1);
    vi dist(n+1, 1e9);
    map<pair<int,int>, int> distMap;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0,1});
    while(!pq.empty()){
        auto pos = pq.top(); pq.pop();
        int neigh = pos.second, weigh = pos.first;
        for(auto v: g[neigh]){
            if(dist[v.first]> weigh + dist[neigh]){
                dist[v.first] = weigh + dist[neigh];
                par[v.second] = neigh;
                pq.push({dist[v.first], v.second}); 
                distMap[{neigh, v.second}] = weigh;
            }
        }
    }
    vi path;
    int cur = n;
    while(cur!=1){
        int father = par[cur];
        path.push_back(distMap[{father, cur}]);
        cur = par[cur];
    }
    sort(path.begin(), path.end());
    int ans = 0;
    for(int i = 0; i<path.size()-1; i++){
        ans += path[i];
    }
    ans += (0.5*path[path.size()-1]);
    cout<<ans<<endl;
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