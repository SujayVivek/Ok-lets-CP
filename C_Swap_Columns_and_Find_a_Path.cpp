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
    vvi v(2, vi(n, 0));
    int sumTop = 0, sumBottom = 0;
    for(int i = 0; i < n; i++) {cin>> v[0][i]; sumTop += v[0][i]; }
    int mx = -2*1e5 -1;
    int mxI = 0;
    for(int i = 0; i<n; i++){
        cin>>v[1][i];
        sumBottom += v[1][i];
        if((v[1][i] + v[0][i])> mx){
            mx = v[1][i] + v[0][i];
            mxI = i;
        }
    }
    // cout<<mx<<" hi "<<mxI<<endl;
    int A = -2*1e5-1, B = A;
    int ans = 0;
    for(int i = 0; i<n; i++){
        A = max(A, sumTop+v[1][i]);
        B = max(B, sumBottom+v[0][i]);
        if(i == mxI){
            ans += mx;
        }else{
             ans += max(v[1][i], v[0][i]);
        }
       
    }
    
    ans = max(ans, A);
    ans = max(ans, B);
    cout<<ans<<endl;return;

}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}