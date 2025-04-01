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
    vi a(n,0), b(m,0), d; int S = 0;
    for(auto &x: a)cin>>x;
    for(auto &x: b)cin>>x;
    for(int i = 0; i<n; i++)d.push_back(a[i]);
    for(int i = 0; i<m; i++)d.push_back(b[i]);
    sort(d.begin(), d.end(), greater<int>());
    bool ok = false;
    for(int i = 0; i<n; i++){
        S+= d[i];
        if(d[i]==b[m-1]) ok = true;
    }
    if(!ok) S = S-d[n-1]+b[m-1];
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