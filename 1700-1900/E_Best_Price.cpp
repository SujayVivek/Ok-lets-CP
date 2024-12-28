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
    int n, k; cin>>n>>k;
    vi a(n, 0), b(n,0); set<int> st; int ans = 0;
    for(auto &x: a){ cin>>x; st.insert(x);}
    for(auto &x: b){ cin>>x; st.insert(x);}
    sort(a.begin(), a.end()), sort(b.begin(), b.end());
    for(auto p: st){
        int A = lower_bound(b.begin(), b.end(), p) - b.begin();
        A = n-A;
        int B = lower_bound(a.begin(), a.end(), p) - a.begin();
        B = n-B;
        if(A-B<=k) ans = max(ans, A*p);
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