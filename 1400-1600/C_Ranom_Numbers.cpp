#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ff first
#define ss second
typedef vector<vector<long long>> vvi;
typedef vector<long long> vi;
#define int long long
#define endl "\n"

int check(string s){
    int mx = 0, S = 0; 
    for(int i = s.length()-1; i >= 0; i--){
        int T;
        if(s[i] == 'A') T = 1;
        else if(s[i] == 'B') T = 10;
        else if(s[i] == 'C') T = 100;
        else if(s[i] == 'D') T = 1000;
        else T = 10000;
        if(T >= mx) mx = T;
        else T = -T;
        S += T;
    }
    return S;
}

void Solve() {
    string s; cin >> s; int ans = LLONG_MIN;
    set<char> st = {'A', 'B', 'C', 'D', 'E'};
    for(auto ch1: st)
        for(auto ch2: st){
            int first = s.find(ch1); string s1 = s, s2 = s; if(first!=string::npos){ s1[first] = ch2; ans = max(ans, check(s1));}
            int last = s.rfind(ch1); if(last != string::npos) {s2[last] = ch2; ans = max(ans, check(s2));}
        }cout<<ans<<endl;
}

int32_t main() {
    int tt_;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}
