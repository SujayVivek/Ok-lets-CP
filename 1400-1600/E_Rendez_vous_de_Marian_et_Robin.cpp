#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ff first
#define ss second
typedef vector<vector<long long>> vvi;
typedef vector<long long> vi;
#define int long long
#define endl "\n"

vvi dijkstra(int start, int n, const vector<vector<pair<int, int>>>& g, const set<int>& H) {
    vvi dist(n, vi(2, 1e18));
    priority_queue<vi, vvi, greater<vi>> q;
    
    dist[start][0] = 0;
    int P = 0;
    if(H.count(start)) P = 1;
    q.push({0, start, P}); 

    while (!q.empty()) {
        auto cur = q.top();
        q.pop();
        int cur_dist = cur[0], node = cur[1], horse = cur[2];

        if (cur_dist > dist[node][horse]) continue;

        for (auto edge : g[node]) {
            int sub_node = edge.first, weight = edge.second;
            int new_horse = horse | (H.count(sub_node) ? 1 : 0);
            int new_dist = cur_dist + (horse ? weight / 2 : weight);
            
            if (dist[sub_node][new_horse] > new_dist) {
                dist[sub_node][new_horse] = new_dist;
                q.push({new_dist, sub_node, new_horse});
            }
        }
    }
    return dist;
}

void Solve() {
    int n, m, h;
    cin >> n >> m >> h;
    
    set<int> H;
    for (int i = 0; i < h; i++) {
        int x; cin >> x;
        H.insert(x - 1);  
    }

    vector<vector<pair<int, int>>> g(n);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        --a, --b;  
        g[a].push_back({b, c});
        g[b].push_back({a, c});
    }

    vvi d1 = dijkstra(0, n, g, H);    
    vvi d2 = dijkstra(n - 1, n, g, H); 

    int Ans = 1e18;
    for (int i = 0; i < n; i++) {
        int A = max(min(d1[i][0], d1[i][1]), min(d2[i][0], d2[i][1]));
        Ans = min(Ans, A);
    }

    cout << (Ans == 1e18 ? -1 : Ans) << endl;
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tt_;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}