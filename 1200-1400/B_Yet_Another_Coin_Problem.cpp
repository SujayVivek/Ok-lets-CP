#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ff first
#define ss second
typedef vector<vector<long long>> vvi;
typedef vector<long long> vi;
#define int long long
#define endl "\n"
int calc(int n){
    int cnt = 0;
    cnt+=n/15;n%=15;
    cnt+=n/6; n%=6; 
    cnt+=n/3; n%=3; 
    cnt+=n; return cnt;
}
void Solve() {
    int n; cin>>n;int ans = 1e18;
    if(n>=20){
        ans = min({calc(n-20) + 2, calc(n-10) + 1, calc(n)});
    }else if(n>=10){
        ans = min({calc(n-10) + 1, calc(n)});
    }else{
        ans = calc(n);
    }cout<<ans<<endl;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}