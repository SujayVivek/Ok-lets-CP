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
    vi a(n,0), b(n,0);
    for(auto &x: a)cin>>x;
    for(auto &y: b)cin>>y;
    int s = 0;
    for(int i = 0; i<n-1; i++){
        if(a[i]>b[i+1])s+= a[i]-b[i+1];
    } 
    s+=a[n-1];
    cout<<s<<endl;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}