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
    for(auto &x: a)cin>>x;
    if(n==1){cout<<0<<endl;return;}
    sort(a.begin(), a.end());
    vi ans;
    while(a[0]!=a[n-1]){
        if(a[0]%2==1 && a[n-1]%2==0){ans.push_back(1); a[0]+=1;}
        else ans.push_back(0);
        a[0]/=2, a[n-1]/=2;
    }
    if(ans.size()>n){cout<<ans.size()<<endl;}
    else{
        cout<<ans.size()<<endl;
        for(auto x: ans)cout<<x<<" ";
        cout<<endl;
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