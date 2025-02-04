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
    vvi grid(n, vi(n,0));
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            cin>>grid[i][j];
        }
    }
    vi suff(n,0);
    for(int i = 0; i<n; i++){
        for(int j = n-1; j>=0; j--){
            if(grid[i][j]!=1) break;
            suff[i]++;
        }
    }
    sort(suff.begin(), suff.end());
    int Ans = 0;
    for(int i = 0; i<n; i++){
        if(suff[i]>Ans) Ans++;
    }
    cout<<min(n-1, Ans) + 1<<endl;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}