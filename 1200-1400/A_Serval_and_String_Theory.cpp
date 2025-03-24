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
    int n, k;  cin>>n>>k;
    string s; cin>>s;
    string r = s; reverse(r.begin(), r.end());
    if(k==0){
        bool ok = true;
        for(int i = 0; i<n; i++){
            if(s[i]>r[i]) ok = false;
            else if(r[i]>s[i]) break;
        }
        if(s==r) ok = false;
        if(ok){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }else{
        set<char> st;
        for(int i = 0; i<n; i++) st.insert(s[i]);
        if(st.size()==1){
            cout<<"NO"<<endl;
        }else{
            cout<<"YES"<<endl;
        }
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