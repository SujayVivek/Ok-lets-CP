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
    if(n==1) {
        cout<<1<<endl;return;
    }
    if(n<=4){
        cout<<2<<endl;return;
    }
    int j = 4;
    int cnt = 0;
    while(j<n){
        cnt++;
        j = 2*(j+1);
    }
    cout<<cnt+2<<endl;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}