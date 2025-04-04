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
    vi a(n,0), hash(n,0);
    for(int i = 0; i<n; i++){
        cin>>a[i];
        if(a[i]==i+1) hash[i] = 1;
    }
    int cnt = 0;
    bool yes = false;
    bool ok1 = false, ok2 = false;
    for(int i = 0; i<n; i++){
        if(hash[i]==0){
            ok1 = true;
        }
        if(hash[i]==1 && ok1){
            ok2 = true;
        }
        if(hash[i]==0 && ok1 && ok2){
            cnt++;
            ok2 = false;
        }
        if(hash[i]==0){
            yes = true;
        }
    }
    cout<<min(2ll,cnt+(yes?1:0))<<endl;  
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}