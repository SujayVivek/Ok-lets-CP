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
    int n, d; cin>>n>>d;
    cout<<1<<" ";
    if(d%3==0 || n>=3) cout<<3<<" ";
    if(d==5) cout<<5<<" ";
    if(n>=3 || d==7) cout<<7<<" ";
    if(n>=6 || d==9 || (d%3==0 && n>=3)) cout<<9<<" ";
    cout<<endl;return;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}