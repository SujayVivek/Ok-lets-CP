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
    map<char,int> mpp;
    for(int i = 0; i<n; i++){
        mpp[s[i]] = i+1;
    }
    if(mpp['p']==0 || mpp['s']==0){
        cout<<"YES"<<endl;return;
    }
    bool P = false, S = false;
    for(int i = 0; i<n; i++){
        // cout<<"HI"<<endl;
        if(s[i]=='s'){
            S = true;
            if(P){
                cout<<"NO"<<endl;return;
            }
        }
        if(s[i]=='p'){
             P = true;
        }
    }
    int i = 0, j = n-1;
    if(s[0]=='.' && s[n-1]=='.'){
        cout<<"NO"<<endl;return;
    }
    for(int i = n-1; i>=0; i--){
        if(s[i]=='p')mpp['p'] = i+1;
    }
    if(mpp['s']==1 || mpp['p']==n){
        cout<<"YES"<<endl;return;
    }
    cout<<"NO"<<endl;return;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}