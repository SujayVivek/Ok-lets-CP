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
    vvi a(n, vi(2, 0));
    for(int i = 0; i<n; i++){
        int x; cin>>x;
        a[i] = {x, i};
    }
    sort(a.begin(), a.end()); 
    vector<pair<int,int>> vpp; 
    for(int i = 1; i<n; i++){
        int Change = a[i-1][0] - (a[i][0]%a[i-1][0]);
        a[i][0]+= Change;
        vpp.push_back({a[i][1], Change});
    }
    cout<<vpp.size()<<endl;
    for(auto it: vpp){
        cout<<it.first+1<<" "<<it.second<<endl;
    }
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}