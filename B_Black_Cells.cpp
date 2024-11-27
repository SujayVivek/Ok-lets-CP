#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ff first
#define ss second
typedef vector<vector<long long>> vvi;
typedef vector<long long> vi;
#define int long long
#define endl "\n"

bool prior(pair<int,int>p1, pair<int,int> p2){
    return max(p1.first, p1.second)>max(p2.first, p2.second);
}
void Solve() {
    int n; cin>>n;
    vi a(n,0);
    for(auto &x: a)cin >>x;
    vector<pair<int,int>>vp;
    if(n==1){
        cout<<1<<endl;return;
    }
    int k = 0;
    if(n%2==0){
        for(int i = 1; i<n; i+=2){
            k = max(k, a[i]-a[i-1]);
        }
        cout<<k<<endl;return;
    }
    for(int i = 1; i<=n-2; i++){
        vp.push_back(make_pair(a[i]-a[i-1], a[i+1]-a[i]));
    }
    vp.push_back({a[1]-a[0], 0});
    vp.push_back({0, a[n-1]-a[n-2]});
    sort(vp.begin(), vp.end(), prior);
    
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}