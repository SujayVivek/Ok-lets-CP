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
    int n, m; cin>>n>>m;
    vvi a(n,vi(m,0));
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cin>>a[i][j];
        }
    }
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            int mx = 0;
            if(i<n-1){
                mx = max(mx, a[i+1][j]);
            }
            if(i>0){
                mx = max(mx, a[i-1][j]);
            }
            if(j<m-1){
                mx = max(mx, a[i][j+1]);
            }
            if(j>0){
                mx = max(mx, a[i][j-1]);
            }
            if(a[i][j]>mx){
                a[i][j] = mx;
            }
        }
    }
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cout<<a[i][j]<<" ";
        }cout<<endl;
    }
    return;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}