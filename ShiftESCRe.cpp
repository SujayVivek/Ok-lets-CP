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
    int n, m, k; cin>>n>>m>>k;
    vvi grid(n, vi(m, -1));
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cin>>grid[i][j];
        }
    }
    vi prevDp(m, 1e18);
    vi curDp, curKDp;
    prevDp[0]= 0;
    for(int i = 0; i<n; i++){
        curDp = vi(m,1e18);
        for(int s= 0; s<m; s++){
            curKDp = vi(m, 1e18);
            for(int j = 0; j<m; j++){
                int curval = grid[i][(j+s)%m];
                curKDp[j] = min(curKDp[j], prevDp[j]+ k*s + curval);
                if(j>0) curKDp[j] = min(curKDp[j], curKDp[j-1] + curval);
            }
            for(int r = 0; r<m; r++) curDp[r] = min(curDp[r], curKDp[r]);
        }
        prevDp = curDp;
    }
    cout<<prevDp[m-1]<<endl;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}