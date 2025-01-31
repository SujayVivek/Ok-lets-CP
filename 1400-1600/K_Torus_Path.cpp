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
    int grid[n][n];
    int S = 0;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            cin>>grid[i][j];
            S += grid[i][j];
        }
    }
    int Ans = 0;
    for(int i = 0; i<n; i++){
        Ans = max(Ans, S-grid[i][n-1-i]);
    }
    cout<<Ans<<endl;
}
int32_t main() {
    int tt_ = 1;
    // cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}