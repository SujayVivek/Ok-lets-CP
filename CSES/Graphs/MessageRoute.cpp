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
vvi g;
vi dist;
vi par;

void bfs(int start) {
    dist[start] = 0;
    par[start] = -1;
    queue<int> q;
    q.push(start);
    
    while (!q.empty()) {
        int pos = q.front(); 
        q.pop();
        
        for (auto v : g[pos]) {  // Corrected: use g[pos] instead of g[nn]
            if (dist[v] > 1 + dist[pos]) {  // Updated to use dist[pos]
                dist[v] = 1 + dist[pos];
                par[v] = pos;
                q.push(v);
            }
        }
    }
}

void ppath(int end) {
    if (par[end] == -1) { 
        cout << "1 ";  // Start of path
        return; 
    }
    ppath(par[end]);
    cout << end << " ";
}

void Solve() {
    cin >> n >> m;
    g.resize(n + 1);
    dist.assign(n + 1, 1e9);
    par.assign(n + 1, 0);

    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    
    bfs(1);
    
    if (dist[n] == 1e9) {
        cout << "IMPOSSIBLE" << endl;
        return;
    }
    
    cout << dist[n] + 1 << endl;  // Number of nodes in the shortest path
    ppath(n);
    cout << endl;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}
