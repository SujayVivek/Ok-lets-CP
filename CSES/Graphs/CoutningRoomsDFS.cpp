#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
typedef vector<int> vi;
#define int long long
#define endl "\n"

int n, m;
int dx[4] = {0,1,0,-1};
int dy[4] = {-1,0,1,0};

int check(int i, int j, vector<vector<char>> &v){
    if(i>=0 && i<n && j>=0 && j<m && v[i][j]=='.') return 1;
    return 0;
}

void dfs(int i, int j, int rooms, vector<vector<int>>&vis, vector<vector<char>>&v){
    vis[i][j] = rooms;
    for(int h = 0; h<4; h++){
        if(check(i+dx[h], j+dy[h], v) && !vis[i+dx[h]][j+dy[h]]){
            dfs(i+dx[h], j+ dy[h], rooms, vis, v);
        }
    }
    return;
}
void Solve() {
    cin>>n>>m;
    vector<vector<char>> v(n, vector<char>(m,'.'));
    set<pair<int,int>>st;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cin>>v[i][j];
            if(v[i][j]=='.') st.insert(make_pair(i, j));
        }
    }
    vector<vector<int>> vis(n,vector<int>(m,0));
    int rooms = 0;
    for(auto it: st){
        if(!vis[it.first][it.second] && check(it.first, it.second, v)){
            rooms++;
            dfs(it.first, it.second, rooms, vis, v);
        }
    }
    cout<<rooms<<endl;return;
}

int32_t main() {
    int tt_ = 1;
    // cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}