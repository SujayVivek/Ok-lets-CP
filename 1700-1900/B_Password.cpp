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
    string s; cin>>s;  int n = s.length();
    vi res(n+1,0); 
    int i = 0, j = -1; res[0] = -1;
    while(i<n){
        while(j!=-1 && s[i]!=s[j]) j = res[j];
        i++, j++; res[i] = j; 
    }
    // for(auto it: res)cout<<it<<" ";
    int x =0;
    for(int i = 1; i<n; i++){
        if(res[i]==res[n] || res[i] == res[res[n]]) x = max(x, res[i]);
    }
    if(x){
        cout<<s.substr(0,x)<<endl; return;
    }
    cout<<"Just a legend"<<endl;
}

int32_t main() {
    int tt_ = 1;
    // cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}