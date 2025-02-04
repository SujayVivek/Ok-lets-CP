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
    string s; cin>>s;
    for(int i = 0; i<s.length(); i++){
        if(s[i]=='E') cout<<"W";
        else if(s[i]=='W')cout<<"E";
        else if(s[i]=='N')cout<<"S";
        else cout<<"N";
    }cout<<endl;
}

int32_t main() {
    int tt_ = 1;
    // cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}