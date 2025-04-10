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
    int n, k, x; cin>>n>>k>>x;
    vi a(n,0); int S = 0;
    for(int i = 0; i<n; i++){
        cin>>a[i]; S+= a[i];
    } int T = 0;
    if(S<x) T+= x/S;
    int P = 0;
    int cnt = 0;
    for(int i = n-1; i>=0; i--){
        if(T*S + P>=x) break;
        P+= a[i];
        cnt++;
    }
    cout<< max(0ll, k*n-(cnt + T*n)+1)<<endl;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}