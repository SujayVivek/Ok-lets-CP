#include <bits/stdc++.h>
using namespace std;
#define mod 998244353
#define ff first
#define ss second
typedef vector<vector<long long>> vvi;
typedef vector<long long> vi;
#define int long long
#define endl "\n"

const int M = 998244353;
 
vector<vector<int>> Tree;
vector<int> distances;
 
void dfs(int x) {
    for (auto i : Tree[x]) {
        distances[i] = distances[x] + 1;
        dfs(i);
    }
}
 
void Solve() {
    int n;
    cin >> n;
    vector<int> p(n + 1);
    Tree.assign(n + 1, vector<int>(0));
    for (int i = 2; i <= n; i++) {
        cin >> p[i];
        Tree[p[i]].push_back(i);
    }
    distances.assign(n + 1, 0);
    dfs(1);
    vector<vector<int>> vec(n);
    for (int i = 1; i <= n; i++)
        vec[distances[i]].push_back(i);
 
    vector<int> dp(n + 1);
    int sum = 0;
    for (int i = n - 1; i >= 1; i--) {
        if (vec[i].empty())
            continue;
        int s = 0;
        for (auto v : vec[i]) {
            dp[v] = (1 + sum) % M;
            for (auto u : Tree[v]) {
                dp[v] -= dp[u];
                dp[v] = (dp[v] % M + M) % M;
            }
            s += dp[v];
            s %= M;
        } 
        sum = s;
    }
    int ans = (sum + 1) % M;
    cout << ans << '\n';
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}