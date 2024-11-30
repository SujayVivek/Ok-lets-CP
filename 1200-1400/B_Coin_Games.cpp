#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
typedef vector<int> vi;
#define int long long
#define endl "\n"

void Solve() {
    int n;cin>>n;
     string s; cin>>s;
     int c = 0;
     for(auto x: s){
        if(x=='U') c++;
     }
     if(c%2==0) cout<<"NO"<<endl;
     else cout<<"YES"<<endl;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}