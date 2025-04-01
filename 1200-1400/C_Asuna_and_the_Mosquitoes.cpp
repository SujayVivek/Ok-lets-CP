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
    vi a(n,0);int mx = 0; int cnt = 0; int S = 0;
    for(int i = 0; i<n; i++){
        cin>>a[i];
        mx = max(mx, a[i]);S+= a[i];
        if(a[i]%2==1) cnt++;
    }
    if(cnt == 0 || cnt == n){
        cout<<mx<<endl;
    }else{
        cout<< S-(cnt- 1)<<endl;
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