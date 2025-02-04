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
    int n, q; cin>>n>>q;
    set<int> db;
    vi hash(n+1,1);
    map<int,int> mpp;
    for(int i = 1; i<=n; i++){
        mpp[i] = i;
    }
    while(q--){
        int a; cin>>a;
        if(a == 1){
            int P, H; cin>>P>>H;
            hash[H]++;
            hash[mpp[P]]--;
            if(hash[mpp[P]]<=1){
                auto it = db.find(mpp[P]);
                if(it!=db.end()) db.erase(it);
            }
            mpp[P] = H;
            if(hash[H]>1) db.insert(H);
        }else{
            cout<<db.size()<<endl;
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