#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ff first
#define ss second
typedef vector<vector<long long>> vvi;
typedef vector<long long> vi;
#define int long long
#define endl "\n"

vvi g;
vi vis;
vi deg;
int cycles;
vi comp;
void dfs(int nn, int par) {
    vis[nn] = 1;
    comp.push_back(nn);
    for (auto v : g[nn]) {
        if(!vis[v]){
            dfs(v, nn);
        }
    }
}

void Solve() {
    int n, m;
    cin >> n >> m;
    g.resize(n + 1);
    vis.assign(n + 1, 0);deg.assign(n + 1, 0);
    // par.assign(n + 1, -1);
    while (m--) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
        deg[x]++, deg[y]++;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            comp.clear();
            dfs(i, -1);
            bool ok = true;
            for(auto v: comp) ok&= (deg[v]==2);
            if(ok) ans++;
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
