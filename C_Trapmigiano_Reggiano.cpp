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
    int n, st, en; cin>>n>>st>>en;
    vvi g(n+1, vi());
    vi vis(n+1, 0);
    for(int i = 1; i<=n-1; i++){
        int a, b; cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vi q;
    q.push_back(en);
    vis[en] =1 ;
    for(int i= 0; i<n; i++){
        int first = q[i];
        for(auto nn: g[first]){
            if(!vis[nn]){
                vis[nn] = 1;
                q.push_back(nn);
            }
        }
    }
    reverse(q.begin(), q.end());
    for(auto x: q)cout<<x<<" ";
    cout<<endl;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}