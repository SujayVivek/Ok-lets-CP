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
    vi ans;
    for(int i = 0; i<n; i++){
        int res = 0;
        for(int j = 0; j<4; j++){
                 char l; cin>>l;
                 if(l=='#') res = j+1;
        }
        ans.push_back(res);
    }
    for(int i = n-1; i>=0; i--){
        cout<<ans[i]<<" ";
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