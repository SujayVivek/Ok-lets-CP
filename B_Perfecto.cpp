#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ff first
#define ss second
typedef vector<vector<long long>> vvi;
typedef vector<long long> vi;
#define int long long
#define endl "\n"

set<int> sqrs;
bool sqr(int n){
    int x = sqrt(n);
    return x*x==n;
}

void Solve() {
    int n;
    cin>>n;
    int T = n*(n+1)/2;
    if(sqr(T)){cout<<-1<<endl;return;}
    vi ans(n);
    iota(ans.begin(), ans.end(), 1);
    for(int i = 1; i<n; i++){
        if(sqr(i*(i+1)/2))swap(ans[i], ans[i-1]);
    }
    for(auto &x: ans)cout<<x<<" ";
    cout<<endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tt_ = 1;
    cin >> tt_;

    for (int i = 1; i <= 1005; i++) {
        sqrs.insert(i * i);
    }

    while (tt_--) {
        Solve();
    }
    return 0;
}
