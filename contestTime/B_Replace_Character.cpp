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
    string s; cin>>s;
    map<char, int>mpp;
    for(int i = 0; i<n; i++){
        mpp[s[i]]++;
    }
    int mn = n+1, mx = 0;
    char mnI, mxI;
    for(auto it: mpp){
       if(mx<=it.second){
        mx = it.second;
        mxI = it.first;
       }
    }
    for(auto it: mpp){
        if(mn>=it.second && mxI!=it.first){
            mn = it.second;
            mnI = it.first;
        }
    }
    for(int i = 0; i<n; i++){
        if(s[i]==mnI){
            s[i] = mxI;
            break;
        }
    }
    cout<<s<<endl;return;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}