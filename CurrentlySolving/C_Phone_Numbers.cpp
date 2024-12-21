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
    int n, k; cin>>n>>k;
    string s; cin>>s;
    set<char> st;
    for(int i = 0; i<n; i++){
        st.insert(s[i]);
    }
    if(k>n){
        for(int i = n; i<k; i++){
            s+=*st.begin();
        }
    }else{
        for(int i = k-1; i>=0; i--){
            if(st.upper_bound(s[i])!=st.end()){
                s[i] = *st.upper_bound(s[i]);
                break;
            }else{
                s[i] = *st.begin();
            }
        }
        s = s.substr(0, k);
    }
    cout<<s<<endl;
}

int32_t main() {
    int tt_ = 1;
    // cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}