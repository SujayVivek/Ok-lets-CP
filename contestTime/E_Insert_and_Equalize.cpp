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
    vi v(n,0);int mx = 1e9*-1;
    for(int i = 0; i<n; i++){
        cin>>v[i];
        mx =max(mx, v[i]);
    }
    if(n==1){
        cout<<1<<endl;return;
    }
    int gcd = 0;
    set<int>st;
    for(int i = 0; i<n; i++){
        v[i] = v[i]-mx;
        st.insert(v[i]);
        gcd = __gcd(gcd, v[i]);
    }
    int ans = 0;
    for(int i = 0; i<n; i++){
        ans+= abs(v[i]/gcd);
    }
    int i = 0;
    while(st.find(i)!=st.end()){
        ans++;
        i-=abs(gcd);
    }
    cout<<ans<<endl;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}