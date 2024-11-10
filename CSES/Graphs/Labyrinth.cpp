#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
typedef vector<int> vi;
#define int long long
#define endl "\n"

int n, m;
const int N = 1001;
vector<vector<int>>dist(N, vector<int>(N,1e9));
vector<vector<pair<int,int>>> par(N, vector<pair<int,int>>(N, {0,0}));
vector<pair<int,int>> PATH;
int dx[4] = {0,1,0,-1};
int dy[4] = {-1,0,1,0};

int check(int i, int j, vector<vector<char>>&v){
    if(i>=0 && i<n && j>=0 && j<m && v[i][j]!='#') return 1;
    return 0;
}
char dir(pair<int,int> P, pair<int,int> Q){
    // cout<<P.first<<" "<<Q.first<<endl;
    if(P.first == Q.first){
        if(Q.second - P.second == 1) return 'L';
        else return 'R';
    }
    else{
        if(Q.first - P.first == 1) return 'U';
        else return 'D';
    }
}
void ppath(pair<int,int> B){
    if(B.first == -1 && B.second == -1) return;
    ppath(par[B.first][B.second]);
    PATH.push_back(make_pair(B.first, B.second));
}
void bfs(pair<int,int>start, pair<int,int>end, vector<vector<char>>&v){
    queue<pair<int,int>>q;
    q.push(start);
    dist[start.first][start.second] = 0;
    par[start.first][start.second] = {-1, -1};
    while(!q.empty()){
        pair<int,int> pos = q.front(); q.pop();
        for(int h = 0; h<4; h++){
            if(check(pos.first + dx[h], pos.second + dy[h], v) && dist[pos.first + dx[h]][pos.second + dy[h]] > 1  + dist[pos.first][pos.second]){
                dist[pos.first + dx[h]][pos.second + dy[h]] = 1  + dist[pos.first][pos.second];
                q.push(make_pair(pos.first + dx[h], pos.second + dy[h]));
                par[pos.first+ dx[h]][pos.second + dy[h]] = make_pair(pos.first, pos.second);
            }
        }
    }
}
void Solve() {
    cin>>n>>m;
    vector<vector<char>>v(n, vector<char>(m,'.'));
    pair<int,int> A,B;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cin>>v[i][j];
            if(v[i][j]=='A') A = make_pair(i,j);
            if(v[i][j]=='B') B = make_pair(i,j);
        }
    }
    bfs(A, B, v);
    if(dist[B.first][B.second] == 1e9){
        cout<<"NO"<<endl;return;
    }
    cout<<"YES"<<endl;
    cout<< dist[B.first][B.second]<<endl;
    // PATH.push_back(make_pair(A.first, A.second));
    ppath(B);
    for(int i = 1; i< PATH.size(); i++){
        cout<< dir(PATH[i], PATH[i-1]);
    }cout<<endl;
    return;
}


int32_t main() {
    int tt_ = 1;
    // cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}