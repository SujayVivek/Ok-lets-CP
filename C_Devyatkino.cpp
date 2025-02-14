#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ff first
#define ss second
typedef vector<vector<long long>> vvi;
typedef vector<long long> vi;
#define int long long
#define endl "\n"

bool check(int n){
    bool ok = false;
    while(n){
        if(n%10==7){ok = true; break;}
        n/=10;
    }
    return ok;
}
void Solve() {
    int n; cin>>n;
    int ans = 1e18;
    for(int k = 9; k<1e18; k = k*10+9){
        int cnt = 0;
        int P = n;
        while(!check(P)){
            cnt++;
            P+= k;
        }
        ans = min(ans, cnt);
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