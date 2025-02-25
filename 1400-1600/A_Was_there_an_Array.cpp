#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define int long long

void Solve() {
    int n; cin>>n;
    n = n-2;
    vector<int> a(n,0);
    for(auto &x: a)cin>>x;
    if(n<=2){
        cout<<"YES"<<endl;return;
    }
    for(int i = 0; i<n-2; i++){
        if(a[i]==1 && a[i+1]==0 && a[i+2]==1){
            cout<<"NO"<<endl;return;
        }
    }
    cout<<"YES"<<endl; return;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}