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
    vvi v(n,vi(m,0));
    vector<pair<int,int>>sums;
    for(int i = 0; i<n; i++){
        int S = 0;
        for(int j = 0; j<m; j++){
            cin>>v[i][j];
            S+= v[i][j];
        }
        sums.push_back({S,i});
    }
    sort(sums.begin(), sums.end(), greater<pair<int,int>>());
    vi Ans(n*m+2,0);
    int k = 1;
    int Sum = 0;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            int T = sums[i].second;
            Ans[k] = v[T][j]+Ans[k-1];
            Sum+= Ans[k];
            // cout<<Ans[k]<<" ";
            k++;
        }
    }
    cout<<Sum<<endl;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}