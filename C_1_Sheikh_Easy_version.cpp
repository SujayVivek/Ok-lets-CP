#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ff first
#define ss second
typedef vector<vector<long long>> vvi;
typedef vector<long long> vi;
#define int long long
#define endl "\n"

bool check(int mid, vi pref, vi xo, int mx, int hi){
    int T =( pref[hi]-pref[mid]) - (xo[mid]^xo[hi]);
    return T>mx;
}
void Solve() {
    int n, q; cin>>n>>q;
    vi a(n,0), pref(n,0), xo(n,0);
    for(int i = 0; i<n; i++){
        cin>>a[i];
        if(!i){pref[i]= a[i], xo[i] = a[i];}
        else{pref[i]= pref[i-1] + a[i], xo[i] = xo[i-1]^a[i];}
    }
    
    while(q--){
        int L, R; cin>>L>>R; L--, R--;
        int az = 0;
        for(int hi = L; hi<=R; hi++){
            int Hi = hi;
            int lo = L;
            int mx = 0;
            while(lo<=hi){
                int mid = lo + (Hi - lo)/2;
                if(check(mid, pref, xo, mx, Hi)){
                    Hi = mid-1;
                    mx = 
                }else{

                }
            }
        }
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