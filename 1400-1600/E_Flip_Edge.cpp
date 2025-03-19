#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ff first
#define ss second
typedef vector<vector<long long>> vvi;
typedef vector<long long> vi;
#define int long long
#define endl "\n"

typedef pair<int, pair<int, int> > pii;
void Solve() {
    int N, M, X;
    cin >> N >> M >> X;
    vvi g(N + 1);
    vvi grev(N + 1);
    for (int i = 0; i < M; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        grev[v].push_back(u);
    }
    vvi dist(N + 1, vi(2, LLONG_MAX));
    dist[1][0] = 0;
    priority_queue<pii, vector<pii>, greater<pii> > pq;
    pq.push(make_pair(0, make_pair(1, 0)));

    while (!pq.empty()) {
        pii top = pq.top();
        int current_cost = top.first;
        int v = top.second.first;
        int s = top.second.second;
        pq.pop();

        if (v == N) break;
        if (current_cost > dist[v][s]) continue;
        int new_s = 1 - s;
        int new_cost = current_cost + X;
        if (new_cost < dist[v][new_s]) {
            dist[v][new_s] = new_cost;
            pq.push(make_pair(new_cost, make_pair(v, new_s)));
        }
        vi& adj = (s == 0) ? g[v] : grev[v];
        for (size_t i = 0; i < adj.size(); ++i) {
            int u = adj[i];
            if (current_cost + 1 < dist[u][s]) {
                dist[u][s] = current_cost + 1;
                pq.push(make_pair(current_cost + 1, make_pair(u, s)));
            }
        }
    }
    cout << min(dist[N][0], dist[N][1]) << endl;
}

int32_t main() {
    int tt_ = 1;
    // cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}
