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
    int n, m, h;
    cin >> n >> m >> h;
    set<int> H;
    for (int i = 0; i < h; i++) {
        int x; cin >> x;
        H.insert(x);
    }
    vector<vector<pair<int, int>>> g(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        g[a].push_back({b, c});
        g[b].push_back({a, c});
    }

    vector<long long> adj1(n + 1, 1e18), adj2(n + 1, 1e18);
    adj1[1] = 0, adj2[n] = 0;

    priority_queue<vector<long long>, vector<vector<long long>>, greater<vector<long long>>> q;
    q.push({0, 1, 0});

    while (!q.empty()) {
        vector<long long> Top = q.top(); q.pop();
        long long cur_dist = Top[0], node = Top[1], horse = Top[2];

        for (auto nn : g[node]) {
            int weight = nn.second, sub_node = nn.first;
            long long new_dist = cur_dist + ((horse) ? weight / 2 : weight);

            if (adj1[sub_node] > new_dist) {
                adj1[sub_node] = new_dist;
                int new_horse = horse | (H.count(sub_node) ? 1 : 0);
                q.push({adj1[sub_node], sub_node, new_horse});
            }
        }
    }
    q = priority_queue<vector<long long>, vector<vector<long long>>, greater<vector<long long>>>();
    q.push({0, n, 0});

    while (!q.empty()) {
        vector<long long> Top = q.top(); q.pop();
        long long cur_dist = Top[0], node = Top[1], horse = Top[2];

        for (auto nn : g[node]) {
            int weight = nn.second, sub_node = nn.first;
            long long new_dist = cur_dist + ((horse) ? weight / 2 : weight);

            if (adj2[sub_node] > new_dist) {
                adj2[sub_node] = new_dist;
                int new_horse = horse | (H.count(sub_node) ? 1 : 0);
                q.push({adj2[sub_node], sub_node, new_horse});
            }
        }
    }

    long long Ans = 1e18;
    for (int i = 1; i <= n; i++) {
        Ans = min(Ans, max(adj1[i], adj2[i]));
    }

    if (Ans == 1e18) cout << -1 << endl;
    else cout << Ans << endl;
}  

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}