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
    vi a(n,0);
    for(int i = 0; i<n; i++){
        cin>>a[i];
    }
    set<int> St;
    vi Final(n+1,0);
    int Lower = 0;
    for(int i = n-1; i>=0; i--){
        if(i!=n-1) Lower = distance(St.upper_bound(a[i]-1), St.begin());
        St.insert(a[i]);
        Final[Lower+a[i]] = i+1;
    }
    for(auto x: Final)cout<<x<<" ";
    cout<<endl;
}

int32_t main() {
    int tt_ = 1;
    // cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}