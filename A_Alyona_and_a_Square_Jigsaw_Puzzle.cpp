#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ff first
#define ss second
typedef vector<vector<long long>> vvi;
typedef vector<long long> vi;
#define int long long
#define endl "\n"

set<int> st;
void Solve() {
    int n; cin>>n;
    // vi a(n,0);
    int s = 0;
    int cnt = 0;
    for(int i = 0; i<n; i++){
        int x; cin>>x;
        s+=x;
        // cout<<s<<" hi "<<x<<endl;
        if(st.find(s)!=st.end()){
            cnt++;
        }
    }
    cout<<cnt<<endl;return;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    int s = 1;
    st.insert(1);
    for(int i = 2; i<=100; i+=2){
        // cout<<s<<" ";
        s+= i*4;
        st.insert(s);
    }
    while (tt_--) {
        Solve();
    }
    return 0;
}