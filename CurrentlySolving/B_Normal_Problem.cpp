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
    for(int i = 0 ; i<s.length(); i++){
        if(s[i]=='p'){s[i] = 'q';}
        else if(s[i]=='q'){s[i] = 'p';};
    }
    reverse(s.begin(), s.end());
    cout<<s<<endl;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}