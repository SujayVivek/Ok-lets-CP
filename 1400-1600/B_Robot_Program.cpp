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
    int n, x, k; cin>>n>>x>>k;
    string s; cin>>s;
    int delta = 0, ans = 0;  
    bool ok = false;
    int i = 0;
    for(i = 0; i<s.length() && i<k; i++){
        if(s[i]=='L')delta--;
        else delta++;
        if(x>0 && x+delta<=0){ ok = true; k-=(i+1); break;}
        else if(x<0 && x+delta>=0){ ok = true; k-=(i+1); break;}
    }
    if(ok)ans++;
    else{cout<<0<<endl;return;}
    ok = false;
    int Time = 0, pos = 0;
    for(int i = 0; i<s.length() && i<k; i++){
        Time++;
        if(s[i]=='L') pos--;
        else pos++;
        if(pos==0) {ok = true;break;}
    }
    if(!ok){
        cout<<ans<<endl;
    }else{
        cout<<k/Time + ans<<endl;
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