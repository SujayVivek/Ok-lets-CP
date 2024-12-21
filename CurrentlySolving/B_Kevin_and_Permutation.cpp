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
    vector<int> v(n+1, 0);
    int l = 0;
    for(int i = k; i<=n; i+=k){
        l++;
        v[i] = l;
    }
    for(int i = 1; i<=n; i++){
        if(v[i]==0){
            l++;
            v[i] = l;
        }
    }
    for(int i = 1; i<=n; i++){
        cout<<v[i]<<" ";
    }cout<<endl;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}