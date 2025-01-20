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
    for(int i = 0; i<n; i++){
        cin>>a[i];
    } int mn = 1e8+1, mx = 0;
    for(int i = 0; i<n-1; i++){
        if(a[i]<a[i+1]) mn = min((a[i]+a[i+1])/2, mn);
        else if(a[i]>a[i+1])
            mx = max((a[i] + a[i + 1] + 1) / 2, mx);
    }
    if(mx>mn){
        cout<<"-1"<<endl;
    }else{
        cout<<mn<<endl;
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