#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define int long long

void Solve() {
    int n, m; cin>>n>>m;
    vector<vector<int>>grid(n,vector<int>(m,0));
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cin>>grid[i][j];
        }
    }
    set<int> colors, sides;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            colors.insert(grid[i][j]);
            if(j<m-1 && grid[i][j]==grid[i][j+1]) sides.insert(grid[i][j]);
            if(i<n-1 && grid[i][j]==grid[i+1][j]) sides.insert(grid[i][j]);
        }
    }
    if(colors.size()==1){cout<<0<<endl;return;}
    cout<<max(0ll,1LL*sides.size()-1)*2 + max(0LL, 1LL*colors.size()-sides.size()+ 1LL*((sides.size()!=0)?0:-1))<<endl;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}