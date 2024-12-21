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
    int n, k, q; cin>>n>>k>>q;
    vi a(k+1,0), b(k+1,0); a[0] = 0, b[0] = 0;
    for(int i = 1; i<=k; i++) cin>>a[i];
    for(int i = 1; i<=k; i++) cin>>b[i];
    while(q--){
        int d; cin>>d;
        int dist = lower_bound(a.begin(), a.end(), d) -a.begin();
        if(dist>0)dist--;
        cout<< b[dist] + ((d-a[dist])*(b[dist+1] - b[dist])/(a[dist+1] - a[dist]))<<" ";
    }cout<<endl;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}