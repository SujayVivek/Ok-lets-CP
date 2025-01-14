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
    int n, m; string s; 
    cin>>n>>m>>s;
    vvi grid(n, vi(m));
    vi rows(n,0), cols(m,0);
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cin>>grid[i][j];
            rows[i]+= grid[i][j];
            cols[j]+= grid[i][j];
        }
    }
    int x = 0, y = 0;
    for(int i = 0; i<s.length(); i++){
        if(s[i]=='D'){
            grid[x][y] -= rows[x];
            rows[x]+= grid[x][y];
            cols[y]+= grid[x][y];
            x++;
        }else{
            grid[x][y]-= cols[y];
            cols[y]+= grid[x][y];
            rows[x]+= grid[x][y];
            y++;
        }
    }
    grid[x][y]-= rows[x];
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cout<<grid[i][j]<<" ";
        }cout<<endl;
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