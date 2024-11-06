#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
typedef vector<int> vi;
#define int long long
#define endl "\n"

void Solve() {
    int n;cin>>n;
    vi a(n,0), b(n,0);
    for(auto &x: a)cin>>x;
    for(auto &x: b)cin>>x;
    int i = 0, j = 0;
    int c = 0;
    while(i<n && j<n){
        if(a[i]>b[j]){
            c++; j++;
        }else{
            i++;j++;
        }
    }
    cout<<c<<endl;return;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}
