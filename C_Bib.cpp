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
    vi P(n+1,0), Q(n+1,0);
    map<int,int> mpp;
    for(int i = 1; i<=n; i++){
        cin>>P[i];
    }
    for(int i = 1; i<=n; i++){
        cin>>Q[i];
        mpp[Q[i]] = i;
    }
    for(int i = 1; i<=n; i++){
        cout<<Q[P[mpp[i]]]<<" ";
    }cout<<endl;
    
}

int32_t main() {
    int tt_ = 1;
    // cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}