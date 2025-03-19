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
    int m;cin>>m;
    vi a(m,0);
    for(auto &x: a)cin>>x;
    bool ok=0; int cnt=0;
    for(int k=1;k<m;k=k<<1){
        for(int i=0;i<m;i+=2*k){
            if(abs(a[i]-a[i+k])!=k) ok=1;
            if(a[i]>a[i+k]) {
                swap(a[i],a[i+k]);
                cnt++;
            }
        }
    }
    cout<<(ok?-1:cnt)<<"\n";
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}