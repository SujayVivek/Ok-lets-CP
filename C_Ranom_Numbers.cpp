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
    string s; cin >> s;
    unordered_map<char, int> first, last;
    for(int i = 0; i < s.length(); i++){
        if(first.find(s[i]) == first.end()) first[s[i]] = i;
        last[s[i]] = i;
    }
    int mx = LLONG_MIN;
    for(auto it : first){
        string S = s;
        S[it.second] = 'E'; 
        mx = max(mx, check(S));
    }
    for(auto it : last){
        string S = s;
        S[it.second] = 'A'; 
        mx = max(mx, check(S));
    }
    cout << mx << endl;
}

int32_t main() {
    int tt_;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}
