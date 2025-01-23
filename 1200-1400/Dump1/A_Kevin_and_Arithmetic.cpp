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
    vi a(n,0);
    int cnt1 = 0, cnt2 = 0;
    for(int i = 0; i<n; i++){
        cin>>a[i];
        if(a[i]%2==0) cnt1++;
        else cnt2++;
    }
    if(n==1){
        cout<<((cnt1)?1:0)<<endl;return;
    }
    if(cnt1>=1) cnt2++;
    cout<< cnt2 + ((cnt1)?0:-1) <<endl;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}