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
    char c1, c2; cin>>c1>>c2;
    string s; cin>>s;
    for(int i = 0; i<s.length(); i++){
        if(s[i]!=c1) s[i] = c2;
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