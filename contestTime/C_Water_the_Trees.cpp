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
     vi h(n,0);
     int mx = 0;
     for(int i = 0; i<n; i++){
        cin>>h[i];
        mx = max(mx, h[i]);
    }
    int ans = 1e18;

    for(auto MX: {mx, mx+1}){
        int lo = 0, hi = 1e18;
        int res = 1e18;
        while(lo<=hi){
            int mid = (lo + hi)/2;
            int day1 = (mid + 1)/2, day2 = mid - day1;
            int req = 0;    
            for(auto x: h){
                int cur= (MX-x)/2;
                if((MX-x)%2==1){
                    req++;
                }
                if(day2>=cur){
                    day2-=cur;
                }else{
                    cur-=day2;
                    day2=0;
                    req+=cur*2;
                }
            } 
            if(req<=day1){
                res = mid;
                hi = mid -1;
            }else{
                lo = mid +1;
            }
        }
        ans = min(ans, res);
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