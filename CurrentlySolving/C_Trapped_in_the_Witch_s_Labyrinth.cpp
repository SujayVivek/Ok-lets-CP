#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ff first
#define ss second
typedef vector<vector<long long>> vvi;
typedef vector<long long> vi;
#define int long long
#define endl "\n"

int n, m;
void calc(int i, int j, vvi &grid, vector<string>&v){
    if(grid[i][j]==1) return;
    grid[i][j]=1;
    if(i+1<n && v[i+1][j]=='U'){
        calc(i+1, j, grid, v);
    }
    if(i-1>=0 && v[i-1][j]=='D'){
        calc(i-1, j, grid, v);
    }
    if(j+1<m && v[i][j+1]=='L'){
        calc(i, j+1, grid, v);
    }
    if(j-1>=0 && v[i][j-1]=='R'){
        calc(i, j-1, grid, v);
    }
}
void Solve() {
    cin>>n>>m;
    vector<string> v(n);
    set<pair<int,int>>st;
    set<pair<int,int>>D;
    for(int i = 0; i<n; i++){
        cin>>v[i];
        for(int j = 0; j<m; j++){
            if(v[i][j]=='?') st.insert({i,j});
            if(v[i][j]=='U' && i==0)D.insert({i,j});
            if(v[i][j]=='L' && j==0)D.insert({i,j});
            if(v[i][j]=='R' && j==m-1)D.insert({i,j});
            if(v[i][j]=='D' && i==n-1)D.insert({i,j});
        }
    }
    vector<vector<int>> grid(n, vi(m,0));
    for(auto it: D){
        int i = it.first, j = it.second;
        calc(i, j, grid, v);
    }
    for(auto it: st){
        int i = it.first, j = it.second;
        bool ok = true;
        if(i+1<n && grid[i+1][j]!=1){
            ok&=false;
        }
        if(i-1>=0 && grid[i-1][j]!=1){
            ok&=false;
        }
        if(j-1>=0 && grid[i][j-1]!=1){
            ok&=false;
        }
        if(j+1<m && grid[i][j+1]!=1){
            ok&=false;
        }
        // cout<<ok<<" hi"<<endl;
        if(ok) grid[i][j]=1;
    }
    int cnt=0;
    // cout<<" helo"<<grid[1][1]<<endl;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(grid[i][j]==0){
                cnt++;
                // cout<<i<<" "<<j<<" "<<endl;
            }
        }
    }
    cout<<cnt<<endl;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}