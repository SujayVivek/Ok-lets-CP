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
    int n,x; cin>>n>>x; vi a(n,0);
    for(int i = 0; i<n; i++){
        cin>>a[i];
    } int ans = 0, last = 0;  
    sort(a.begin(), a.end(), greater<int>());
    for(int i = 0; i<n; i++){
        if(a[i]*(i+1-last)>=x){
            ans++, last = i+1;
        }
    }cout<<ans<<endl;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}