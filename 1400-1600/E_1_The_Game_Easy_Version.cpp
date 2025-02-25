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
vi Hash;
void dfs(int node){
    Hash[node] = 1;
    for(auto nn: g[node]){
        if(!Hash[nn])
        dfs(nn);
    }
}
void Solve() {
    int n; cin>>n;
    vvi v(n,vi(2));
    Hash.assign(n+1,0);
    for(int i = 0; i<n; i++){
        int W; cin>>W;
        v[i] = {W, i+1};
    }
    sort(v.begin(), v.end());
    g.assign(n+1, {});
    for(int i = 0; i<n-1; i++){
        int a, b; cin>>a>>b;
        g[b].push_back(a);
    }
    dfs(n); int ans = 0;
    bool ok1 = true, ok2 = true;
    for(int i = n-1; i>=0; i--){
        if(Hash[i]==0) {ans = v[i][1];ok1 = false; break;}
    }
    if(ok1==true){
        cout<<0<<endl;return;
    }
    dfs(ans-1);
    for(int i = ans; i>=0; i--){
        if(Hash[i]==0) {ok2 = false;}
    }
    if(ok2){
        cout<<ans<<endl;
    }else{
        cout<<0<<endl;
    }
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}