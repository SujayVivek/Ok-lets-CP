#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define int long long

void Solve() {
    int n; cin>>n;
    string s; cin>>s;
    bool ok1 = false;
    int cnt = 0;
    for(int i = 0; i<s.length(); i++){
        if(s[i]=='1'){
            if(!ok1) cnt++;
            ok1 = true;
        }
        if(s[i]=='0' && ok1){
            cnt++;
            ok1 = false;
        }
    }
    cout<<cnt<<"\n";
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}