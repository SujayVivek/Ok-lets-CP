#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ff first
#define ss second
typedef vector<vector<long long>> vvi;
typedef vector<long long> vi;
#define int long long
#define endl "\n"

const int INF = LLONG_MAX;
void Solve() {
    int n, m; cin>>n>>m;
    vector<vector<pair<int,int>>>g(n+1), rg(n+1);
    vi dis1(n+1, INF);
    vi dis2(n+1, INF);
    vvi Edges;

    for(int i = 0; i<m; i++){
        int a, b, c; cin>>a>>b>>c;
        g[a].push_back({c , b});
        Edges.push_back({c, a, b});
        rg[b].push_back({c, a});
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 1});
    dis1[1] = 0;

    while (!pq.empty()) {
        auto Pos = pq.top();
        int Pos_distance = Pos.first, Pos_Val = Pos.second;
        pq.pop();
        // if (Pos_distance > dis1[Pos_Val]) continue;

        for (auto X : g[Pos_Val]) {
            int X_distance = X.first, X_Val = X.second;
            if (dis1[X_Val] > dis1[Pos_Val] + X_distance) {
                dis1[X_Val] = dis1[Pos_Val] + X_distance;
                pq.push({dis1[X_Val], X_Val});
            }
        }
    }

    // Dijkstra for dis2 (from n to 1 using reversed graph)
    pq.push({0, n});
    dis2[n] = 0;

    while (!pq.empty()) {
        auto Pos = pq.top();
        int Pos_distance = Pos.first, Pos_Val = Pos.second;
        pq.pop();
        // if (Pos_distance > dis2[Pos_Val]) continue;

        for (auto X : rg[Pos_Val]) {
            int X_distance = X.first, X_Val = X.second;
            if (dis2[X_Val] > dis2[Pos_Val] + X_distance) {
                dis2[X_Val] = dis2[Pos_Val] + X_distance;
                pq.push({dis2[X_Val], X_Val});
            }
        }
    }
    int ans = INF;
    for (auto it : Edges) {
        int Edge_val = it[0], Edge_lft = it[1], Edge_rgt = it[2];
        if (dis1[Edge_lft] != INF && dis2[Edge_rgt] != INF) {
            ans = min(ans, Edge_val / 2 + dis1[Edge_lft] + dis2[Edge_rgt]);
        }
    }

    cout << ans << endl;
}

int32_t main() {
    int tt_ = 1;
    // cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}