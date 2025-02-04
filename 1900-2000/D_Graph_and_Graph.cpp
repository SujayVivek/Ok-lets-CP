#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ff first
#define ss second
typedef vector<vector<long long>> vvi;
typedef vector<long long> vi;
#define int long long
#define endl "\n"
set<int> Near_points;

void Solve() {
    int n, s1, s2; cin >> n >> s1 >> s2;
    int m1; cin >> m1;
    set<pair<int, int>> st;
    vvi g1(n + 1), g2(n + 1);
    for (int i = 0; i < m1; i++) {
        int a, b; cin >> a >> b;
        st.insert({a, b}); st.insert({b, a});
        g1[a].push_back(b), g1[b].push_back(a);
    }
    Near_points.clear();
    int m2; cin >> m2;
    for (int i = 0; i < m2; i++) {
        int a, b; cin >> a >> b;
        g2[a].push_back(b), g2[b].push_back(a);
        if (st.find({a, b}) != st.end()) {
            Near_points.insert(a), Near_points.insert(b);
        }
    }
    if (Near_points.empty()) {
        cout << -1 << endl; return;
    }
    vvi distances(n + 1, vi(n + 1, 1e18));
    set<pair<int, pair<int, int>>> q;
    distances[s1][s2] = 0;
    q.insert({0, {s1, s2}});
    while (!q.empty()) {
        int cost = q.begin()->first;
        int nn1 = q.begin()->second.first;
        int nn2 = q.begin()->second.second;
        q.erase(q.begin());
        for (auto it1 : g1[nn1]) {
            for (auto it2 : g2[nn2]) {
                int C = abs(it1 - it2);
                if (distances[it1][it2] > distances[nn1][nn2] + C) {
                    distances[it1][it2] = distances[nn1][nn2] + C;
                    q.insert({distances[it1][it2], {it1, it2}});
                }
            }
        }
    }
    int ans = 1e18;

    for (int it : Near_points) {
        ans = min(ans, distances[it][it]);
    }
    
    cout << (ans==1e18?-1:ans) << endl;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}