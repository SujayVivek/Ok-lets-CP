#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ff first
#define ss second
typedef vector<vector<long long>> vvi;
typedef vector<long long> vi;
#define int long long
#define endl "\n"

int points(int X, int x, int r){
    int lo = 0, hi = r; int ans = -1;
    while(lo<=hi){
        int mid = lo + (hi - lo)/2;
        if((mid*mid + (X-x)*(X-x)) <= r*r){
            lo = mid + 1;
            ans = mid;
        }else{
            hi = mid -1;
        }
    }
    return ans;
}
void Solve() {
    int n, m; cin>>n>>m;
    vector<pair<int,int>>vp;
    for(int i = 0; i<n; i++){
        int x, r; cin>>x>>r;
        vp.push_back({x, r});
    }
    sort(vp.begin(), vp.end());
    map<int, pair<int,int>>mpp;
    for(int i = 0; i<n; i++){
        int x = vp[i].first, r = vp[i].second;
        for(int j = x-r; j<=x+r; j++){
            if(mpp[j].second){ if(mpp[j].second < r) mpp[j] = {x, r};}
            else mpp[j] = {x, r};
        }
    }int pts = 0;
    for(auto it: mpp){
        pts+= points(it.first, it.second.first, it.second.second);
    }
    cout<<2*pts<<endl;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}