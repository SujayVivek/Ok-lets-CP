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
    int n, w; cin>>n>>w;
    vvi Tetris(w+1);
    vector<pair<int,int>>A;
    for(int i = 0; i<n; i++){
        int x, y; cin>>x>>y;
        Tetris[x].push_back(y);
        A.push_back({x,y});
    }
    vi maxes; int mxY = 0;
    for(int i = 1; i<=w; i++){
        sort(Tetris[i].begin(), Tetris[i].end());
        mxY = max(mxY, 1ll*Tetris[i].size());
    }
    for(int i = 0; i<=mxY; i++){
        int mx = 0;
        for(int j = 1; j<=w; j++){
            if(Tetris[j].size()>i)
                mx = max(mx, Tetris[j][i]);
        }
        maxes.push_back(mx);
    }
    int Q; cin>>Q;
    while(Q--){
        int T, a; cin>>T>>a;
        a--;
        int x_pos = A[a].first, y_pos = A[a].second;
        int mxy_pos = lower_bound(Tetris[x_pos].begin(), Tetris[x_pos].end(), y_pos)-Tetris[x_pos].begin();
        if(T<maxes[mxy_pos]){
            cout<<"Yes"<<endl;
        }else{
            cout<<"No"<<endl;
        }
    }
}

int32_t main() {
    int tt_ = 1;
    // cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}