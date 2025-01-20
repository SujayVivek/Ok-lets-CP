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
    vi a(4,0);
    for(auto &x: a)cin>>x;
    int A = a[0] + a[1];
    int cnt1 = 1, cnt2 = 1;
    if(a[1] + A == a[2]) cnt1++;
    if(A + a[2] == a[3]) cnt1++;
    // cout<<A<<" hi"<<cnt1<<endl;
    A = a[3] - a[2];
    if(a[0] + a[1] == A) cnt2++;
    if(a[1] + A == a[2]) cnt2++;
    // cout << A << " hi" << cnt2 << endl;
    cout<<max(cnt1, cnt2)<<endl;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}