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
    int A, B, C, D; 
    cin>>A>>B>>C>>D;
    set<int> st;
    st.insert(A), st.insert(B), st.insert(C), st.insert(D);
    if(st.size()==2)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}

int32_t main() {
    int tt_ = 1;
    // cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}