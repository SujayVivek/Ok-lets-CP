#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ff first
#define ss second
typedef vector<vector<long long>> vvi;
typedef vector<long long> vi;
#define int long long
#define endl "\n"

int Toggle = -1;
int calc(string s){
    if(s.length() == 1){Toggle = s[0]-'0'; return Toggle;}
    vi pref(s.length()); pref[0] = s[0]-'0';
    for(int i = 1; i<s.length(); i++){
        pref[i] = pref[i-1] + (s[0]-'0');
    }
    for(int i = 0; i<s.length(); i+=3){
        
    }
}
void Solve() {
    int n; cin>>n;
    string s; cin>>s;

}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}