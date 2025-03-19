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
    vi a, a_;
    for(int i = 0; i<n; i++){
        int x; cin>>x;
        a.push_back(x);
    }int L_min = n, R_max = -1;
    for(int i = 0; i<n; i++){
        int x; cin>>x;
        a_.push_back(x);
        if(a[i]!=a_[i]){
            L_min = min(i, L_min) ;
            R_max = max(i, R_max);
        }
    }int mn = 1e18, mx = 0; 
    for(int i = L_min; i<=R_max; i++){
        mn = min(mn, a_[i]), mx = max(mx, a_[i]);
    }
    while(L_min>0){
        if(a_[L_min-1]<=a_[L_min]) L_min--;
        else break;
    }
    while(R_max<n-1){
        if(a_[R_max+1]>=a_[R_max]) R_max++;
        else break;
    }
    cout<<L_min+1<<" "<<R_max+1<<endl;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}