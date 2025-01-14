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
    vi a(n+1, 0);
    for(int i = 1; i<=n; i++){
        cin>>a[i];
    }
    sort(a.begin(), a.end());
    int proxy = 0;
    for(int i = n; i>=1; i--){
        int v = a[i]-a[i-1];
        if(v>0){
            if(proxy == 0){
                proxy = 1;
            }else if(v == 1){
                proxy = 0;
            }
        }
    }
    if(proxy) cout<<"Alice"<<endl;
    else cout<<"Bob"<<endl;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}