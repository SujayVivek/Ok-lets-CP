#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ff first
#define ss second
typedef vector<vector<long long>> vvi;
typedef vector<long long> vi;
#define int long long
#define endl "\n"

const int INF = 1e17;
const int NINF = INF * (-1);

struct triplet {
    int u, v, w;
};

vector<triplet> edges;
vi dist;

void bellmanford(int n) {
    for (int i = 1; i < n; i++) {  // Relaxation phase
        for (auto e : edges) {
            int u = e.u, v = e.v, d = e.w;
            if (dist[u] == INF) continue;
            dist[v] = min(dist[u] + d, dist[v]);
            dist[v] = max(dist[v], NINF);
        }
    }
    for (int i = 1; i < n; i++) {  // Negative cycle detection
        for (auto e : edges) {
            int u = e.u, v = e.v, d = e.w;
            if (dist[u] == INF) continue;
            dist[v] = max(dist[v], NINF);
            if (dist[u] + d < dist[v]) {
                dist[v] = NINF;
            }
        }
    }
}

void Solve() {
    int n, m; cin >> n >> m;
    dist.resize(n + 1, INF);
    edges.resize(m);
    for (int i = 0; i < m; i++) {  // Correct indexing
        int u, v, w; cin >> u >> v >> w;
        edges[i] = {u, v, -1 * w};
    }
    dist[1] = 0;  // Source initialization
    bellmanford(n);
    if(n==1)
    {
        bool check=false;
        for(auto e: edges)
		{
            if(e.w<0)
            {
                check=true;
                break;
            }
        }
        if(!check)
        {
        cout<<0<<endl; return;
        }
        else
        cout<<-1<<endl; return;
    }
    if (dist[n] == NINF) cout << -1 << endl;
    else if (dist[n] == INF) cout << -1 << endl;
    else cout << -1 * dist[n] << endl;
}

int32_t main() {
    Solve();
    return 0;
}
