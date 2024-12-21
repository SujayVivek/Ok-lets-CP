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
    map<int,int> mppx, mppy;
    map<vector<int>, int> NegSlope, PosSlope;
    vector<pair<int,int>> vp;
    while(n--){
        int x, y; cin>>x>>y;
        vp.push_back({x,y});
        mppx[x]++;
        mppy[y]++;
        // if(x==0 && y==0)continue;
        PosSlope[{x-y, 0, 0, y-x}]++;
        NegSlope[{x + y, 0, 0, x+y}]++;
        // if(x!=0){PosSlope[{0, y-x}]++, NegSlope[{0, x+y}]++;}
    }
    int ans = 0;
    for(auto it: mppx){
        ans+= (it.second*(it.second-1));
    }
    for(auto it: mppy){
        ans+= (it.second*(it.second-1));
    }
    for(auto it: PosSlope){
        ans+= (it.second*(it.second-1));
    }
    for(auto it: NegSlope){
        ans+= (it.second*(it.second-1));
    }
    cout<<ans<<endl;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}