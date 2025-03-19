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
    int n, H, M; cin>>n>>H>>M;
    int Time = H*60 + M;
    vi clock;
    for(int i = 0; i<n; i++){
        int h, m; cin>>h>>m;
        clock.push_back(h*60 + m);
    }
    sort(clock.begin(), clock.end());
    int P = lower_bound(clock.begin(), clock.end(), Time)-clock.begin();
    int d = 0;
    if(P==n) {P = 0; d= 24*60;}
    Time = clock[P]-Time + d;
    cout<<Time/60<<" "<<Time%60<<endl;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}