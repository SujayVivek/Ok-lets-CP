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
    int fn_x = 0, fn_y = 0;
    int stx = 0, sty = 0;
    for(int i = 0; i<n; i++){
        int x, y; cin>>x>>y;
        if(!i){
            stx = x, sty = y;
        }
        fn_x+=x, fn_y+= y;
    }
    cout<<2*(fn_x+fn_y+2*m - stx - sty)<<endl;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}