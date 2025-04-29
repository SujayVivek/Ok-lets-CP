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
    string s; cin>>s; int cnt = 1;
    string p = s; reverse(p.begin(), p.end());
    for(int i = 0; i<p.length(); i++){
        if(s[i]=='<')cnt++;
    }
    vi ans; ans.push_back(cnt);

    int mn = cnt, mx = cnt;
    for(int i = 0; i<s.length(); i++){
        if(s[i]=='<'){ans.push_back(mn-1), mn = mn-1;}
        else {ans.push_back(mx+1), mx = mx+1;}
    }
    for(auto &x: ans)cout<<x<<" ";
    cout<<endl;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}