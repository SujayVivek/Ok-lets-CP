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
    int T = 0;
    int cnt = 0;
    int P = n/15;
    T = P-1;
    cnt+= T*3;
    while(T*15<=n){
        if(T*15<=n)cnt++;
        if(T*15+1<=n)cnt++;
        if(T*15+2<=n)cnt++;
        T++;
    }
    cout<<cnt<<endl;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}