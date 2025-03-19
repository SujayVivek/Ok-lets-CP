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
    int c = 0, d = 0;
    for(int i = 0; i<s.length(); i++){
        if(s[i]=='-') c++;
        else d++;
    }
    if(c<2 || d<1){
        cout<<0<<endl;return;
    }
    int S = 0;
    for(int i = 1; i<=d; i++){
        S+= c/2*(c-c/2);
    }
    cout<<S<<endl;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}