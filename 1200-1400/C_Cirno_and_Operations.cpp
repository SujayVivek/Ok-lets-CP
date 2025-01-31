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
    vi a(n,0);
    for(auto &x: a)cin>>x;
    int N = n;
    while(N>1){
        if(a[0]>a[1])reverse(a.begin(),a.end());
        for(int i = 0; i<N-1; i++){
            a[i] = a[i+1]-a[i];
        }
        N--;
    }
    cout<<a[0]<<endl;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}