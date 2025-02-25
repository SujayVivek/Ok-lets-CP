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
    bool ok = false;
    for(int i = 0; i<s.length()-1; i++){
        if(s[i]==s[i+1]) ok = true;
    }
    if(ok){
        cout<<1<<endl;
    }else{
        cout<<s.length()<<endl;
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