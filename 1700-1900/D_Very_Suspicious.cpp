#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ff first
#define ss second
typedef vector<vector<long long>> vvi;
typedef vector<long long> vi;
#define int long long
#define endl "\n"

int check(int mid, int n){
    int x = mid/3, y = mid/3, z = mid/3;
    if(mid%3) x++;
    if(mid%3==2) y++;
    return 2*(x*y + y*z + z*x)>=n;
}
void Solve() {
    int n; cin>>n;
    int hi = 1e9, lo = 0;
    int ans = -1;
    while(lo<=hi){
        int mid = lo + (hi-lo)/2;
        if(check(mid, n)){
            ans = mid;
            hi = mid-1;
        }else{
            lo = mid + 1;
        }
    }
    cout<<ans<<endl;return;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}