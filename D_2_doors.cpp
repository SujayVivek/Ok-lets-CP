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
    int n, q; cin>>n>>q;
    vector<vector<pair<int,int>>>g(n+1);
    vi v(n+1, (1<<30)-1);
    for(int i = 0; i<q; i++){
        int a, b, c; cin>>a>>b>>c;
        a--, b--;
        g[a].push_back({b, c});
        g[b].push_back({a, c});
    }
    for(int bit = 0; bit<30; bit++){
        for(int i = 0; i<n; i++){
            for(auto x: g[i]){
                if(((x.second>>bit)&1)==0){
                    v[i]&=~(1<<bit);
                }
            }
        }
        for(int i = 0; i<n; i++){
            bool ok = true;
            if((v[i]>>bit)&1){
                for(auto x: g[i]){
                    if(x.first == i) {
                        ok = false; break;
                    }
                    if(!((v[x.first]>>bit)&1)){
                        ok = false; break;
                    }
                }
            }
            if(ok) v[i]&= ~(1<<bit);
        }
    }
    for(int i = 0; i<n; i++) cout<<v[i]<<" ";
    cout<<endl;
}

int32_t main() {
    int tt_ = 1;
    // cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}