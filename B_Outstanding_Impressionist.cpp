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
    map<int,int> mpp;
    vector<pair<int,int>>vp;
    vi hash(2*n+5, 0);
    for(int i = 0; i<n; i++){
        int l, r; cin>>l>>r;
        vp.push_back({l,r});
        if(l==r){
            mpp[l]++;
            hash[l] = 1;
        }
    }
    for(int i = 1; i<hash.size(); i++){
        hash[i]+= hash[i-1];
    }
    for(auto it: vp){
        int l = it.first, r = it.second;
        if(l==r){
            if(mpp[l]>1) cout<<0;
            else cout<<1;
        }else{
            bool ok =false;
            if(hash[r]-hash[l-1]>=(r-l+1)) ok = true;
            if(ok) cout<<0;
            else cout<<1;
        }
    }cout<<endl;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}