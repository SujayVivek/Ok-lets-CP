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
    vi a(3);
    for(auto &x: a)cin>>x;
    sort(a.begin(), a.end());
    if(a[2]== a[0]*a[1]){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
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