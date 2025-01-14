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
    int l, r; cin>>l>>r;
    int T = 64 - __builtin_clzll(r);
    int s = 0; 
    int Q = 64 - __builtin_clzll(l);
    T--, Q--;
    int a = 1<<T;
    int b = a, c = a;  
    int index = 31;  
    while (index>=0 && index<=31) {  
        Q = 1<<index;
        if ((l&Q)!=(r&Q)) {  
            break; 
        } else {
            if (r&Q && l&Q)s+=Q; 
        } 
        index--;  
    }  
    T = s + (1<<index);
    if (T<r) {  
        cout <<T+1<<" "<<T-1<<" "<<T<<endl;  return;
    } 
    cout<<T<<" "<<T-2<<" "<<T-1<<endl;
    return;  
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}