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
    int n, q; cin>>n>>q;
    vi a(n+1,0), x(n+1, 0);
    vvi v(n+1, vi(30,0));
    for(int i = 1; i<=n; i++){
        cin>>a[i];
        x[i] = x[i-1]^a[i];
        for(int j = 0; j<30; j++){
            v[i][j] = a[i]<(1<<j)? v[i-1][j]: i;
        }
    }
    while(q--){
        int X; cin>>X;
        int i = n, j;
        while(i>0 && X>0){
            j = v[i][__lg(X)];
            X^=x[i]^x[j];
            if(!j || X<a[j]) break;
            X^=a[j]; j--;
            i = j;
        }
        cout<<n-j<<" ";
    }cout<<endl;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}