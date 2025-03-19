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
    int n, k; cin>>n>>k;
    vi a(n,0);  for(auto &x: a) cin>>x; vi b = a;
    sort(a.begin(), a.end(), greater<int>()); int S = 0;
    if(k==1){
        for(int i = 1; i<n-1; i++){
            int A = b[i] + b[0];
            int B = b[i] + b[n-1];
            B = max(A, B);
            S= max(S, B);
        }
        S= max(S, b[0] + b[n-1]);
    }else{
        for(int i = 0; i<=k; i++){
            S+= a[i];
        }
    }
    cout<<S<<endl;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}