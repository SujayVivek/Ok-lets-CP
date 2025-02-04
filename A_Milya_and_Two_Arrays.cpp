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
    vi a(n,0), b(n,0);
    set<int> st, st1, st2;
    for(int i = 0; i<n; i++){
        cin>>a[i];
        st1.insert(a[i]);
    }
    for(int i = 0; i<n; i++){
        cin>>b[i];
        st.insert(a[i]+b[i]);
        st2.insert(b[i]);
    }
    if(st.size()>=3){
        cout<<"YES"<<endl;return;
    }
    if(st1.size()==1 || st2.size()==1){
        cout<<"NO"<<endl;return;
    }
    cout<<"YES"<<endl;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}