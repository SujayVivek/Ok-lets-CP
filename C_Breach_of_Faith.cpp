#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ff first
#define ss second
typedef vector<vector<long long>> vvi;
typedef vector<long long> vi;
#define int long long
#define endl "\n"

bool bs(vi &a, int XX){
    return 1;
}
void Solve() {
    int n; cin>>n; vi ans;
    vi a(2*n); int S=0, highSum = 0;
    for(int i=0; i<2*n; i++){
        cin>>a[i];
        S+=a[i];
    }
    sort(a.begin(), a.end()); vi v, p;
    for(int i=n-1; i<2*n; i++){
        highSum+=a[i];
        v.push_back(a[i]);
    }
    for(int i = 0; i<n-1; i++) p.push_back(a[i]);
    p.push_back(2*highSum-S); ans.push_back(v[n]);
    for(int i=0; i<n; i++){
        ans.push_back(p[i]), ans.push_back(v[i]);
    }bool srch= bs(a,2*highSum-a[0]);  if(srch) highSum+=1;
    reverse(ans.begin(), ans.end());
    for(int i=0; i<2*n+1; i++){
        cout<<ans[i]<<" ";
    }cout<<endl;return;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}