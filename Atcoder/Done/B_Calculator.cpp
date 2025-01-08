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
    map<char, int> mpp;
    int ans = 0;int c = 0;
    for(int i = 0; i<s.length(); i++){
        if(s[i]=='0'){
            c++;
        }else{
            ans+= (c+1)/2;
            c= 0;
            ans++;
        }
    }
    ans+= (c+1)/2;
    cout<<ans<<endl;
}

int32_t main() {
    int tt_ = 1;
    // cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}