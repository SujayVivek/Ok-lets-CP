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
    for(auto &x: a) cin>>x;
    bool ok = true;
    for(int i = 1; i<n; i++){
        if(a[i]<a[i-1]) ok = false;
    }
    if(ok){
        cout<<0<<endl;return;
    }
    if(a[n-2]>a[n-1] || (a[n-2]<0 && a[n-1]<0)){
        cout<<-1<<endl;return;
    }else{
        cout<<n-2<<endl;
        for(int i = 0; i<=n-3; i++){
            cout<<i+1<<" "<<n-1<<" "<<n<<endl;
        }
    }
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}