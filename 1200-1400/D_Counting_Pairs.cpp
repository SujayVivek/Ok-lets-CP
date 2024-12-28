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
    int n, x, y; cin>>n>>x>>y;
    vi a(n,0); int s = 0;
    for(int i = 0; i<n; i++){
        cin>>a[i];
        s+=a[i];
    }
    int Uper = s-x, Lower = s-y;
    int ans = 0;
    sort(a.begin(), a.end());
    for(int i = 0; i<n; i++){
        if(a[i]>=Uper) break;
        int dis1 = lower_bound(a.begin(), a.end(), Lower-a[i]) - a.begin();
        int dis2 = upper_bound(a.begin(), a.end(), Uper-a[i]) - a.begin();
        ans+= dis2-dis1;
        ans-= (s-2*a[i]>=x && s-2*a[i]<=y)?1:0; // if a[i]+a[i] on removal lies between x and y, then it means we are removing the same digit twice
    }
    ans/=2;
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