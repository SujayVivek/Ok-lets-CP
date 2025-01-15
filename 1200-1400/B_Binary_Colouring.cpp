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
    int x; cin>>x;
    vi ans;
    while(x){
        int cnt = 0;
        while(x&1){
            cnt++;
            x>>=1;
        }
        if(cnt<=1){
            ans.push_back(cnt);
            if(cnt==0)x>>=1;
        }
        else{
            ans.push_back(-1);
            cnt-=1;
            while(cnt--){
                ans.push_back(0);
            }
            x|=1;
        }
    }
    cout<<ans.size()<<endl;
    for(auto &x: ans){
        cout<<x<<" ";
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