#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ff first
#define ss second
typedef vector<vector<long long>> vvi;
typedef vector<long long> vi;
#define int long long
#define endl "\n"

set<int> sumz;
vi pref;
void Cals(int start, int end, vi &a){
    if(start == end) a[start];
    int maximum = end, minimum = end;
    sumz.insert(pref[end]-pref[start-1]);
    int mid = start + (end-start)/2;
    Cals(start, mid, a)
    Cals(mid, end, a);
}
void Solve() {
    int n, q; cin>>n>>q;
    vi a(n,0);
    for(auto &x: a)cin>>x;
    sort(a.begin(), a.end());
    pref.assign(n+1,0);
    // pref[0] = a[0];
    for(int i = 1; i<=n; i++) pref[i] = pref[i-1] + a[i-1];
    sumz.clear();
    
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}