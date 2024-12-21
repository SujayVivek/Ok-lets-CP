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
    int n, x, y; cin>>n>>x>>y;
    x--, y--;
    if(x>y)swap(x,y);
    vi ans(n, -1);
    ans[x] = 1, ans[y] = 0;
    for(int i = x+1; i<y; i++){
        ans[i] = 1-(ans[i-1]);
    }
    if(ans[y-1]==ans[y]) ans[y] = 2;
    for(int i = x-1; i>y-n; i--){
        ans[(i+n)%n] = 1-ans[(i+1+n)%n];
    }
    if(ans[(y+1)%n] == ans[y]) ans[(y+1)%n] = 2;
    for(auto it: ans)cout<<it<<" ";
    cout<<endl;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}