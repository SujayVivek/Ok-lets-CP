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
    vvi SparseTable(n+1, vi((int)log2(n) + 1));
    for(int i = 0; i<n; i++){
        cin>>SparseTable[i][0];
    }
    for(int j = 1; j<= log2(n); j++){
        for(int i = 0; i + (1<<j)<=n; i++){
            SparseTable[i][j] = min(SparseTable[i][j-1] , SparseTable[i+ (1<<(j-1))][j-1]);
        }
    }
    while(q--){
        int l, r; cin>>l>>r; l--, r--;
        int len = r-l+1; int j = log2(len);
        cout<< min(SparseTable[l][j], SparseTable[r-(1<<j)+1][j])<<endl;
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