#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
typedef vector<int> vi;
#define int long long
#define endl "\n"

int rooms = 0;
int n, m;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int check(int i, int j, vector<vector<char>>&v){
    if(i<n && i>=0 && j<m && j>=0 && v[i][j]!='#'){
        return 1;
    }
    return 0;
}
void bfs_(int i, int j, int rooms, vector<vector<int>>&vis, vector<vector<char>>&v){
    queue<pair<int,int>> q;
    q.push(make_pair(i,j));
    while(!q.empty()){
        auto pos = q.front(); q.pop();
        vis[pos.first][pos.second] = rooms;
        for(int a = 0; a<4; a++){
            if(check(pos.first+dx[a], pos.second+dy[a], v) && !vis[pos.first + dx[a]][pos.second + dy[a]])
                q.push(make_pair(pos.first+dx[a], pos.second+dy[a]));
        }
    }
    return;
}
void Solve() {
    cin>>n>>m;
    set<pair<int,int>> st;
    vector<vector<char>> v(n,vector<char>(m,'.'));
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cin>>v[i][j];
            if(v[i][j]=='.') st.insert(make_pair(i,j));
        }
    }
    rooms = 0;
    vector<vector<int>> vis(n, vector<int>(m,0));
    for(auto it: st){
        if(!vis[it.first][it.second]){
            rooms++;
            bfs_(it.first, it.second, rooms, vis, v);
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