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
    int M = 998244353;
    int n; cin>>n;
    vi a(n,0);  map<int,int> mpp;
    for(int i = 0; i<n; i++){
        cin>>a[i];
    }
    for(int i = 0; i<n; i++){
        int x; cin>>x;
        mpp[a[i]] = x;
    }
    int m; cin>>m;
    vi b(m,0);
    for(int i = 0; i<m; i++){
        cin>>b[i];
    } bool ok = true;
    for(int i = 0; i<m; i++){
        int x; cin>>x;
        if(!mpp[b[i]]){ ok = false;}
        else{
            int T = mpp[b[i]];
            mpp[b[i]] = T-x;
            if(T-x<0) ok = false;
        }
    }
    if(!ok){cout<<0<<endl;return;} int Ans = 1;
    for(auto it: mpp){
        if(it.second!=0){
            Ans = (Ans*2)%M;
        }
    }
    cout<<Ans<<endl;
}

int32_t main() {
    int tt_ = 1;
    // cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}