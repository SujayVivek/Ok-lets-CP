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
    vi a(n,0);
    for(int i = 0; i<n; i++){
        cin>>a[i];
        a[i]--;
    }
    int last = n;
    while(last>0 && a[last-1] == last-1){
        last--;
    }
    double fail = last>0 ?  1:0;
    for(int i = 0; i<m; i++){
        int r; cin>>r;
        double p; cin>>p;
        if(r>=last){
            fail*= (1-p);
        }
    }
    cout<<1-fail<<endl;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}