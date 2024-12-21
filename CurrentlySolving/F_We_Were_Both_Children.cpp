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
    priority_queue<pair<int,int>>st;
    map<int,int>mpp;
    for(int i = 0; i<n; i++){
        cin>>a[i];
        st.push({a[i], a[i]});
        if(a[i]<=n)mpp[a[i]]++;
    }
    if(n==1){cout<<0<<endl; return;}
    while(!st.empty()){
        pair<int,int> Top = st.top(); st.pop();
        if(Top.first + Top.second<=n){
            mpp[Top.first + Top.second]++;
            st.push({Top.first+Top.second, Top.second});
        }
        if(mpp[Top.first + Top.second]==n){
            cout<<n<<endl;return;
        }
    }
    int mx = 0;
    for(auto it: mpp){
        mx = max(mx, it.second);
    }
    cout<<mx<<endl;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}