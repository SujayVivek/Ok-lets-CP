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
    int n; cin>>n;
    vvi g(n+1);
    for(int i = 1; i<=n-1; i++){
        int a, b; cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int leaf = 0;
    for(int i = 1; i<=n; i++){
        if(g[i].size()==1) leaf++;
    }
    map<int,int> mpp;
    int ans = leaf*(n-leaf);
    int adjleaf = 0;
    for(int i = 1; i<=n; i++){
        if(g[i].size()>1){
            for(auto v: g[i]){
                mpp[i] += (g[v].size()>1);
                adjleaf += (mpp[i]==g[i].size());//we want only those places that has not adj node as a leaf
            }
        }
    }
    for(int i = 1; i<=n; i++){
        if(g[i].size()>1 && mpp[i]!=g[i].size()){//we want those whose next nodes are leaves
            ans+= adjleaf*(mpp[i]-1);//important
        }
    }
    cout<<ans<<endl;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}