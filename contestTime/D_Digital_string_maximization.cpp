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
    vi v(s.length(),0);
    for(int i = 0; i<s.length(); i++){
        v[i] = s[i] - '0';
    }
    for(int j = 1; j<s.length(); j++){
        int i = j;
        while(i>=1 && v[i]>v[i-1]+1 && v[i]>0){
            int temp = v[i];
            v[i] = v[i-1];
            v[i-1] = temp-1;
            if(i>1)i--;
            else break;
        }
    }
    string ans = "";
    for(auto x: v) ans+= to_string(x);
    cout<<ans<<endl;return;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}