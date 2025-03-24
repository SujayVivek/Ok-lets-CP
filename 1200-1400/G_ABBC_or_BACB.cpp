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
    string s; cin>>s; int n = s.length(); s+='$';
    vector<pair<char, int>> vp; int c  = 1;
    vector<int> places;
    for(int i = 0; i<n; i++){
        if(s[i] == s[i+1]){
            c++;
        }else{
            vp.push_back({s[i], c}); c = 1;
        }
    } int cnt = 0;
    int mn = 1e18, S = 0; bool ok = false;
    for(auto it: vp){
        if(it.first == 'A'){ S+= it.second, mn = min(mn, it.second);}
        else if(it.second>=2) ok = true;
    }
    if(ok || !(vp[0].first == 'A' && vp[vp.size()-1].first == 'A') ){
        cout<<S<<endl;
    }else{
        if(mn == 1e18) mn = 0;
        cout<<S-mn<<endl;
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