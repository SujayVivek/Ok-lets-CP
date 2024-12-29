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
    vi a(n,0);
    for(auto &x: a)cin>>x;
    int cnt = 0;
    if(n==1){cout<<"YES"<<endl; return;}
    // sort(a.begin(), a.end());
    for(int i = 0; i<n-1; i++){
        if(a[i]<=a[i+1] && a[i]*2>a[i+1])cnt++;
        else if(a[i]>a[i+1] && a[i]<2*a[i+1])cnt++;
    }
    if(cnt>=1 || (n==2 && cnt>=1))cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}