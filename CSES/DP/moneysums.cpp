#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
typedef vector<int> vi;
#define int long long
#define endl "\n"

void Solve() {
    int n;cin>>n;
     vi a(n,0);
    bitset<100001> bts;
    bts[0] = 1;
    for(int i = 0; i<n; i++){
        int x; cin>>x;
        bts |= bts<<x;
    }
    vi ans;
    for(int i = 1; i<100001; i++){
        if(bts[i]) ans.push_back(i);
    }
    cout<<ans.size()<<endl;
    for(auto &x: ans){
        cout<<x<<" ";
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