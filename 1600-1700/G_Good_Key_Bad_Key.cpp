#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ff first
#define ss second
typedef vector<vector<long long>> vvi;
typedef vector<long long> vi;
#define int long long
#define endl "\n"

const int D = 1e9;
int n, k; 
vi v;

int calc(map<pair<int,int>, int>&mdp, int idx, int d){
    if(idx>=n) return 0;
    if(d>D) return 0;
    if(mdp.find({idx, d})!=mdp.end()){
        return mdp[{idx, d}];
    }
    int left = calc(mdp, idx+1, d) + v[idx]/d - k;
    int right = calc(mdp, idx + 1, d*2)+ v[idx]/(2*d);
    return mdp[{idx, d}] = max(left, right);
}
void Solve() {
    cin>>n>>k;
    v.assign(n,0);
    for(auto &x: v) cin>>x;
    map<pair<int,int>,int> mdp;
    int result = calc(mdp, 0, 1);
    cout<<result<<endl;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}