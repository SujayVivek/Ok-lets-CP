#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ff first
#define ss second
typedef vector<vector<long long>> vvi;
typedef vector<long long> vi;
#define int long long
#define endl "\n"

vi cost; string s;
int n, k;
int check(int mid){
    int Seg = 0, segOk = 0;
    for(int i = 0; i<s.length(); i++){
        if(segOk){
            if(s[i]=='R' && cost[i]>mid) segOk = 0;
        }else{
            if(s[i]=='B' && cost[i]>mid){
                Seg++; segOk = 1;
            }
        }
    }
    if(Seg<=k) return 1;
    else return 0;
}
void Solve() {
    cin>>n>>k;
    cin>>s;
    cost.assign(n,0); int mx = 0;
    for(auto &x: cost) {cin>>x; mx = max(mx, x);}
    int lo = 0, hi = mx, ans = -1;
    while(lo<=hi){
        int mid = lo + (hi-lo)/2;
        if(check(mid)){
            ans = mid;
            hi = mid-1;
        }else{
            lo = mid + 1;
        }
    }
    cout<<ans<<endl;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}