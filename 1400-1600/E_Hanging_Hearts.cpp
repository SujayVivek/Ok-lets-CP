#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ff first
#define ss second
typedef vector<vector<long long>> vvi;
typedef vector<long long> vi;
#define int long long
#define endl "\n"
priority_queue<int> pq;
vvi g;
vi vis;
int mx, NN, newMx, newNN;
void dfs(int node, int cnt){
    vis[node] = 1;
    if(cnt>mx){mx = cnt, NN = node;}
    for(auto nn: g[node]){
        if(!vis[nn])dfs(nn, cnt+1);
    }
}
void dfs2(int node, int cnt){
    vis[node] = 1;
    if(cnt>newMx){newMx = cnt, newNN = node;}
    for(auto nn: g[node]){
        if(!vis[nn])dfs(nn, cnt+1);
    }
}
void Solve() {
    int n; cin>>n;
    g.resize(n+2, vi());
    vis.assign(n+1, 0);
    for(int i = 1; i<n; i++){
        int x; cin>>x;
        g[x].push_back(i+1);
        g[i+1].push_back(x);
    } mx = 0, NN = 1;
    dfs(1,1);
    vis.assign(n+1, 0);
    newMx = 0, newNN = NN;
    dfs2(newNN, 1); int Ans = 0;
    if(newNN == 1) Ans++;
    cout<<Ans + newMx -1<<endl;
}

int32_t main() {
    int tt_ = 1;
    // cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}