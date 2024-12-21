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
    set<int> st;
    for(int i = 0; i<n; i++) {cin>>a[i];st.insert(i+1);}
    map<int,int> mpp;
    for(int i = 0; i<n; i++){
        st.erase(a[i]);
        if(mpp[a[i]]){
            a[i] = 0;
            continue;
        }
        mpp[a[i]]++;
    }
    // cout<<st.size()<<" HI"<<endl;
    for(int i = 0; i<n; i++){
        if(a[i]==0){
            a[i] = *st.begin();
            st.erase(a[i]);
        }
    }
    for(int i = 0; i<n; i++) cout<<a[i]<<" ";
    cout<<endl;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}