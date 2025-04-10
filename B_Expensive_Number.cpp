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
    int t = 0, p = 0;  bool ok = true;
    for(int i = s.length() - 1; i>=0; i--){
        if(s[i]=='0') {
            if(ok)t++;
            p++;
        }else{
            ok = false;
        }
    }
    cout<<s.length()-p-1+t<<endl;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}