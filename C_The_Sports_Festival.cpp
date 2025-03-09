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
    vector<pair<int,int>>vpp;
    for(int i = 0; i<n; i++){ int x; cin>>x;
        vpp.push_back({x, i});
    }int Ans = 1e18;
    if(n==1){cout<<0<<endl;return;}
    sort(vpp.begin(), vpp.end());
    for(int i = 0; i<n; i++){
        int mn = vpp[i].first, mx = vpp[i].first;
        int j = i, k = i; int cnt = 1; int Sum = 0;
        while(cnt<n){
            int T = 1e18, S = 1e18;
            if(j<n-1) T = vpp[j+1].first - mx;
            if(k>0) S = mn - vpp[k-1].first;
            if(T==1e18 && S==1e18) break;
            if(T<S){
                j++; mx = vpp[j].first; Sum+= (mx-mn);
            }else if(T>=S){
                k--; mn = vpp[k].first; Sum+= (mx-mn);
            }
            cnt++;
        }
        cout<<Sum<<" ho"<<endl;
        Ans = min(Ans, Sum);
    } cout<<Ans<<endl;
}

int32_t main() {
    int tt_ = 1;
    // cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}