#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ff first
#define ss second
typedef vector<vector<long long>> vvi;
typedef vector<long long> vi;
#define int long long
#define endl "\n"

bool doomed(int x, int y, char c, int a, int b){
    if(x==0 && c=='U'){
        return true;
    }else if(x==a-1 && c =='D'){
        return true;
    }else if(y==0 && c =='L'){
        return true;
    }else if(y==b-1 && c =='R'){
        return true;
    }
    return false;
}
void Solve() {
    int a, b;cin>>a>>b;
    vvi v(a, vi(b,0));
    set<pair<int,int>> stp;
    vvi doomer(a, vi(b,0));
    for(int i = 0; i< a; i++){
        for(int j = 0; j<b; j++){
            cin>>v[i][j];
            if(v[i][j]=='?'){
                stp.insert({i, j});
            }
        }
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