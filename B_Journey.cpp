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
    int n, a, b, c; cin>>n>>a>>b>>c;
    int s = a+b+c;
    int ans = 3*(n/s);
    n%=s;
    if(n>0){n-=a; ans++;}
    if(n>0){n-=b; ans++;}
    if(n>0){n-=c; ans++;}
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