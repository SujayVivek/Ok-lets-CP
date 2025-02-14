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
    int n, m; cin>>n>>m;
    vi a(n,0), b(m,0);
    for(int i = 0; i<n; i++) cin>>a[i];
    for(int i = 0; i<m; i++) cin>>b[i];
    sort(b.begin(), b.end());
    a[0] = min(a[0], b[0]-a[0]);
    for(int i = 1; i<n; i++){
        int idx = lower_bound(b.begin(), b.end(), a[i-1]+a[i]) - b.begin();
        if(idx>=m){
            // cout<<"eheleo";
            continue;
        }
        // cout<<idx<<" hi";
        int A = a[i];
        if(b[idx]-a[i]>=a[i-1]){
            A = b[idx]-a[i];
        }
        if(a[i]>=a[i-1]) A = min(A, a[i]);
        a[i] = A;
    }
    for(int i = 0; i<n-1; i++){
        if(a[i]>a[i+1]){
            cout<<"NO"<<endl;return;
        }
        // cout<<a[i]<<" ";
    }
    cout<<"YES"<<endl;return;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}