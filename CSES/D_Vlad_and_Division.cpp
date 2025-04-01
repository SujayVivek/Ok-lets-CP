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
    int cnt = 0;
    map<int,int> mpp;
    vi a(n,0); for(auto &x: a)cin>>x;
    sort(a.begin(), a.end(), greater<int>());
    for(int i = 0; i<n; i++){
        int x; x = a[i];
        int sz = 64-__builtin_clzll(x);
        // cout<<x<<" "<<(((1<<(31))-1)^x)<<endl;
        if(mpp[x]!=0) {cnt++;mpp[x]--; continue;}
        mpp[((1<<(31))-1)^x]++;
    }
    cout<<n-cnt<<endl;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}