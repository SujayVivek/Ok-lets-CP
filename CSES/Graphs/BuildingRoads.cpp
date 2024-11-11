#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ff first
#define ss second
typedef vector<vector<long long>> vvi;
typedef vector<long long> vi;
#define int long long
#define endl "\n"

int n, m;
vi vis;
vvi g;

void dfs(int i, int comp) {
    vis[i] = comp;
    for (auto v : g[i]) {
        if (!vis[v]) {
            dfs(v, comp);
        }
    }
}

void Solve() {
    cin >> n >> m;
    vis.assign(n + 1, 0);
    g.resize(n + 1);
    
    for (int i = 0; i < m; i++) {
        int a, b; 
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    
    int comp = 0;
    for (int i = 1; i <= n; i++) {  
        if (!vis[i]) {
            comp++;
            dfs(i, comp);
        }
    }
    
    map<int, int> mpp;
    vi ans;
    
    for (int i = 1; i <= n; i++) {  
        if (!mpp[vis[i]]) {  
            mpp[vis[i]] = 1; 
            ans.push_back(i);  
        }
    }
    
    cout << ans.size()-1 << endl; 
    for (size_t i = 1; i < ans.size(); i++) {
        cout << ans[i - 1] << " " << ans[i] << endl;  
    }
}

int32_t main() {
    int tt_ = 1;
    while (tt_--) {
        Solve();
    }
    return 0;
}
