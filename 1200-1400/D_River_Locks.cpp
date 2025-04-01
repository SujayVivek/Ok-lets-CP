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
    vi v(n,0);
    for(auto &x: v)cin>>x;
    for(int i = n-2; i>=0; i--){
        v[i]+=v[i+1];
    } int q; cin>>q;
    reverse(v.begin(), v.end());
    while(q--){
        int T = 0;
        int t; cin>>t;
        int cnt = 0; bool ok = false; int prev = 0;
        while(T<n){
            int newT = upper_bound(v.begin() + T, v.end(), t+prev)-v.begin(); 
            cnt++; prev = T;
            if(T>=newT-1){cout<<-1<<endl; ok = true; break;}
            T = newT;
        }
        if(!ok)cout<<cnt<<endl;
    }
 }

int32_t main() {
    int tt_ = 1;
    // cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}