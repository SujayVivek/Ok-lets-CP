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
    int n, k; cin>>n>>k;
    vi a(n,0);
    for(auto &x: a) cin>>x;
    sort(a.begin(), a.end());
    int c = 0;
    for(int i = n-1; i>=0; i--){
        k-=a[i];
        if(k<0){
            c = k+a[i];
            break;
        }
    }
    if(k>0){
        c = k;
    }
    cout<<c<<endl;return;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}